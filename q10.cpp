//18/94087
//paging scheme

#include<iostream>
#include<time.h>
using namespace std;

int phy_mem;
int page_size;
int no_of_frames;
struct Frame
{
	int fill;
	char name;
}*Fr;

void init()
{
	cout<<"\nEnter the size of the physical memory:";
	cin>>phy_mem;
	cout<<"\nEnter the size of the page:";
	cin>>page_size;
	no_of_frames=phy_mem/page_size;
	if(phy_mem%page_size!=0)
	no_of_frames++;	
	Fr=new struct Frame[no_of_frames];
	for(int i=0;i<no_of_frames;i++)
	Fr[i].fill=0;
}
class Paging
{
	char pname;
	int psize,no_of_pages;
	int *arr,*loc;
	public:
		void enter()
		{
			cout<<"\nEnter the name of the process:";
			cin>>pname;
			cout<<"\nEnter the memory required for the process:";
			cin>>psize;
			no_of_pages=psize/page_size;
			if(psize%page_size!=0)
			no_of_pages++;
			arr=new int[no_of_pages];
			loc=new int[no_of_pages];
			for(int i=0;i<no_of_pages;i++)
			arr[i]=i;
			srand(time(NULL));
		}
		void allocate()
		{
			for(int i=0;i<no_of_pages;i++)
			{
				int y=rand()%no_of_frames;
				if(Fr[y].fill==0)
				{
					
					Fr[y].fill=1;
					Fr[y].name=pname;
					loc[i]=y;
				}
				else
				{
					int x=rand()%no_of_frames;
					while(Fr[x].fill!=0)
					x=rand()%no_of_frames;
					Fr[x].fill=1;
					Fr[x].name=pname;
					loc[i]=x;
				}	
			}
		}
		void deallocate(char a)
		{
			bool flag=false;
			for(int i=0;i<no_of_frames;i++)
			{
				
				if(Fr[i].name==a)
				{
					flag=true;
					Fr[i].fill=0;
					Fr[i].name='.';
				}
			}
			if(!flag)
			cout<<"\nProcess has already been deallocated";
			else
			{
				cout<<"\nFill\tProcess name\n";
				for(int i=0;i<no_of_frames;i++)
				{
					if(Fr[i].fill==1)
					cout<<Fr[i].fill<<"\t\t"<<Fr[i].name<<"\n";
					else
					cout<<Fr[i].fill<<"\t\t"<<"Frame not allocated\n";
				}
			}			
		}
		void display(char a)
		{
			int c=0;
			bool flag=false;
			cout<<"\nPage Number\tFrame number\n";
			for(int i=0;i<no_of_frames;i++)
			{
				if(Fr[i].name==a)
				{
					flag=true;
					cout<<c<<"\t\t"<<i+1<<"\n";
					c++;
				}
			}
			if(!flag)
			cout<<"\nProcess has already been deallocated";
		}
};
int main()
{
	init();
	int n;
	cout<<"\nEnter the number of Processes:";
	cin>>n;
	Paging P[10];
	for(int i=0;i<n;i++)
	{
		P[i].enter();
		P[i].allocate();
	}	
	int c;
	char h;
	while(1)
	{
		cout<<"\n1.Deallocate";
		cout<<"\n2.Display page table of a process";
		cout<<"\n3.Exit";
		cout<<"\nEnter your choice:";
		cin>>c;
		switch(c)
		{
			case 1:cout<<"\nEnter the process name:";
   					cin>>h;
					   P[0].deallocate(h);
					   break;
			case 2:cout<<"\nEnter the process name:";
					cin>>h;
					P[0].display(h);
					break;
			case 3:exit(0);
			break;
			default:cout<<"\nWrong choice!!";
			break;					
		}
	}
}
