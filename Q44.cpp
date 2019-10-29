//18/94087
//parent waits child 
#include<sys/wait.h>
//for wait()
#include<unistd.h>	
//standard symbolic constant and type ,for close(),read(),write().fork()
#include<iostream>
using namespace std;

int main()
{
	pid_t pid;
	pid=fork();
	if(pid<0)	cout<<"\nError no process.\n";
	else if(pid==0)
	{	execlp("ps","ps",NULL);	cout<<"\nChild process...\n";	}
	else
	{	wait(NULL);	cout<<"\nParent process...\n";	}
	return 0;
}

