*This project has been created as part of the 42 curriculum by randrade.*

# C++ Modules

*Ranks 04–05 — ten modules, thirty-eight exercises, learning C++ from C.*

## Description

After four ranks of C, the C++ modules are where 42 switches languages. They are not a
project in the usual sense — there is no single program to deliver — but a graded course:
ten modules of small exercises, each one isolating a single language feature and refusing
to let you move on until it is understood.

The progression is deliberate. It starts with the mechanics that have no C equivalent
(classes, references, streams), moves through the four pillars of object orientation
(encapsulation, inheritance, polymorphism, abstraction), then to the parts of C++ that
replace what you used to do by hand — templates instead of copy-pasted functions,
containers instead of manual memory, exceptions instead of error codes — and finishes on
the STL.

Everything is written to **C++98**. That constraint is the point: no `auto`, no range-for,
no smart pointers, no `nullptr`, no move semantics, no `std::to_string`. Being denied the
modern conveniences forces the underlying mechanism into view — you write the copy
constructor and the assignment operator yourself, so you learn why the compiler generates
them and when its versions are wrong.

## The modules

| Module | Topic | Exercises |
|--------|-------|-----------|
| [CPP00](CPP00) | Namespaces, classes, member functions, stdio streams, initialization lists, `static`, `const` | 3 |
| [CPP01](CPP01) | Memory allocation, pointers to members, references, `switch` | 7 |
| [CPP02](CPP02) | Ad-hoc polymorphism, operator overloading, the Orthodox Canonical Form | 4 |
| [CPP03](CPP03) | Inheritance | 4 |
| [CPP04](CPP04) | Subtype polymorphism, abstract classes, interfaces | 4 |
| [CPP05](CPP05) | Repetition and exceptions | 4 |
| [CPP06](CPP06) | C++ casts | 3 |
| [CPP07](CPP07) | Templates | 3 |
| [CPP08](CPP08) | Templated containers, iterators, algorithms | 3 |
| [CPP09](CPP09) | The STL | 3 |

Modules 00–04 belong to Rank 04, modules 05–09 to Rank 05.

## Instructions

Every exercise is self-contained: its own directory, its own `Makefile`, its own binary.

```sh
cd CPP02/ex03 && make && ./fixed
```

All 38 Makefiles share the same shape and the same flags:

```make
CXX      = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
```

| Target | Effect |
|--------|--------|
| `make` | Build the exercise's binary |
| `make clean` | Remove the object directory |
| `make fclean` | `clean` + remove the binary |
| `make re` | `fclean` then `all` |
| `make valgrind` | Build, then run under Valgrind with full leak checking |

Objects are kept in a per-exercise `obj/` directory, and each module's README lists the
binary name for every exercise.

## Rules that apply throughout

The modules share a common rulebook, and most of it exists to stop you writing C in a
`.cpp` file:

- **C++98 only.** Anything from C++11 onwards is rejected, including the standard
  containers' newer members.
- **No C functions.** `printf`, `malloc`, `free` and friends are forbidden — use streams
  and `new`/`delete`.
- **No STL until module 08.** No containers, no algorithms before then, which is what
  forces you to implement the underlying ideas by hand first.
- **Every class in Orthodox Canonical Form** from module 02 onwards: default constructor,
  copy constructor, copy assignment operator, destructor.
- **Header guards on every header**, and no function implementations in headers — except
  templates, which have to be there.
- **`using namespace` is forbidden**, as are `friend` keywords.
- Memory allocated with `new` must be freed with `delete`, and leaks are graded.

## Concepts, module by module

Reading the list as a progression is more useful than reading it as ten separate topics:

1. **CPP00–01** — the syntax and memory model. Classes and member functions, references
   versus pointers, stack versus heap allocation, and what a destructor is for.
2. **CPP02** — the object's contract. Operator overloading and the Orthodox Canonical
   Form, i.e. what a class must provide to be copyable and assignable without corruption.
3. **CPP03–04** — the object hierarchy. Inheritance, then virtual functions and the
   difference between a base pointer that dispatches correctly and one that does not;
   deep copy versus shallow copy; abstract classes and pure interfaces.
4. **CPP05** — control flow that crosses call boundaries: exceptions, custom exception
   types, and why a destructor must not throw.
5. **CPP06** — the four C++ casts and when each is legitimate, including the run-time
   cost and safety of `dynamic_cast`.
6. **CPP07–08** — genericity. Function and class templates, then the container/iterator/
   algorithm triad that the STL is built from.
7. **CPP09** — using the STL in earnest, with each exercise constraining which container
   you may use so you have to think about the trade-off rather than reaching for
   `std::vector` every time.

## Resources

- [cppreference.com](https://en.cppreference.com/w/) — the reference that matters
- [C++98 standard (ISO/IEC 14882:1998)](https://www.iso.org/standard/25845.html)
- [Orthodox Canonical Form](https://en.wikipedia.org/wiki/Rule_of_three_(C%2B%2B_programming)) — the rule of three
- Subjects: [CPP00](../../../Subjects/Rank_4/CPP00.pdf) · [CPP01](../../../Subjects/Rank_4/CPP01.pdf) · [CPP02](../../../Subjects/Rank_4/CPP02.pdf) · [CPP03](../../../Subjects/Rank_4/CPP03.pdf) · [CPP04](../../../Subjects/Rank_4/CPP04.pdf) · [CPP05](../../../Subjects/Rank_5/CPP05.pdf) · [CPP06](../../../Subjects/Rank_5/CPP06.pdf) · [CPP07](../../../Subjects/Rank_5/CPP07.pdf) · [CPP08](../../../Subjects/Rank_5/CPP08.pdf) · [CPP09](../../../Subjects/Rank_5/CPP09.pdf)
