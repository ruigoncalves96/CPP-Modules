*This project has been created as part of the 42 curriculum by randrade.*

# C++ Module 00

*Rank 04 — Namespaces, classes, member functions, stdio streams, initialization lists, `static` and `const`.*

## Description

The first contact with C++. Nothing here is conceptually hard — the difficulty is
unlearning C. Output goes through `std::cout` rather than `printf`, strings are objects
rather than `char *`, and data and the functions that operate on it live together in a
class instead of being passed around as a struct pointer.

The three exercises escalate quickly: a one-line stream exercise, a full interactive
program with two classes, and then a file you are forbidden to modify — you are given the
header and the expected output log, and must write the implementation that reproduces it
exactly.

## Exercises

| Directory | Exercise | Binary | What it covers |
|-----------|----------|--------|----------------|
| `ex00` | Megaphone | `megaphone` | Shout the arguments back in upper case. Streams and `std::string` in place of `printf` and `char *`. |
| `ex01` | My Awesome PhoneBook | `yellowpages` | An interactive phonebook of 8 contacts, stored in a fixed array. Two classes, formatted column output with `std::setw`, and input that must survive anything typed at it. |
| `ex02` | The Job Of Your Dreams | `GlobalBankstersUnited` | Reconstruct `Account.cpp` from its header and a log of the expected output. Exercises `static` members and class-wide state, since the account totals are shared across all instances. |

## Instructions

Each exercise builds on its own:

```sh
cd ex00 && make && ./megaphone
```

| Target | Effect |
|--------|--------|
| `make` | Build the binary |
| `make clean` | Remove the `obj/` directory |
| `make fclean` | `clean` + remove the binary |
| `make re` | `fclean` then `all` |
| `make valgrind` | Build, then run under Valgrind with full leak checking |

Compiled with `c++ -Wall -Wextra -Werror -std=c++98`.

## Concepts

- `std::cout` / `std::cin` and stream manipulators (`std::setw`, `std::setfill`)
- `std::string` versus C strings
- classes, member functions, and access specifiers
- initialization lists, and why they differ from assignment in the constructor body
- `static` members — state that belongs to the class, not the instance
- `const` member functions

## Notes

`ex01` adds a `ft_getline` helper to make input handling robust against EOF and empty lines, which the naive `std::getline` loop is not.

## Resources

- [cppreference.com](https://en.cppreference.com/w/)
- [`CPP00.pdf`](../../../../Subjects/Rank_4/CPP00.pdf) — the module subject
- [All C++ modules](..) — the overview
