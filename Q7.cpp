//18/94087
//q7.pthread library

#include<iostream>
#include<pthread.h>
using namespace std;
int sum; 

void *runner(void *param)
{
    int n= *(int*)param;
    sum = 0;
    for (int i = 1; i <=n; i++)	sum += i;
    pthread_exit(0);
}

int main()
{
	pthread_t t; 
	int num=5;
	pthread_create(&t,NULL,runner,&num);
	pthread_join(t,NULL);
	cout<<sum<<"\n";
	return 0;
}

