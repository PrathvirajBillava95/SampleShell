#include <string>
using namespace std;
#include "functions.h"

int CheckIfPipeCmd(string str)
{
        int findPipe = str.find('|', 0);
		
	return findPipe;
}

void splitSpace(string str, string *parsedCmd)
{
        int i=0;
        size_t prev, curr;

        prev = 0;
        curr = str.find(' ', prev);

        while(curr != std::string::npos) {
                parsedCmd[i++] = str.substr(prev, curr-prev);
                prev = curr + 1;
                curr = str.find(' ', prev);
        }
        parsedCmd[i] = str.substr(prev, curr-prev);

}
