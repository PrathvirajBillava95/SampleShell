/*
 * Code Owner: Prathviraj Billava
 * 
 * Simple Unix Like shell written in C++
 * 
 * command.h : header file for commmand.cpp
 *
 * command class and its members
 *
 */

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
	string cmdArgs[MAXARGS];		// stores the normal command argumants
	string pipeCmdArgs[MAXARGS];		// stores the single pipe command arguments
public:
	bool bPipe= false; 			// flag to denote whether the command is a normal one or has pipe
	string command;				// stored the whole command string
	void parseCommand();			// Parse the command string and split it into command and arguments
	void exec();				// execute the normal (non-pipe) command
	void execPiped();			// execute the single pipe command
};
#endif
