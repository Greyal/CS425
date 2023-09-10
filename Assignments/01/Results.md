# Results for Assignment 01

## Improvement Iterations

Here's a table showing the improvements I did to make the application go faster.  The **Time** column in the table represents the _wall-clock time_ for a program run.

| Version | Time | Speedup | Memory (KB) | Changes |
| :-----: | ---- | :-----: | :------: | ------- |
| [01](01.cpp) | 9.42s | &mdash; | 1041140 | Initial version - no changes |
| 02 | 1.66s | 5.67x | 1041328 | Compiled with -Ofast |
| 03 | 9.33s | 1.01x | 1041332 | Compiled with -funroll-loops |
| 04 | 9.52s | 0.99x | 1040272 |  Compiled with -funroll-all-loops |
| 05 | 9.07s | 1.04x | 1041336 |  Compiled with -O0 |
| 06 | 9.15s | 1.03x | 1041320 |  Compiled with -O0 -funroll-loops | 
| 07 | 1.51s | 6.24x | 1041336 | Compiled with both -Ofast and -funroll-loops 

## Profiling Analysis

### Initial Review

Looking at [01] (01.cpp) there are several loops that happen once per face, with one being when the data is loaded and another when it is processed. I figured that -funroll-loops would offer some speedup, since these large loops are present. However, it had barely any effect, and the same is true for -funroll-all-loops. I thought this might be because the optimizer was already unrolling loops, so I tested -O0, but this made the code (negligibly) faster. Using -funroll-loops as well as -O0 made no appreciable difference, so I am forced to conclude that the logic in the looops themselves is not affecting the calculation time much. -Ofast made a significant difference, and using both -Ofast and -funroll-loops seemed to speed it up slightly further, which is interesting, but I'm honestly not sure how to interpret what that means for how the program is being compiled. 
