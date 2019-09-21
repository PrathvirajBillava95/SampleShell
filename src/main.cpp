#include "command.h"
#include "functions.h"

int main()
{
        do {
		command cmd;
		cout << "MyShell::" << get_current_dir_name() << "# ";
                getline(cin, cmd.command);
		if(cmd.command == "exit")
			exit(0);
                cmd.parseCommand();
                if(cmd.bPipe)
                        cmd.execPiped();
                else
                        cmd.exec();
        }while(1);
        return 0;
}
