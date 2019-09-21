#ifndef __COMMAND_CLASS_H__
#define __COMMAND_CLASS_H__

#include <string>
#include <cstring>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <iostream>

#define MAXARGS 10
using namespace std;

class command 
{
private:
	string cmdArgs[MAXARGS];
	string pipeCmdArgs[MAXARGS];
public:
	bool bPipe= false;
	string command;
	void parseCommand();
	void exec();
	void execPiped();
};
#endif
