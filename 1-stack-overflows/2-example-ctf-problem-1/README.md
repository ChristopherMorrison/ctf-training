# Visualized Overflow
## Demonstation:
Here is an example CTF problem, the printf statement used previously has been left i n for ease of use. The goal is to set overflowed_int to `\xf00dbabe`

This program will take the first argument after the binary name and enter it into the buffer.

Arbitrary bytes can be printed to the console using python2 (python3 uses utf-8, which will cause issues) like so:
```
python -c "print('\x01\xFF')"
```

## Takeaways:
- How to cause a trivial overflow through unfiltered user input
