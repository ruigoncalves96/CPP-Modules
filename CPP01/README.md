*This project has been created as part of the 42 curriculum by randrade.*

# C++ Module 01

*Rank 04 — Memory allocation, pointers to members, references and `switch`.*

## Description

Where the objects live. C++ gives you two places to put an object — the stack, where
it dies at the end of scope, and the heap, where it lives until you `delete` it — and this
module makes the difference concrete by having you build the same thing both ways.

It also introduces **references**, which have no C equivalent: an alias that cannot be
null and cannot be reseated. Half the module is really about choosing between a pointer
and a reference, and the answer is usually "reference, unless it must be able to point at
nothing".

## Exercises

| Directory | Exercise | Binary | What it covers |
|-----------|----------|--------|----------------|
| `ex00` | BraiiiiiiinnnzzzZ | `zombie` | One zombie on the heap, one on the stack. `newZombie` returns a pointer you must free; `randomChump` creates one that cleans itself up. |
| `ex01` | Moar brainz! | `ZombieHorde` | Allocate an array of zombies in a single `new[]`, and free it with the matching `delete[]`. |
| `ex02` | HI THIS IS BRAIN | `ThisIsBrain` | A string, a pointer to it and a reference to it — printing all three addresses and values to show that a reference *is* the object, not a copy. |
| `ex03` | Unnecessary violence | `FightClub` | `HumanA` holds a `Weapon &`, `HumanB` a `Weapon *`. The exercise is choosing correctly: B's weapon is optional, A's is not. |
| `ex04` | Sed is for losers | `sed` | A file-based find-and-replace using only `std::string` operations — no `std::replace`, so you implement it with `find` and `substr`. |
| `ex05` | Harl 2.0 | `harl` | Four complaint levels dispatched through an array of **pointers to member functions** — the C++ answer to a function-pointer table. |
| `ex06` | Harl filter | `harlFilter` | The same dispatch driven by a `switch` with deliberate fall-through, so that asking for a level prints it and everything above it. |

## Instructions

Each exercise builds on its own:

```sh
cd ex00 && make && ./zombie
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

- stack versus heap allocation; `new`/`delete` and `new[]`/`delete[]`
- references: non-null, non-reseatable aliases
- when a member should be a reference and when a pointer
- pointers to member functions, and the syntax that makes them work
- `switch` fall-through used on purpose
- file streams: `std::ifstream` and `std::ofstream`

## Notes

`ex05` and `ex06` solve the same problem twice on purpose — once with a member-function table, once with a `switch` — which is the module's clearest lesson in picking a dispatch mechanism.

## Resources

- [cppreference.com](https://en.cppreference.com/w/)
- [`CPP01.pdf`](../../../../Subjects/Rank_4/CPP01.pdf) — the module subject
- [All C++ modules](..) — the overview
