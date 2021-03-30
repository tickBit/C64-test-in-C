Simple test to program the C64 in C with CC65 compiler.

Without raster interrupt, sync with vertical beam..

You need a C64 emulator to run the executable.

Steps to compile:

cc65 -t c64 "c64 test in c.c"
ca65 "c64 test in c.s"
cl65 "c64 test in c.o"
