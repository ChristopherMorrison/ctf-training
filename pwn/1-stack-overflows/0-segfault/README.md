# The Segfault
## Demonstation:
Open up `the-segfault.c` and take a quick look at it. It's a relatively simple program that simply fills a buffer with 'A'. However, there is a flaw that you may catch, there is no stopping condition in our loop. This results in our index incrementing forever, way past the 512 byte size of our buffer.

Compiling with `gcc -g -o the-segfault the-segfault.c` (the `-g` includes debug symbols for use with gdb) and running, we can see that when our program runs will end up with the terror of intro to CS, the *Segmentation Fault*. At a high level, the Sementation Fault is thrown when we try to access invalid memory address for our program.

We can also see that our index reaches much higher than the length of our buffer, which also lets us know that we can reach into a very large memory range that our program occupies and begin to edit the information in that memory range.

## Takeaways:
- *Segfault* means we have accessed invalid an memory address
- We have the ability to write past the defined length of buffers
- There is a large memory range that our program can store data in

