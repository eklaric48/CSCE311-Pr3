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

#define MAXLINE 1500
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

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
    
    int fp = open(fileName.c_str(), O_RDONLY, S_IRUSR);
    
    std::map<char, int> characters;
    char buf[MAXLINE];
    
    int incoming = read(fp,buf,MAXLINE);
    char c;
    while (incoming > 0)
    {
        for (int i = 0; i < incoming; ++i)
        {
            c = buf[i];
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
        
        incoming = read(fp,buf,MAXLINE);
    }
    
    close(fp);
    
    for (MapIterator mit = characters.begin(); mit != characters.end(); mit++)
    {
        cout << "Char: " << mit->first << "\tCount: " << mit->second << endl;
    }
}