//18/94087
//q6.using pipe system call

#include<iostream>
#include<unistd.h>	
//standard symbolic constant and type ,for close(),read(),write().fork()
using namespace std;

int main()
{
	pid_t pid;
	char m[]="HELLO WORLD.";
	int size=20,p[2];	char n[size];
	pipe(p);	pid=fork();	
	if(pid<0)	cout<<"\nError no process.\n";
	else if(pid==0)
	{	read(p[0],n,size);	cout<<"\n"<<n<<"\n";	}
	else
	{	write(p[1],m,size);	}
	return 0;
}

