# Results for Assignment 01

## Improvement Iterations

Here's a table showing the improvements I did to make the application go faster.  The **Time** column in the table represents the time taken to load the page as clocked in Opera.

| Version | Time | Speedup | Changes |
| :-----: | ---- | :-----: | ------- |
| 01 | 78.8ss | &mdash; | Initial version - no changes |
| [02](server.cpp) | 52.6ss | 1.5x | Basic multithreading implemented |

## Profiling Analysis

### Initial Review

I implemented a simple multithreading scheme that creates and detatches thread for every incoming connection. What surprised me is how little it changed the runtime, with only a 1.5x speedup. I suspect this would be less true on a server where my program was allocated a higher data throughput, but I don't know for sure. 
