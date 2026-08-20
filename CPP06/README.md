*This project has been created as part of the 42 curriculum by randrade.*

# C++ Module 06

*Rank 05 — C++ casts.*

## Description

C has one cast; C++ has four, and this module is about knowing which is which.

`static_cast` for related types checked at compile time, `dynamic_cast` for downcasts
checked at run time, `reinterpret_cast` for reinterpreting bits, and `const_cast` for
removing constness. Each exercise forces one of them by making the alternatives wrong.

## Exercises

| Directory | Exercise | Binary | What it covers |
|-----------|----------|--------|----------------|
| `ex00` | Conversion of scalar types | `Convert` | Take a string, detect which of `char`, `int`, `float` or `double` it represents, and print it as all four — handling the pseudo-literals (`nan`, `+inf`, `-inf`), non-displayable characters, and values that do not fit. |
| `ex01` | Serialization | `Serialize` | Round-trip a pointer through an integer type with `reinterpret_cast`, and confirm the recovered pointer is the original. |
| `ex02` | Identify real type | `notTypeinfo` | Given a `Base *` to a randomly created `A`, `B` or `C`, identify the real type — once via pointer `dynamic_cast`, once via reference `dynamic_cast` where failure throws instead of returning null. `typeinfo` is forbidden. |

## Instructions

Each exercise builds on its own:

```sh
cd ex00 && make && ./Convert
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

- `static_cast`, `dynamic_cast`, `reinterpret_cast`, `const_cast` — and when each is correct
- `dynamic_cast` on pointers (returns null) versus references (throws `std::bad_cast`)
- why `dynamic_cast` needs a polymorphic type, i.e. at least one virtual function
- parsing and classifying scalar literals by hand
- `std::numeric_limits` for range checks
- the difference between converting a value and reinterpreting its bits

## Notes

`ex00` is the substantial one: the scalar converter is split across `ScalarConverter`, `TypeFlag` and `TypeUtils` so that detection, classification and printing stay separable.

## Resources

- [cppreference.com](https://en.cppreference.com/w/)
- [`CPP06.pdf`](../../../../Subjects/Rank_5/CPP06.pdf) — the module subject
- [All C++ modules](..) — the overview
