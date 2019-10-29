//18/94087
//q5.producer consumer problem

#include<iostream>
using namespace std;

class q
{
	public:
	int in,out,size,que[];
	
	q()
	{
		cout<<"\nSize of queue=";	cin>>size;
		que[size];	in=0;	out=0;
	}
	void producer(int p)
	{
		if((in+1)%size!=out)
		{	que[in]=p;	in=(in+1)%size;	cout<<"\nProduced.";	}
		else
		cout<<"\nFull queue.";
	}
	void consumer()
	{
		int c;
		if(in!=out)
		{	
			c=que[out];	out=(out+1)%size;
			cout<<"\nConsumed=="<<c;	
		}
		else
		cout<<"\nEmpty queue.";	
	}
	void menu()
	{
		char c;
		do
		{
			cout<<"\nProducer/Consumer (1/n)=";
			int ch;	cin>>ch;
			if(ch==1)
			{
				cout<<"\nProduce=";
				int n;	cin>>n;	producer(n);
			}
			else
			consumer();
			cout<<"\nContinue (y/n)=";  cin>>c;
		}while(c=='y'||c=='Y');
	}
};
int main()
{
	q obj;
	obj.menu();
	return 0;
}

