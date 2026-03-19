<div align="center">

```
╔═══════════════════════════════════════════════════════════════╗
║                                                               ║
║   ██████╗██████╗ ██████╗     ███╗   ███╗ ██████╗ ██████╗     ║
║  ██╔════╝██╔══██╗██╔══██╗    ████╗ ████║██╔═══██╗██╔══██╗    ║
║  ██║     ██████╔╝██████╔╝    ██╔████╔██║██║   ██║██║  ██║    ║
║  ██║     ██╔═══╝ ██╔═══╝     ██║╚██╔╝██║██║   ██║██║  ██║    ║
║  ╚██████╗██║     ██║         ██║ ╚═╝ ██║╚██████╔╝██████╔╝    ║
║   ╚═════╝╚═╝     ╚═╝         ╚═╝     ╚═╝ ╚═════╝ ╚═════╝    ║
║                                                               ║
║              ██████╗ ██████╗                                  ║
║             ██╔═══██╗╚════██╗                                 ║
║             ██║   ██║ █████╔╝                                 ║
║             ██║   ██║██╔═══╝                                  ║
║             ╚██████╔╝███████╗                                 ║
║              ╚═════╝ ╚══════╝                                 ║
║                                                               ║
║       Numbers aren't always whole.                            ║
║       Neither is understanding them.                          ║
║                                                               ║
╚═══════════════════════════════════════════════════════════════╝
```

![C++98](https://img.shields.io/badge/C%2B%2B-98-00599C?style=flat-square&logo=c%2B%2B)
![42](https://img.shields.io/badge/42-Bangkok-white?style=flat-square&logo=42)
![Module](https://img.shields.io/badge/Module-02-cyan?style=flat-square)

</div>

---

## About

**Module 02** explores ad-hoc polymorphism through operator overloading and introduces the Orthodox Canonical Form. You build a fixed-point number class from scratch, learning how to make custom types behave like built-in ones.

---

## Exercises

| # | Exercise | Description |
|---|----------|-------------|
| 00 | **My First Class in Orthodox Canonical Form** | Fixed-point number class — construction, copy, assignment |
| 01 | **Towards a more useful fixed-point number class** | Conversion constructors, `toFloat`, `toInt`, stream insertion |
| 02 | **Now we're talking** | Comparison, arithmetic, and increment/decrement operators |
| 03 | **BSP** | Binary Space Partitioning — point-in-triangle test |

---

## Key Concepts

```
├── Orthodox Canonical Form   — the four special members
├── Fixed-point arithmetic    — precision without floats
├── Operator overloading      — +, -, *, /, <, >, ==, !=
├── Pre/post increment        — understanding the difference
├── Copy constructor          — deep vs shallow
├── Stream insertion (<<)     — custom output formatting
└── Static member functions   — min / max helpers
```

---

## Build

```bash
c++ -Wall -Wextra -Werror -std=c++98 *.cpp -o program
```

---

<div align="center">

*Part of the 42 C++ Module Series — 42 Bangkok*

</div>✨
