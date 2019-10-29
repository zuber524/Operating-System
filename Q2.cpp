//18/94087
//q2.file access permission

#include<fcntl.h>	
//for fcnt()=set and get files permission flag,open(),creat()
#include<sys/stat.h>
//for struct stat,fstat()=returns structure of data
#include<iostream>
using namespace std;

int main(int arg,char *args[])
{
	char t[50];
	struct stat s;
	int f;
	if(arg<2)
	cout<<"\nMissing arguments.";
	else
	{
		f=open(args[1],O_RDONLY);	//O_RONLY=open for read only
		fstat(f,&s);
		cout<<"\nOwner uid="<<s.st_uid;
		cout<<"\nGroup gid="<<s.st_gid;
		cout<<"\nAccess permission="<<s.st_mode;
		cout<<"\nSize="<<s.st_size;
		strftime(t,sizeof(t),"%d-%m-%y,%H:%M:%S",localtime(&s.st_atime));
//atime=access time
		cout<<"\nLast access time="<<t;
		strftime(t,sizeof(t),"%d-%m-%y,%H:%M:%S",localtime(&s.st_mtime));
//mtime=modified time
		cout<<"\nLast modified time="<<t;
	}
	cout<<endl;
	return 0;
}
