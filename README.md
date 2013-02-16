sha256
======

sha256 hash implementation in c++ from back in 2010.

Most likely slow, bloated and buggy. This was written as a learning exercise, to understand the sha256 algorithm. This is where I started: http://en.wikipedia.org/wiki/SHA-2#Pseudocode

Compile
-------
anything of the sort:

    g++ sha256.cpp main.cpp

or however suits your needs.

It will compile/run on windows, but I haven't tried the test code (main.cpp) on windows. I should also dig up some currently MIA unit tests, which I vaguely remember writing for this.

Performance
-----------
Bad! But generally runs best with:

    -O2
    
switch when compiling with gcc.
