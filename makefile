GPP = g++ -O3 -Wall -std=c++11

C = countChars.cpp
M = memory_mapped_io.cc
D = standard_io.cpp

standard: $C
	$(GPP) -o standard $C

memorymap: $M
	$(GPP) -o memory $M

standard2: $D
	$(GPP) -o standard2 $D

clean:
	rm ./standard ./standard2 ./memory
