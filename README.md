# libcaesar-rt

Real-time data structures and algorithms written for a course on Advanced C Programming in Real-Time Systems. Follows strict coding standards used in safety-critical embedded systems.

## What's Included

**caesar_ring** - Lock-free circular buffer for single producer/single consumer
- O(1) operations with predictable timing
- No dynamic allocation after init
- Runtime integrity checks (canaries, magic values)
- Explicit memory ordering

**caesar_sort** - Stable descending sort that preserves original indices
- Implemented as optimized bubble sort for MISRA C:2012 compliance
- Shows how to meet real-time coding standards

Both static (.a) and shared (.so) libraries are built.

## Real-Time Properties

- Bounded worst-case execution time
- No dynamic memory allocation after initialization
- MISRA-C:2012 compliant (deviations documented)
- Verified with static analyzers for undefined behavior
- Suitable for ASIL-D / SIL-3 style development

## Build

```bash
mkdir build && cd build
cmake .. -DCMAKE_BUILD_TYPE=Release
make -j
```

## Files

```
circular_buffer.{c,h} → original coursework (refactored as caesar_ring)
libcaesar-rt.a / .so  → library artifacts
librot13.a / .so      → alternative build target
main.c, program.c     → demo programs
cipher*.txt           → test data
```

## License

MIT
