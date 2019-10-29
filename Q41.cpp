//18/94087
//same program same code

#include<unistd.h>	
//standard symbolic constant and type ,for close(),read(),write().fork()
#include<iostream>
using namespace std;

int main()
{
	pid_t pid;
	pid=fork();
	if(pid<0)
	cout<<"\nError no process."<<"\n";
	else
	cout<<"\nProcess..."<<"\npid=="<<pid<<"\ngetpid=="<<getpid()<<"\n";
	return 0;
}

