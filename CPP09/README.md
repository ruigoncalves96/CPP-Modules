*This project has been created as part of the 42 curriculum by randrade.*

# C++ Module 09

*Rank 05 — The STL.*

## Description

The final module, and the only one where the exercises are real programs rather
than language demonstrations. Each one names a *different* container you must use, so the
difficulty is not "use the STL" but "justify this container for this job".

They also stop being toys: a data-file-backed lookup with date handling, an expression
evaluator, and a sorting algorithm benchmarked against itself on two containers.

## Exercises

| Directory | Exercise | Binary | What it covers |
|-----------|----------|--------|----------------|
| `ex00` | Bitcoin Exchange | `btc` | Read a CSV price database and an input file of dates and amounts, and for each line report the value using the price at that date — or the nearest earlier one. Mostly date parsing, validation, and `std::map::lower_bound`. |
| `ex01` | RPN | `RPN` | Evaluate a reverse-Polish expression given as a single argument, using a stack and rejecting malformed input. |
| `ex02` | PmergeMe | `PmergeMe` | Implement the **Ford–Johnson merge-insertion sort** on two different containers and time both, to show the container choice affecting real performance. |

## Instructions

Each exercise builds on its own:

```sh
cd ex00 && make && ./btc
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

- associative containers: `std::map` and ordered lookup with `lower_bound`
- sequence containers compared on a real workload
- choosing a container from its complexity guarantees rather than by habit
- the Ford–Johnson (merge-insertion) algorithm
- parsing and validating untrusted input files
- timing code with `clock()` / `gettimeofday`

## Notes

`ex00` reads its price database from a file named `data.csv` in the working
directory (`DATA_FILE_PATH` in `BitcoinExchange.hpp`). **That file is not in this
repository** — the program will report that it cannot open the database until it is
supplied.

## Resources

- [cppreference.com](https://en.cppreference.com/w/)
- [`CPP09.pdf`](../../../../Subjects/Rank_5/CPP09.pdf) — the module subject
- [All C++ modules](..) — the overview
