GPP = g++ -O3 -Wall -std=c++11

C = countChars.cpp

c: $C
	$(GPP) -o c $C

clean:
	rm ./c