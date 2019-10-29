//18/94087
//same program, different code

#include<unistd.h>	
//standard symbolic constant and type ,for close(),read(),write().fork()
#include<iostream>
using namespace std;

int main()
{
	pid_t pid;
	pid=fork();
	cout<<"\nProcess...\n1.pid=="<<pid<<"\n1.getpid=="<<getpid()<<"\n";
	if(pid<0)	cout<<"\nError no process.\n";
	else if(pid==0)
	cout<<"\nChild process..."<<"\n2.pid=="<<pid<<"\n2.getpid=="<<getpid()<<"\n";
	else
	cout<<"\nParent process..."<<"\n3.pid=="<<pid<<"\n3.getpid=="<<getpid()<<"\n";
	return 0;
}

