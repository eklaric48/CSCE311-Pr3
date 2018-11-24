/*
This program reads in a text file using standard File IO
and counts the number of each character in the file by inserting 
them into a map as a <char, int> pair.
*/
#include <string.h>
#include <fstream>
#include <map>
#include <unistd.h>
#include <iostream>

using std::cout;
using std::endl;

typedef std::map<char, int>::iterator MapIterator;

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		cout << "usage: ./Aprog <filepath>" << endl;
		exit(1);
	}
	
    std::string fileName = argv[1];
    std::ifstream myFile(fileName.c_str());
    std::map<char, int> characters;
    
    std::string line;
    
    if (myFile.is_open())
    {
        while (getline(myFile,line))
        {
            for (char& c : line)
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
    }
    
    else
    { 
        cout << "Unable to open file." << endl;
        exit(1);
	}
	
	myFile.close();
    
    for (MapIterator mit = characters.begin(); mit != characters.end(); mit++)
    {
        cout << "Char: " << mit->first << "\tCount: " << mit->second << endl;
    }
    
}