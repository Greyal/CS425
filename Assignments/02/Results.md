# Results for Assignment 01

## Improvement Iterations

Here's a table showing the improvements I did to make the application go faster.  The **Time** column in the table represents the _wall-clock time_ for a program run.

| Version | Time | Speedup | Changes |
| :-----: | ---- | :-----: | ------- |
| 01 | 10m 46s | &mdash; | Initial version - no changes |
| 02 | 1m 45s | 6.15x | Dynamic scheduling with incorrect number of data items per processing chunk |
| 03 | 1m 10s | 9.23x | Dynamic scheduling with correct number of data items per processing chunk |
| [04](lychrel.cpp) | 44.889s | 14.41x | Version 03 with line reversing the vector removed and additional thread safety implementations |


## Comments

We talked about a lot of this in class and determined that it was extremely weird and that we weren't sure why it worked this way, so I don't have too much explanation that I can do here. Version 02 and 03 are different in that the size of each chunk of data is different, version 02 gives the threads 1/110 * (number of remaining lychrel numbers) per chunk while version 03 gives the threads 1/100 * (number of remaining lychrel numbers) per chunk. Why these are so significantly different is a mystery. Version 04, the final version, removes the line needlessly reversing a vector and implements the thread safety on the results vector that we discussed in class. Interestingly, this thread safety also significantly reduced the optimal chunk size to between 1/3000 and 1/10000 of the remaining lychrel numbers. It's possible that there's an even faster chunk size that I haven't found, who knows. The last thing to note is that the only version I committed is the final version, because I forgot to do the intermediate commits as I was doing the assignment. My bad. 
