#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>

using namespace std;

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

		int fatherPid = getpid();
		cout << "This is parent process!" << endl;
		cout << "This parent process ID is " << fatherPid << endl;
		cout << "The uid is " << getuid() << endl;
		cout << "The gid is " << getgid() << endl;

		cout << "num = " << num << endl;


	}

	exit(0);

	return 0;

}