//18/94087
//q8.scheduling algorithm

#include<iostream>
using namespace std;

class process
{
	int n,*p,*at,*bt,*wt,*ct,*tat,*pr,*temp;
	public:
	void input()
	{
		cout<<"\nNumber of process=";	cin>>n;
		p=new int[n];	at=new int[n];
		bt=new int[n];	wt=new int[n];
		ct=new int[n];	tat=new int[n];
		pr=new int[n];	temp=new int[n];
		cout<<"Arrival time-->\n";
		for(int i=0;i<n;i++)
		{	cout<<"P"<<i+1<<"=";	cin>>at[i];	}
		cout<<"Burst time-->\n";
		for(int i=0;i<n;i++)
		{	p[i]=i+1;	cout<<"P"<<i+1<<"=";	cin>>bt[i];	}
	}
	
	void swap(int *x,int *y)
	{	int temp=*x;*x=*y;*y=temp;	}
	
	void sort(int *x,int n)
	{
		for(int i=1;i<n;i++)
		for(int j=0;j<n-i;j++)
		if(x[j]>x[j+1]||(x[j]==x[j+1]&&bt[j]>bt[j+1]))
		{
			swap(&p[j],&p[j+1]);	swap(&at[j],&at[j+1]);	
			swap(&bt[j],&bt[j+1]);	swap(&pr[j],&pr[j+1]);
			swap(&temp[j],&temp[j+1]);
		}
	}
	
	void avg(int tat[],int wt[],int n)
	{
		int tats=0,wts=0;
		for(int i=0;i<n;i++)
		{	tats+=tat[i];	wts+=wt[i];	}
		cout<<"\nAVERAGE TURN AROUND TIME:"<<tats*1.0/n;
		cout<<"\nAVERAGE WAITING TIME:"<<wts*1.0/n;
	}
	
	void fcfs()
	{
		sort(at,n);
		cout<<"\n\tP.\tA.T.\tB.T.\tW.T.\tT.A.T.\n";
		for(int i=0;i<n;i++)
		{
			if(ct[i-1]<at[i])
			{
				cout<<"("<<ct[i-1]<<"_"<<at[i]<<")\t~\t~\t~\t~\t~\n";
				ct[i-1]=at[i];	i--;
			}
			else
			{
				ct[i]=ct[i-1]+bt[i];
				tat[i]=ct[i]-at[i];
				wt[i]=tat[i]-bt[i];
				cout<<"("<<ct[i-1]<<"_"<<ct[i]<<")\tP"<<p[i]<<"\t"<<at[i];
				cout<<"\t"<<bt[i]<<"\t"<<wt[i]<<"\t"<<tat[i]<<"\n";
			}
		}
		avg(tat,wt,n);
	}
		
	void sjf()
	{
		sort(at,n);
		int t=0,l=-99;
		for(int i=0;i<n;i++)	temp[i]=bt[i];
		cout<<"\n\tP.\tA.T.\tB.T.\tW.T.\tT.A.T.\n";
		for(int i=0;i<n;i++)
		{
			if(ct[i-1]<at[i])
			{
				cout<<"("<<ct[i-1]<<"_"<<at[i]<<")\t~\t~\t~\t~\t~\n";
				ct[i-1]=at[i];	i--;
			}
			else
			{
				while(t<n&&ct[i-1]>=at[t])	t++;
				sort(temp,t);
				ct[i]=ct[i-1]+bt[i];
				tat[i]=ct[i]-at[i];
				wt[i]=tat[i]-bt[i];
				cout<<"("<<ct[i-1]<<"_"<<ct[i]<<")\tP"<<p[i]<<"\t"<<at[i];
				cout<<"\t"<<bt[i]<<"\t"<<wt[i]<<"\t"<<tat[i]<<"\n";
				temp[i]=l++;
			}
		}
		avg(tat,wt,n);
	}
	
	void sjfp()
	{
		sort(at,n);
		for(int i=0;i<n;i++)	temp[i]=bt[i];
		int c,i,t;	c=i=t=0;
		cout<<"\n\tP.\tA.T.\tB.T.\tW.T.\tT.A.T.\n";
		while(i<n&&check(temp,n))
		{
			if(c<at[t]&&!check(temp,t))
			{
				cout<<"("<<c<<"_"<<at[t]<<")\t~\t~\t~\t~\t~\n";
				c=at[t];
			}
			else
			{
				while(t<n&&c>=at[t])	t++;
				sort(temp,t);
				if(temp[i]==0)	{	i++; }
				else if(temp[i]==1)
				{
					ct[i]=++c;
					tat[i]=ct[i]-at[i];
					wt[i]=tat[i]-bt[i];
					temp[i]--;
					cout<<"("<<c-1<<"_"<<c<<")\tP"<<p[i]<<"\t";
					cout<<at[i]<<"\t"<<bt[i]<<"\t"<<wt[i]<<"\t"<<tat[i]<<"\n";
					i=0;
				}
				else
				{
					temp[i]--;
					cout<<"("<<c<<"_"<<(++c)<<")\tP"<<p[i]<<"\t";
					cout<<at[i]<<"\t"<<bt[i]<<"\t...\t...\n";
					i=0;
				}	  
			}
		}
		avg(tat,wt,n);
	}
	
	void pbp()
	{
		cout<<"Priority-->\n";
		for(int i=0;i<n;i++)
		{	cout<<"P"<<i+1<<"=";	cin>>pr[i];	}
		sort(at,n);
		for(int i=0;i<n;i++)	temp[i]=bt[i];
		int c,i,t;	c=i=t=0;
		cout<<"\n\tP.\tPri.\tA.T.\tB.T.\tW.T.\tT.A.T.\n";
		while(i<n&&check(temp,n))
		{
			if(c<at[t]&&!check(temp,t))
			{
				cout<<"("<<c<<"_"<<at[t]<<")\t~\t~\t~\t~\t~\n";
				c=at[t];
			}
			else
			{
				while(t<n&&c>=at[t])	t++;
				sort(pr,t);
				if(temp[i]==0)	{	i++; }
				else if(temp[i]==1)
				{
					ct[i]=++c;
					tat[i]=ct[i]-at[i];
					wt[i]=tat[i]-bt[i];
					temp[i]--;
					cout<<"("<<c-1<<"_"<<c<<")\tP"<<p[i]<<"\t"<<pr[i]<<"\t";
					cout<<at[i]<<"\t"<<bt[i]<<"\t"<<wt[i]<<"\t"<<tat[i]<<"\n";
					i=0;
				}
				else
				{
					temp[i]--;
					cout<<"("<<c<<"_"<<(c+1)<<")\tP"<<p[i]<<"\t"<<pr[i]<<"\t";
					cout<<at[i]<<"\t"<<bt[i]<<"\t...\t...\n";
					i=0;
					c++;
				}	  
			}
		}
		avg(tat,wt,n);
	}
	
	void pb()
	{
		cout<<"Priority-->\n";
		for(int i=0;i<n;i++)
		{	cout<<"P"<<i+1<<"=";	cin>>pr[i];	}
		sort(at,n);
		int t=0,l=-99;
		for(int i=0;i<n;i++)	temp[i]=pr[i];
		cout<<"\n\tP.\tPri.\tA.T.\tB.T.\tW.T.\tT.A.T.\n";
		for(int i=0;i<n;i++)
		{
			if(ct[i-1]<at[i])
			{
				cout<<"("<<ct[i-1]<<"_"<<at[i]<<")\t~\t~\t~\t~\t~\t~\n";
				ct[i-1]=at[i];	i--;
			}
			else
			{
				while(t<n&&ct[i-1]>=at[t])	t++;
				sort(temp,t);
				ct[i]=ct[i-1]+bt[i];
				tat[i]=ct[i]-at[i];
				wt[i]=tat[i]-bt[i];
				cout<<"("<<ct[i-1]<<"_"<<ct[i]<<")\tP"<<p[i]<<"\t"<<pr[i]<<"\t";
				cout<<at[i]<<"\t"<<bt[i]<<"\t"<<wt[i]<<"\t"<<tat[i]<<"\n";
				temp[i]=l++;
			}
		}
		avg(tat,wt,n);
	}
	
		
	bool check(int t[],int n)
	{
		for(int i=0;i<n;i++)
			if(t[i]!=0)	return true;
		return false;	
	}
	
	void rr()
	{
		sort(at,n);
		cout<<"\nQuantum time:";	int qt;	cin>>qt;
		for(int i=0;i<n;i++)	temp[i]=bt[i];
		int c=0;
		cout<<"\n\tP.\tA.T.\tB.T.\tW.T.\tT.A.T.\n";
		while(check(temp,n))
		{
			int i=0;
			while(i<n)
			{
				if(c<at[i])
				{
					if(!check(temp,i))
					{
						cout<<"("<<c<<"_"<<at[i]<<")\t~\t~\t~\t~\t~\n";
						c=at[i]; i--;
					}
					else break;
				}
				else
				{
					int loc;
					if(temp[i]==0)	{}
					else if(qt<temp[i])
					{
						loc=c+qt;
						temp[i]=temp[i]-qt;
						cout<<"("<<c<<"_"<<loc<<")\tP"<<p[i]<<"\t";
						cout<<at[i]<<"\t"<<bt[i]<<"\t...\t...\n";
						c=loc;
					}
					else
					{
						loc=c+temp[i];
						temp[i]=0;
						tat[i]=loc-at[i];
						wt[i]=tat[i]-bt[i];
						cout<<"("<<c<<"_"<<loc<<")\tP"<<p[i]<<"\t";
						cout<<at[i]<<"\t"<<bt[i]<<"\t"<<wt[i]<<"\t"<<tat[i]<<"\n";
						c=loc;
					}	  
				}
				i++;
			}
		}
		avg(tat,wt,n);
	}
	
	void menu()
	{
		char c='r';
		do
		{
			if(c=='r')	input();
			ct[-1]=0;
			cout<<"\n1.FCFS\n2.SJF\n3.SJF(pre)\n4.PRIORITY BASE";
			cout<<"\n5.PRIORITY BASED(pre)\n6.ROUND ROBIN\n0.EXIT";
			cout<<"\nChoice:";	int ch;	cin>>ch;
			switch(ch)
			{
				case 1:fcfs();	break;
				case 2:sjf();	break;
				case 3:sjfp();	break;
				case 4:pb();	break;
				case 5:pbp();	break;
				case 6:rr();	break;
				case 0:exit(0);
				default: cout<<"\nInvalid input.";
			}
			cout<<"\nRe-enter/Continue(r/y/...):";
			cin>>c;
		}while(c=='y'||c=='r');
	}
};
	
int main()
{
	cout<<"\n***Number of process,burst time,priority must be greater than 0***";
	cout<<"\n***Arrival time must be greater than -1***\n";
	process a;
	a.menu();
	return 0;
}
