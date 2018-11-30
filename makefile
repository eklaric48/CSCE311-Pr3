GPP = g++ -O3 -Wall -std=c++11

C = countChars.cpp
M = memory_mapped_io.cc

standard: $C
	$(GPP) -o standard $C

memorymap: $M
	$(GPP) -o memory $M

clean:
	rm ./standard ./memory
