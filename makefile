GPP = g++ -O3 -Wall -std=c++11

M = memory_mapped_io.cc
D = standard_io.cpp

memorymap: $M
	$(GPP) -o memorymap $M

standard: $D
	$(GPP) -o standard $D

clean:
	rm ./standard ./memorymap
