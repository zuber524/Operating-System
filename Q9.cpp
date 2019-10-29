//18/94087
//q9.fisrt best worst fit

#include<iostream>
using namespace std;

class memory
{
	int n,m,*p,*me,*mid,*temp;
	public:
	void input()
	{
		cout<<"\nNumber of process=";	cin>>n;
		p=new int[n];
		cout<<"Process size in KB-->\n";
		for(int i=0;i<n;i++)
		{	cout<<"P"<<i+1<<"=";	cin>>p[i];	}
		cout<<"\nNumber of memory blocks available=";	cin>>m;
		me=new int[m];	temp=new int[m];	mid=new int[m];
		cout<<"Memory block size in KB-->\n";
		for(int i=0;i<m;i++)
		{	cout<<"M"<<i+1<<"=";	mid[i]=i+1;	cin>>me[i];	temp[i]=me[i];	}
	}
	
	void swap(int *x,int *y)
	{	int temp=*x;*x=*y;*y=temp;	}
	
	void sort(char c)
	{
		for(int i=1;i<m;i++)
		for(int j=0;j<m-i;j++)
		if(c=='<'?temp[j]<temp[j+1]:temp[j]>temp[j+1])
		{
			swap(&me[j],&me[j+1]);	swap(&mid[j],&mid[j+1]);
			swap(&temp[j],&temp[j+1]);
		}
	}
	void ff()
	{
		bool f;
		for(int i=0;i<n;i++)
		{	
			f=1;
			for(int j=0;j<m;j++)
			{
				if(p[i]>temp[j]){f=0;}
				else
				{	
					temp[j]-=p[i];	cout<<"\nP"<<i+1<<"->M"<<j+1<<":"<<temp[j]<<"KB";
					f=1;	break;	
				}
			}
			if(!f)	cout<<"\nP"<<i+1<<"->UNALLOCATED";
		}
	}
	
	void bf()
	{
		sort('>');	bool f;
		for(int i=0;i<n;i++)
		{	
			f=1;
			for(int j=0;j<m;j++)
			{
				if(p[i]>temp[j]){f=0;}
				else
				{	
					temp[j]-=p[i];	cout<<"\nP"<<i+1<<"->M"<<mid[j]<<":"<<temp[j]<<"KB";
					f=1;	sort('>');	break;	
				}
			}
			if(!f)	cout<<"\nP"<<i+1<<"->UNALLOCATED";
		}
	}
	
	void wf()
	{
		bool f;	sort('<');
		for(int i=0;i<n;i++)
		{	
			f=1;
			for(int j=0;j<m;j++)
			{
				if(p[i]>temp[j]){f=0;}
				else
				{	
					temp[j]-=p[i];	cout<<"\nP"<<i+1<<"->M"<<mid[j]<<":"<<temp[j]<<"KB";
					f=1;	sort('<');	break;	
				}
			}
			if(!f)	cout<<"\nP"<<i+1<<"->UNALLOCATED";
		}
	}
					
	void menu()
	{
		char c;
		do
		{
			input();
			cout<<"\n1.FIRST FIT\n2.BEST FIT\n3.WORST FIT\n0.EXIT";
			cout<<"\nChoice:";	int ch;	cin>>ch;
			switch(ch)
			{
				case 1:ff();	break;
				case 2:bf();	break;
				case 3:wf();	break;
				case 0:exit(0);
				default: cout<<"\nInvalid input.";
			}
			cout<<"\nRe-enter/(r/...):";
			cin>>c;
		}while(c=='R'||c=='r');
	}
};
	
int main()
{
	memory a;
	a.menu();
	return 0;
}
