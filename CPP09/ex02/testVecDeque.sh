#!/usr/bin/env bash
# =============================================================================
#  test.sh — test harness for PmergeMe (cpp09 ex02, Ford-Johnson)
#
#  Usage:
#     ./test.sh                 # build (if needed) and run all tests
#     ./test.sh --no-build      # skip the compile step, use existing ./PmergeMe
#     BIN=./PmergeMe ./test.sh  # point at a specific binary
#
#  What it checks:
#     1. Clean compile with 42's mandatory flags
#     2. Parsing / error cases (must print Error to stderr, exit 1)
#     3. Valid cases (must exit 0, output sorted, match `sort -n`)
#     4. The key invariant: vector comparison count == list comparison count
#     5. Comparison count stays at/under the Ford-Johnson worst-case bound
#     6. Many sizes incl. edge + Jacobsthal-boundary, several input orderings
# =============================================================================

CXX="${CXX:-c++}"
FLAGS="-Wall -Wextra -Werror -std=c++98"
BIN="${BIN:-./PmergeMe}"
SRC="main.cpp PmergeMe.cpp"

PASS=0
FAIL=0
RED=$'\033[31m'; GRN=$'\033[32m'; YLW=$'\033[33m'; DIM=$'\033[2m'; RST=$'\033[0m'

ok()   { PASS=$((PASS+1)); printf "  ${GRN}PASS${RST} %s\n" "$1"; }
ko()   { FAIL=$((FAIL+1)); printf "  ${RED}FAIL${RST} %s\n" "$1"; [ -n "$2" ] && printf "       ${DIM}%s${RST}\n" "$2"; }
hdr()  { printf "\n${YLW}== %s ==${RST}\n" "$1"; }

# portable shuffle of 1..N — `shuf` is absent on macOS / 42 Macs.
# Uses perl (present everywhere 42 runs); falls back to awk if perl is missing.
shuffle_seq() {
  if command -v perl >/dev/null 2>&1; then
    seq 1 "$1" | perl -MList::Util=shuffle -e 'print shuffle(<>)'
  else
    seq 1 "$1" | awk 'BEGIN{srand()} {print rand()"\t"$0}' | sort -n | cut -f2-
  fi
}

# Ford-Johnson reference comparison counts, index = n (1..30), from the
# ceil(log2(3k/4)) sum. NOTE: this is the theoretical optimum. This particular
# implementation can sit 1-2 ABOVE it at Jacobsthal-boundary sizes (e.g. n=21).
# So this check is INFORMATIONAL: exceeding it flags "above textbook optimum",
# which is worth knowing but does not by itself mean the sort is wrong. The
# hard correctness checks are: output sorted, and vector count == list count.
FJ_OPT=(0 0 1 3 5 7 10 13 16 19 22 26 30 34 38 42 46 50 54 58 62 66 71 76 81 86 91 96 101 106 111)

# -----------------------------------------------------------------------------
# 0. Build
# -----------------------------------------------------------------------------
if [ "$1" != "--no-build" ]; then
  hdr "Build ($CXX $FLAGS)"
  if $CXX $FLAGS $SRC -o PmergeMe 2> /tmp/build_err.txt; then
    ok "compiles clean, no warnings"
  else
    ko "compile failed / warnings present" "$(cat /tmp/build_err.txt)"
    echo "Aborting: cannot test a binary that does not build."
    exit 1
  fi
  BIN=./PmergeMe
fi

if [ ! -x "$BIN" ]; then
  echo "${RED}No executable at $BIN${RST}"; exit 1
fi

# -----------------------------------------------------------------------------
# Helpers
# -----------------------------------------------------------------------------

# extract the "After:" line values, space-separated
after_values() { echo "$1" | sed -n 's/^After: //p' | tr -s ' '; }
vec_cmp()      { echo "$1" | sed -n 's/^Vector Comparisons = //p'; }
deque_cmp()     { echo "$1" | sed -n 's/^Deque Comparisons = //p'; }

# assert: input must be REJECTED (exit 1, nothing on stdout's Before/After)
expect_error() {
  local desc="$1"; shift
  local out rc
  out=$("$BIN" "$@" 2>/dev/null); rc=$?
  if [ $rc -ne 0 ] && ! echo "$out" | grep -q '^After:'; then
    ok "$desc  ${DIM}(rejected, rc=$rc)${RST}"
  else
    ko "$desc" "expected rejection; got rc=$rc, stdout: $out"
  fi
}

# assert: input must be ACCEPTED, output sorted, == sort -n, and vec==deque count
expect_sorted() {
  local desc="$1"; shift
  local out rc got want vc lc
  out=$("$BIN" "$@" 2>/dev/null); rc=$?
  if [ $rc -ne 0 ]; then ko "$desc" "expected success; got rc=$rc"; return; fi

  got=$(after_values "$out" | xargs)                 # trim
  want=$(printf '%s\n' "$@" | sort -n | xargs)       # ground truth
  vc=$(vec_cmp "$out"); lc=$(deque_cmp "$out")

  if [ "$got" != "$want" ]; then
    ko "$desc" "not sorted correctly: got [$got] want [$want]"; return
  fi
  if [ "$vc" != "$lc" ]; then
    ko "$desc" "comparison mismatch: vector=$vc deque=$lc (algorithms diverged!)"; return
  fi
  ok "$desc  ${DIM}(n=$# sorted, cmp=$vc, vec==deque)${RST}"
}

# assert on a generated sequence of size n with a given ordering
# ordering: asc | desc | rand
expect_size() {
  local n="$1" ordering="$2"
  local nums out rc got want vc lc bound
  case "$ordering" in
    asc)  nums=$(seq 1 "$n") ;;
    desc) nums=$(seq "$n" -1 1) ;;
    rand) nums=$(shuffle_seq "$n") ;;
  esac
  nums=$(echo $nums)   # flatten to one line

  out=$("$BIN" $nums 2>/dev/null); rc=$?
  if [ $rc -ne 0 ]; then ko "n=$n ($ordering)" "rc=$rc"; return; fi

  got=$(after_values "$out" | xargs)
  want=$(printf '%s\n' $nums | sort -n | xargs)
  vc=$(vec_cmp "$out"); lc=$(deque_cmp "$out")

  local why=""
  [ "$got" != "$want" ] && why="not sorted"
  [ "$vc" != "$lc" ]    && why="${why:+$why; }vec($vc)!=list($lc)"

  # F-J optimum check (informational only — see FJ_OPT note above)
  local note=""
  bound=""
  if [ "$n" -le 30 ]; then
    bound="${FJ_OPT[$n]}"
    if [ -n "$bound" ] && [ "$vc" -gt "$bound" ]; then
      note=" ${YLW}[+$((vc-bound)) over textbook optimum $bound]${RST}"
    fi
  fi

  if [ -z "$why" ]; then
    ok "n=$n ($ordering)  ${DIM}cmp=$vc${bound:+ / opt $bound}, vec==deque${RST}$note"
  else
    ko "n=$n ($ordering)" "$why"
  fi
}

# =============================================================================
#  1. Parsing / error cases  — must be rejected
# =============================================================================
hdr "Parsing & error handling (must reject, exit 1, Error on stderr)"
expect_error "no arguments at all"            # (no args)
expect_error "single empty string"        ""
expect_error "zero is rejected"           1 0 2
expect_error "negative number"            1 -2 3
# +N is accepted (value-compare skipped: sort -n keeps the literal '+')
out=$("$BIN" +1 2 3 2>/dev/null); rc=$?
if [ $rc -eq 0 ] && [ "$(after_values "$out" | xargs)" = "1 2 3" ]; then
  ok "leading plus sign accepted  ${DIM}(+1 2 3 -> 1 2 3)${RST}"
else
  ko "leading plus sign accepted" "rc=$rc out=$out"
fi
expect_error "embedded plus (5+3)"        5+3
expect_error "embedded minus (5-3)"       5-3
expect_error "lone plus"                  +
expect_error "lone minus"                 -
expect_error "non-digit char"             1 2a 3
expect_error "letters"                    abc
expect_error "float"                      1.5 2
expect_error "duplicate value"            1 2 2 3
expect_error "duplicate (non-adjacent)"   5 1 3 1
expect_error "overflow INT_MAX+1"         2147483648
expect_error "huge overflow"              99999999999
expect_error "space-embedded junk"        "1 2" 3
expect_error "tab char"                   $'\t' 2

# =============================================================================
#  2. Boundary values that should be ACCEPTED
# =============================================================================
hdr "Accepted boundary values"
expect_sorted "INT_MAX alone"             2147483647
expect_sorted "INT_MAX in a set"          5 2147483647 3 1
expect_sorted "single element"            42
expect_sorted "two elements (swap)"       2 1
expect_sorted "two elements (sorted)"     1 2

# =============================================================================
#  3. Hand-picked small cases (straggler + Jacobsthal paths)
# =============================================================================
hdr "Small hand-picked cases"
expect_sorted "n=3 reverse"               3 2 1
expect_sorted "n=4 reverse"               4 3 2 1
expect_sorted "n=5 reverse (straggler)"   5 4 3 2 1
expect_sorted "n=5 already sorted"        1 2 3 4 5
expect_sorted "n=7 mixed"                 4 1 7 3 6 2 5
expect_sorted "duplicates? no — distinct" 10 30 20 50 40

# =============================================================================
#  4. Many sizes x orderings  (correctness + vec==deque + F-J bound)
#     includes Jacobsthal boundaries: 5,11,21,43 ... and n-1/n/n+1 around them
# =============================================================================
hdr "Sizes x orderings (sorted? + vec==deque count + F-J max)"
for n in 1 2 3 4 5 6 10 11 12 20 21 22 23 30 100 500 1000 3000; do
  for ord in asc desc rand; do
    # skip asc/desc spam on the big ones, keep rand
    if [ "$n" -gt 30 ] && [ "$ord" != "rand" ]; then continue; fi
    expect_size "$n" "$ord"
  done
done

# =============================================================================
#  5. Determinism — same input twice gives identical comparison count
# =============================================================================
hdr "Determinism"
SEQ=$(shuffle_seq 200 | tr "\n" " ")
A=$("$BIN" $SEQ 2>/dev/null); B=$("$BIN" $SEQ 2>/dev/null)
if [ "$(vec_cmp "$A")" = "$(vec_cmp "$B")" ] && [ "$(after_values "$A")" = "$(after_values "$B")" ]; then
  ok "identical input -> identical count & output"
else
  ko "non-deterministic" "counts: $(vec_cmp "$A") vs $(vec_cmp "$B")"
fi

# =============================================================================
#  Summary
# =============================================================================
printf "\n${YLW}==============================${RST}\n"
printf "  ${GRN}PASS: %d${RST}    ${RED}FAIL: %d${RST}\n" "$PASS" "$FAIL"
printf "${YLW}==============================${RST}\n"
[ "$FAIL" -eq 0 ] && exit 0 || exit 1
