/*
This program reads in a text file using memory mapped File IO
and counts the number of each character in the file by inserting 
them into a map as a <char, int> pair.
*/


#include <map>
#include <unistd.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

typedef std::map<char, int>::iterator MapIterator;

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cout << "usage: ./Aprog <filepath>" << std::endl;
		exit(1);
	}
	std::string fileName = argv[1];
	
	int fp = open(fileName.c_str(), O_RDWR, S_IRWXU);
	
	int ret;
	long int file_size;
	struct stat status;
	char *addr;
	std::map<char, int> characters;
	
	ret = fstat(fp,&status);
	if (ret < 0) {
		std::cout << "Error in fstat" << std::endl;
		exit(1);
	}
	
	file_size = status.st_size;
	
	addr = (char *) mmap(NULL,file_size,PROT_READ,MAP_PRIVATE,fp,0);
	
	char c;
	for (int i = 0; i < file_size; ++i)
	{
		c = addr[i];
		if (c != '\n')
		{
			if (characters.count(c) == 0)
			{
				characters.insert(std::pair<char, int>(c, 1));
			}
			else
			{
				MapIterator mit = characters.find(c);
				mit->second += 1;
			}
		}
	}
	close(fp);
	
	for (MapIterator mit = characters.begin(); mit != characters.end(); mit++)
	{
		std::cout << "Char: " << mit->first << "\tCount: " << mit->second << std::endl;
	}
}