#include<iostream>
#include<stdlib.h>
using namespace std;
void reset(int [],int);
int swap(int,int &,int &);
int reverse(int,int &,int &);
int stk[100];
int main()
{

	int n,i,flag=0,res_sw,res_rev,ind1,ind2;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>stk[i];
	}
	for(i=0;i<n-1;i++)
	{
		if(stk[i]>stk[i+1])
		{
			flag=1;
			break;
		}
	}
	if(flag==0)
	{
		cout<<"yes";
		exit(0);
	}
	res_sw=swap(n,ind1,ind2);
	if(res_sw!=1)
    	{
        	res_rev=reverse(n,ind1,ind2);
    	}
	if(res_sw==1)
	{
		cout<<"yes";
		cout<<endl;
		cout<<"swap "<<ind1<<" "<<ind2;
	}
	else if(res_rev==1)
	{
		cout<<"yes";
		cout<<endl;
		cout<<"reverse "<<ind1<<" "<<ind2;
	}
	else
	{
		cout<<"no";
	}
	return 0;
}
int swap(int size,int &ind1,int &ind2)
{
	int i,j,flag=0,a[100],k,temp;
	reset(a,size);
	for(i=0;i<size;i++)
	{
		flag=0;
		for(j=i+1;j<size;j++)
		{
			flag=0;
			if(a[j]<a[i])
			{
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
				for(k=0;k<size;k++)
				{
					if(a[k]>a[k+1])
					{
						flag=1;
						break;
					}
				}
				if(flag==0)
				{
				    ind1=i+1;
				    ind2=j+1;
					return 1;
				}
			}
			reset(a,size);
		}
		reset(a,size);
	}
	return -1;
}
int reverse(int size,int &ind1,int &ind2)
{
	int i,j,a[100],k,temp,l,flag=0;
	reset(a,size);
	for(i=0;i<size;i++)
	{
		flag=0;
		for(j=i;j<size;j++)
		{
			flag=0;
			for(k=0;k<=(j-i)/2+i/2;k++)
			{
				temp=a[k+i];
				a[k+i]=a[j-k+i];
				a[j-k+i]=temp;
			}
			for(l=0;l<size-1;l++)
			{
				if(a[l]>a[l+1])
				{
					flag=1;
					break;
				}
			}
			if(flag==0)
			{
			    ind1=i+1;
			    ind2=j+i+1;
				return 1;
			}
			reset(a,size);
		}
		reset(a,size);
	}
	return -1;
}
void reset(int a[],int s)
{
	for(int i=0;i<s;i++)
	{
		a[i]=stk[i];
	}
}
