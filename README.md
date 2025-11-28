# libcaesar-rt
**Real-Time Safe Embedded Utilities – Advanced C Programming in Real-Time Systems**

[![Course](https://img.shields.io/badge/Course-Advanced_C_in_Real--Time_Systems-006400)](#)
[![MISRA-C:2012](https://img.shields.io/badge/MISRA--C-2012_Compliant-blue)](#)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](LICENSE)

Course project repository for **Advanced C Programming in Real-Time Systems**.

This library contains reference implementations of fundamental real-time data structures and algorithms written with the strict coding standards and defensive programming techniques required in hard real-time and safety-critical environments.

### Components

- **`caesar_ring`** – Deterministic, lock-free, bounded SPSC circular buffer  
  Predictable O(1) operations, no dynamic allocation, full runtime integrity verification (canaries, poison values, magic signatures), explicit memory ordering.
- **`caesar_sort`** – Stable descending sort with original index preservation  
  Intentionally implemented as an optimized bubble sort to demonstrate full compliance with MISRA C:2012, CERT, and AUTOSAR C++14 guidelines in real-time contexts.

Both static (`libcaesar-rt.a`) and shared (`libcaesar-rt.so`) libraries are provided.

### Key Real-Time Properties

- Bounded worst-case execution time (WCET)
- No dynamic memory allocation after initialization
- Full MISRA-C:2012 compliance (all rule deviations explicitly documented and isolated)
- Zero undefined behavior (verified with multiple static analyzers)
- Suitable as teaching/reference material for ASIL-D / SIL-3 development

### Build

```bash
mkdir build && cd build
cmake .. -DCMAKE_BUILD_TYPE=Release
make -j

Directory Contents

circular_buffer.{c,h} → original coursework files (now refactored as caesar_ring)
libcaesar-rt.a / .so → final library artifacts
librot13.a / .so     → alternative build target (identical functionality)
main.c, program.c    → real-time demonstration programs
cipher*.txt            → test vectors and sample data

License
MIT License – free for academic and commercial use.
