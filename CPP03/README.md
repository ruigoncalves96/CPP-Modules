*This project has been created as part of the 42 curriculum by randrade.*

# C++ Module 03

*Rank 04 — Inheritance.*

## Description

A single chain of classes, extended one exercise at a time, ending in the problem
that makes inheritance interesting.

`ClapTrap` gains a subclass, then a sibling, then a class that inherits from **both** —
at which point `DiamondTrap` contains two copies of `ClapTrap` unless the inheritance is
declared `virtual`. That is the diamond problem, and meeting it in four short exercises is
the entire point of the module.

## Exercises

| Directory | Exercise | Binary | What it covers |
|-----------|----------|--------|----------------|
| `ex00` | Aaaaand... OPEN! | `ClapTrap` | The base class: hit points, energy points, attack damage, and methods that respect them. |
| `ex01` | Serena, my love! | `ScavTrap` | A first subclass with different stats and its own special ability, showing constructor and destructor chaining order. |
| `ex02` | Repetitive work | `FragTrap` | A sibling subclass — two classes now inherit from the same base, independently. |
| `ex03` | Now it's weird! | `DiamondTrap` | Inherits from both `ScavTrap` and `FragTrap`. Requires **virtual inheritance** so only one `ClapTrap` sub-object exists, plus explicit disambiguation of the members both parents provide. |

## Instructions

Each exercise builds on its own:

```sh
cd ex00 && make && ./ClapTrap
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

- public inheritance and what a subclass inherits
- constructor and destructor call order along an inheritance chain
- calling a base constructor explicitly from a subclass initialization list
- the diamond problem, and `virtual` inheritance as its fix
- name ambiguity when two parents supply the same member, and scope resolution
- overriding versus hiding a base member

## Notes

Watching the constructor/destructor messages in `ex03` is the fastest way to see what virtual inheritance actually changes — without it, `ClapTrap`'s constructor runs twice.

## Resources

- [cppreference.com](https://en.cppreference.com/w/)
- [`CPP03.pdf`](../../../../Subjects/Rank_4/CPP03.pdf) — the module subject
- [All C++ modules](..) — the overview
