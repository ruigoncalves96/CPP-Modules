*This project has been created as part of the 42 curriculum by randrade.*

# C++ Module 07

*Rank 05 — Templates.*

## Description

Genericity without the preprocessor. A C programmer solves "the same function for
several types" with a macro or by copy-pasting; C++ solves it with templates, which are
type-checked and expanded per instantiation.

Three exercises, each a step up: function templates, a function template taking a
function, and finally a class template that manages its own memory.

## Exercises

| Directory | Exercise | Binary | What it covers |
|-----------|----------|--------|----------------|
| `ex00` | Start with a few functions | `template` | `swap`, `min` and `max` as function templates, working for any type with the operators they need. |
| `ex01` | Iter | `template` | A template that applies a function to every element of an array — the ancestor of `std::for_each`, written before the STL is allowed. |
| `ex02` | Array | `array_template` | A class template wrapping a dynamic array: allocates with `new[]`, deep-copies, reports its `size()`, and throws `std::exception` on an out-of-range index. |

## Instructions

Each exercise builds on its own:

```sh
cd ex00 && make && ./template
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

- function templates and implicit template argument deduction
- class templates
- why template definitions must live in the header
- passing a function as a template parameter
- the implicit requirements a template places on its type (it must be copyable, comparable, …)
- bounds checking by exception rather than undefined behaviour

## Notes

`Array` in `ex02` is the module's payoff — it is a container written by hand, immediately before module 08 introduces the ones the standard library provides.

## Resources

- [cppreference.com](https://en.cppreference.com/w/)
- [`CPP07.pdf`](../../../../Subjects/Rank_5/CPP07.pdf) — the module subject
- [All C++ modules](..) — the overview
