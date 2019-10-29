//18/94087
//q1.kernalversion,CPU,memory

#include<stdio.h>	
//for printf(),scanf()
#include<sys/statfs.h>
//for struct statfs,statfs()=returns info about a mounted filesystem
#include<sys/sysinfo.h>
//for struct sysinfo,sysinfo()=returns info about memory
#include<sys/utsname.h>	
//for struct utsname,uname()=returns info about current kernal

int main()
{
	int a,b,c,MB,GB;
	struct statfs sf;
	struct sysinfo si;
	struct utsname un;
	a=statfs("./",&sf);
	b=sysinfo(&si);
	c=uname(&un);
	MB=1024*1024;
	GB=MB*1024;
	if(!a&&!b&&!c)
	{
		printf("\nSystem name=%s",un.sysname);
		printf("\nVersion=%s",un.version);
		printf("\nRelease=%s",un.release);
		printf("\nMachine=%s",un.machine);
		printf("\nTotal RAM=%d MB",si.totalram/MB);
		printf("\nFree RAM=%d MB",si.freeram/MB);
		printf("\nUsed RAM=%d MB",(si.totalram/MB-si.freeram/MB));
		printf("\nTotal size of partition=%d GB",(sf.f_blocks-sf.f_bsize)/GB);
	}
	else
		printf("\nError.");
	printf("\n");
	return 0;
}
