/*
 * Simple Unix Like shell written in C++
 * Author: Prathviraj Billava
 *
 * main.cpp : main function file
 *
 * The program takes linux command as input
 * from the user, executes the command and 
 * then prints the output of executed command
 *
 * The program only supports normal linux commands 
 * and single pipe commands. It doesn't support 
 * redirection (>> or >)
 *
 */

#include "command.h"
#include "functions.h"

int main()
{
        do {
		command cmd;
		cout << "MyShell::" << get_current_dir_name() << "# ";
                getline(cin, cmd.command);
		if(cmd.command == "exit")	// if the user enters exit then the shell terminates
			exit(0);
                cmd.parseCommand();
                if(cmd.bPipe)
                        cmd.execPiped();	// calls execPiped() if the command has pipe
                else
                        cmd.exec();
        }while(1);
        return 0;
}
