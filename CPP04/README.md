*This project has been created as part of the 42 curriculum by randrade.*

# C++ Module 04

*Rank 04 — Subtype polymorphism, abstract classes and interfaces.*

## Description

Inheritance becomes useful once a base pointer can dispatch to the right derived
implementation — and this module makes the mechanism unmissable by having you build the
broken version first.

`Animal` and `WrongAnimal` are the same class but for one keyword: `virtual`. Calling
`makeSound()` through a base pointer works for one and silently calls the base version for
the other. From there the module adds deep copying, then abstract classes, then pure
interfaces.

## Exercises

| Directory | Exercise | Binary | What it covers |
|-----------|----------|--------|----------------|
| `ex00` | Polymorphism | `Animals` | `Animal`/`Dog`/`Cat` alongside `WrongAnimal`/`WrongCat` — the same hierarchy with and without `virtual`, so the difference is visible in the output. |
| `ex01` | I don't want to set the world on fire | `BrainAnimals` | Each animal owns a `Brain` allocated with `new`, which forces a **deep copy**: the compiler's shallow copy would leave two animals sharing one brain and double-freeing it. |
| `ex02` | Abstract class | `BrainAnimals` | `Animal` becomes `AAnimal` with a pure virtual method, so the base can no longer be instantiated — only subclassed. |
| `ex03` | Interface & recap | `AMateria` | `ICharacter` and `IMateriaSource` are pure interfaces; `AMateria` is abstract. A character carries an inventory of clonable materias, which pulls together polymorphism, deep copy and prototype-style cloning. |

## Instructions

Each exercise builds on its own:

```sh
cd ex00 && make && ./Animals
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

- `virtual` functions and the vtable — why dispatch is decided at run time
- **virtual destructors**, without which deleting through a base pointer leaks the derived part
- deep versus shallow copy when a class owns heap memory
- pure virtual functions (`= 0`) and abstract classes
- interfaces: classes that are nothing but pure virtual methods
- the clone pattern, for copying an object whose exact type you do not know

## Notes

The `Wrong*` classes in `ex00` exist purely to be wrong. Running the exercise and comparing the two sets of output is the demonstration.

## Resources

- [cppreference.com](https://en.cppreference.com/w/)
- [`CPP04.pdf`](../../../../Subjects/Rank_4/CPP04.pdf) — the module subject
- [All C++ modules](..) — the overview
