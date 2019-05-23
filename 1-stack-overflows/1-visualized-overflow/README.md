# Visualized Overflow
## Demonstation:
Open up `visualized-overflow.c` and take a quick look at it. At first glance, it's nearly identical to our previous code, however the most important change here is the position in which we declare our buffer. This change will be explained momentarily. Also included is a printf statement that will visualize the memory we are interested in without requiring GDB.

This time we will need the ~forbidden~ `-fno-stack-protector` flag when compiling. Take note that this flag must be manually typed and will not autocomplete with tab.

Compiling with `gcc -fno-stack-protector -o the-segfault the-segfault.c` and running, we get a visualization of the iterations of our loop. We can see our 15 byte buffer fill up, but then the remaining 4 'A' bytes are written into the memory of our `overflowed_int`! Why is this?

As it turns out, when variables are put onto the program memory, or stack, they are added in "reverse order". The memory values of the stack start high and then decrease with every vaiable added, approaching 0.

This means that because we've declared our buffer in the C code after we've declared our `overflowed_int`, if we write past the end of our buffer we are really writting into our int. Luckily, modern compilers include stack protection by default.

Visualized, our memory looks like this:
```
x0...<-- Lower Stack Frames/Variables   |LSB                   15 byte buffer                MSB|LSB  4 byte int    MSB | Higher stack frames and overflow direction -->...
  ......................................| A | A | A | A | A | A | A | A | A | A | A | A | A | A |  A  |  A  |  A  |  A  |..................................................
``` 

An additional point to note is the endianness of our architecture. Endianness is either little or big. Little endian architectures store the Least Significant Byte (LSB) at the lowest address in a variable's memory range. Big endianness does the opposite, storing the Most Significant Byte (MSB) at lowest address.

Both i386 and x86_64 are little-endian. This can be proved with the table printed out by our program. When we overflow our buffer, we change the value of the lower bytes first. We can see that a single overflowed 'A' = \x00000041 = 65, demonstrating the lower bytes are overflowed first.

## Takeaways:
- We can overwrite "previously" declared variables on the same stack almost trivially
- The `-fno-stack-protector` flag for gcc allows us to compile code without stack protection (on modern GCC versions)
- Endianess

