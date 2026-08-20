*This project has been created as part of the 42 curriculum by randrade.*

# C++ Module 05

*Rank 05 — Repetition and exceptions.*

## Description

Error handling that cannot be ignored. A return code can be discarded; a thrown
exception cannot. This module builds a small bureaucracy — bureaucrats with grades from 1
(highest) to 150 (lowest), forms that require a grade to sign and another to execute — and
every rule violation is expressed as a custom exception type.

The bureaucratic theme is doing real work: grades are bounded on both ends, so there are
two failure modes for every operation, and the classes have to throw rather than clamp.

## Exercises

| Directory | Exercise | Binary | What it covers |
|-----------|----------|--------|----------------|
| `ex00` | Mommy, when I grow up, I want to be a bureaucrat! | `Bureaucrat` | A `Bureaucrat` with an immutable name and a grade, throwing `GradeTooHighException` or `GradeTooLowException` whenever the bounds are breached. |
| `ex01` | Form up, maggots! | `BureaucratForm` | A `Form` with separate grades required to sign and to execute, signed via the bureaucrat so the check lives on one side only. |
| `ex02` | No, you need form 28B, not 28C... | `Forms` | `Form` becomes the abstract `AForm` with three concrete subclasses — shrubbery creation, robotomy request and presidential pardon — each with its own execution behaviour and grade requirements. |
| `ex03` | At least this beats coffee-making | `Forms` | An `Intern` that manufactures a form from its name alone, without a chain of `if`s exposed to the caller. |

## Instructions

Each exercise builds on its own:

```sh
cd ex00 && make && ./Bureaucrat
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

- `throw` / `try` / `catch`, and the stack unwinding in between
- custom exception classes deriving from `std::exception`
- overriding `what()`, and why it is `const` and `throw()` in C++98
- catching by reference rather than by value, to avoid slicing
- `const` members and why they must be set in the initialization list
- abstract base classes revisited, now carrying behaviour as well as an interface

## Notes

The `Intern` in `ex03` is a factory: the subject wants the form chosen by name without a visible `if`/`else` ladder, which is really an argument for a table of names and creators.

## Resources

- [cppreference.com](https://en.cppreference.com/w/)
- [`CPP05.pdf`](../../../../Subjects/Rank_5/CPP05.pdf) — the module subject
- [All C++ modules](..) — the overview
