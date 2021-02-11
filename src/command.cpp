/*
 * Code Owner: Prathviraj Billava
 * 
 * Simple Unix Like shell written in C++
 *
 * command.cpp :  Implements the functions from the command class
 *
 */

#include "command.h"
#include "functions.h"

/*
 * void command::parseCommand()
 * Parse the command string and split it 
 * into command and arguments
 */
void command::parseCommand()
{
	int pipe;
	pipe = CheckIfPipeCmd(command);

	if(pipe != -1 ) {
		bPipe = true;
		string cmd1, cmd2;
                cmd1 = command.substr(0, pipe++);
		while(command[pipe] == ' ')
			pipe++;
                cmd2 = command.substr(pipe, command.length());
                splitSpace(cmd1, cmdArgs);
                splitSpace(cmd2, pipeCmdArgs);

        } else {
                splitSpace(command, cmdArgs);
        }
}

/*
 * void command::exec()
 * Execute the normal (non-piped) command
 */
void command::exec()
{
        if(cmdArgs[0].substr(0,5) != "/home") {
                cmdArgs[0] = "/bin/"+cmdArgs[0]; 	// append /bin to the command
        }

        char *cmd[MAXARGS]={};

        for(int i = 0 ;i < MAXARGS ;i++){
                if(cmdArgs[i] != "")
                        cmd[i] = const_cast<char *>((cmdArgs[i]).c_str());
        }

        pid_t pid = fork();

        if (pid == 0){
                if(execvp(cmd[0],cmd) == -1){
                        cout<<"Failed to execute " << cmd[0] << " command" << std::endl;
                        exit(0);
                }
        } else{
                int status;
                waitpid(pid, &status,0);
        }
}

/*
 * void command::execPiped()
 * Execute the single pipe command
 */
void command::execPiped()
{
        pid_t pid1, pid2;
        int pd[2];
        char *cmd1[MAXARGS]={}, *cmd2[MAXARGS]={};

        if(cmdArgs[0].substr(0,5) != "/home") {
                cmdArgs[0] = "/bin/"+cmdArgs[0];	// append /bin to the command
        }

        if(pipeCmdArgs[0].substr(0,5) != "/home") {
                pipeCmdArgs[0] = "/bin/"+pipeCmdArgs[0];	// append /bin to the command
        }

        for(int i = 0 ;i < MAXARGS ;i++){
                if(cmdArgs[i] != "")
                        cmd1[i] = const_cast<char *>((cmdArgs[i]).c_str());
        }

        for(int i = 0;i <MAXARGS; i++) {
                if(pipeCmdArgs[i] != "")
                        cmd2[i] = const_cast<char *>((pipeCmdArgs[i]).c_str());
        }

        if(pipe(pd) < 0){
                cout << "Failed to create a pipe" << std::endl;
                return;
        }
        pid1 = fork();

        if(pid1 == 0) {
                close(pd[0]);
                dup2(pd[1], STDOUT_FILENO);
                close(pd[1]);

                if(execvp(cmd1[0],cmd1) == -1){
                        cout<<"Failed to execute " << cmd1[0] << " command" << std::endl;
                        exit(0);
                }
        } else {
                pid2 = fork();

                if(pid2 == 0) {
                        close(pd[1]);
                        dup2(pd[0], STDIN_FILENO);
                        close(pd[0]);
                        if(execvp(cmd2[0],cmd2) == -1){
                                cout<<"Failed to execute " << cmd2[0] << " command" << std::endl;
                                exit(0);

                        }
                } else {
                        wait(NULL);
                      	wait(NULL);
                }
        }

}
