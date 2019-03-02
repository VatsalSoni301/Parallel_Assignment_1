#include<bits/stdc++.h>
using namespace std;

int maximumVal = 100;

int main()
{
	int p,q,r;
	cout<<"Enter the dimension of the two matrices p*q and q*r: "<<endl;
	cin>>p;
	cin>>q;
	cin>>r;
	
	int A[p][q],B[q][r];
	int i,j,k;
	
	for(i=0;i<p;i++)
	{
		for(j=0;j<q;j++)
		{
			A[i][j] = rand() % maximumVal + 1;
		}
	}
	
	for(i=0;i<q;i++)
	{
		for(j=0;j<r;j++)
		{
			B[i][j] = rand() % maximumVal + 1;
		}
	}
	cout<<endl<<"Matrix A:"<<endl<<endl;
	for(i=0;i<p;i++)
	{
		for(j=0;j<q;j++)
		{
			cout<<A[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl<<"Matrix B:"<<endl<<endl;
	for(i=0;i<q;i++)
	{
		for(j=0;j<r;j++)
		{
			cout<<B[i][j]<<" ";
		}
		cout<<endl;
	}
	
	int C[p][r];
	
	for(i=0;i<p;i++)
	{
		for(j=0;j<r;j++)
		{
			C[i][j] = 0;
		}
	}
	for(i=0;i<p;i++)
	{
		for(j=0;j<r;j++)
		{
			for(k=0;k<q;k++)
			{
				C[i][j] += A[i][k]*B[k][j];
			}
		}
	}
	
	cout<<endl<<"Matrix C = A * B:"<<endl<<endl;
	for(i=0;i<p;i++)
	{
		for(j=0;j<r;j++)
		{
			cout<<C[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}