*This project has been created as part of the 42 curriculum by randrade.*

# C++ Module 08

*Rank 05 — Templated containers, iterators and algorithms.*

## Description

The STL, taken apart. The standard library is built on three interlocking ideas —
containers hold elements, iterators traverse them, and algorithms operate on iterator
ranges without knowing which container they came from — and each exercise here targets one
joint of that structure.

The last exercise is the interesting one: `std::stack` deliberately has no iterators, and
the task is to add them anyway.

## Exercises

| Directory | Exercise | Binary | What it covers |
|-----------|----------|--------|----------------|
| `ex00` | Easy find | `easyfind` | A template that finds a value in any container of `int`, using `std::find` — so the function works for `vector`, `list`, `deque` alike. |
| `ex01` | Span | `Span` | A class storing up to N integers, able to report the shortest and longest span between any two of them, and to be filled from an iterator range in one call. |
| `ex02` | Mutated abomination | `MutantStack` | Make `std::stack` iterable by subclassing it and exposing the underlying container's iterators — turning a deliberately non-iterable adapter into a traversable one. |

## Instructions

Each exercise builds on its own:

```sh
cd ex00 && make && ./easyfind
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

- container / iterator / algorithm as three separable concepts
- iterator categories, and what an algorithm requires of them
- `std::find`, and range-based algorithms in general
- sequence containers: `vector`, `list`, `deque`
- container adapters, and the protected `c` member that `std::stack` exposes to subclasses
- range constructors and range insertion

## Notes

`MutantStack` works because `std::stack` keeps its underlying container as a *protected* member — inheriting is the only legitimate way to reach it, which is exactly what the exercise is pointing at.

## Resources

- [cppreference.com](https://en.cppreference.com/w/)
- [`CPP08.pdf`](../../../../Subjects/Rank_5/CPP08.pdf) — the module subject
- [All C++ modules](..) — the overview
