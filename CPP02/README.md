*This project has been created as part of the 42 curriculum by randrade.*

# C++ Module 02

*Rank 04 — Ad-hoc polymorphism, operator overloading and the Orthodox Canonical Form.*

## Description

The module that defines what a well-behaved C++ class is. If a class holds a
resource, the compiler's generated copy constructor and assignment operator will do the
wrong thing — so from here on, every class must explicitly provide the four members of the
**Orthodox Canonical Form**: default constructor, copy constructor, copy assignment
operator, and destructor.

The vehicle is a fixed-point number class, built up across four exercises until it behaves
exactly like a built-in arithmetic type: comparable, assignable, printable, and usable
with `+`, `-`, `*`, `/`, `++` and `--`.

## Exercises

| Directory | Exercise | Binary | What it covers |
|-----------|----------|--------|----------------|
| `ex00` | My First Class in Orthodox Canonical Form | `fixed` | The bare canonical form, with a fixed-point value stored as an integer and a constant 8 fractional bits. |
| `ex01` | Towards a more useful fixed-point number class | `fixed` | Constructors from `int` and `float`, conversion back to both, and an overloaded `<<` so the class prints like a number. |
| `ex02` | Now we're talking | `fixed` | The full operator set — six comparisons, four arithmetic operators, pre/post increment and decrement, and static `min`/`max`. |
| `ex03` | BSP | `fixed` | Using the class for something real: a point-in-triangle test built on the sign of three cross products. |

## Instructions

Each exercise builds on its own:

```sh
cd ex00 && make && ./fixed
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

- the Orthodox Canonical Form and why the compiler's defaults are not enough
- operator overloading, and which operators should be members versus free functions
- overloading `operator<<` for stream output
- the difference between pre- and post-increment, and why post- returns a copy
- fixed-point arithmetic — representing fractions in an integer with a bit shift
- `static` member functions and constants

## Notes

`ex03` (BSP) is the one exercise in the module that is a real algorithm rather than class plumbing — it uses the fixed-point type to decide whether a point lies strictly inside a triangle.

## Resources

- [cppreference.com](https://en.cppreference.com/w/)
- [`CPP02.pdf`](../../../../Subjects/Rank_4/CPP02.pdf) — the module subject
- [All C++ modules](..) — the overview
