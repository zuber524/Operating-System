//18/94087
//q3.copy one file to another

#include<fcntl.h>	
//for fcnt()=set and get files permission flag,open(),creat()
#include<unistd.h>	
//standard symbolic constant and type ,for close(),read(),write()
#include<iostream>
using namespace std;

int main(int arg,char *args[])
{
	if(arg<3)
	{
		cout<<"\nMissing arguments.";
		exit(0);
	}
	int f1=open(args[1],0);
	if(f1<0)
	{
		cout<<"\nError in opening source file.";
		exit(0);
	}
	int f2=creat(args[2],0666);
	char c[500];
	int count;
	while(count=read(f1,c,sizeof(c)))
	write(f2,c,count);
	close(f1);
	close(f2);
	cout<<"Copied"<<endl;
	return 0;
}
