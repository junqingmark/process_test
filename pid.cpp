#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <signal.h>
#include <sys/wait.h>

using namespace std;

void sigHandlerCallback(int signo)
{
		int status;
		wait(&status);
		if(WIFEXITED(status))
		{
			printf("The SIGCHILD has been executed!\n");
			printf("The child process exit normally!\n");
		}
		

}


int main()

{

	pid_t pid;

	pid = vfork();

	int num = 1;

	if (pid < 0)

	{

		perror("In fork()");

		exit(1);

	}

	else if (pid == 0)

	{

		int childPid = getpid();
		cout << "This is child process!" << endl;
		cout << "This child process ID is " << childPid << endl;
		cout << "The uid is " << getuid() << endl;
		cout << "The gid is " << getgid() << endl;

		cout << "num = " << num << endl;
		_exit(0);

	}

	else

	{
		signal(SIGCHLD, sigHandlerCallback);
		int fatherPid = getpid();

		while(1)
		{
			cout << "This is parent process!" << endl;
			cout << "This parent process ID is " << fatherPid << endl;
			cout << "The uid is " << getuid() << endl;
			cout << "The gid is " << getgid() << endl;

			cout << "num = " << num << endl;
			sleep(1);
		}
		
		


	}

	exit(0);

	return 0;

}