/*
Code written and edited by Edmond Klaric.

This program reads in a text file using standard File IO
and counts the number of each character in the file by inserting 
them into a map as a <char, int> pair.
*/

#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <time.h>
#include <map>
#include <unistd.h>
#include <iostream>

#define MAXLINE 1500

using std::cout;
using std::endl;

typedef std::map<char, int>::iterator MapIterator;

int main(int argc, char *argv[])
{
    clock_t start = clock();
    
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
    
    clock_t finish = clock();
    double total_time = (double)(finish - start) / CLOCKS_PER_SEC;
    
    cout << "\nTotal time of execution: " << std::to_string(total_time) << " seconds" << endl;
}