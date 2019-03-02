#include<bits/stdc++.h>
using namespace std;

int maximumVal = 100;

int main()
{
	int n;
	cout<<"enter the dimension of the matrix n*n: ";
	cin>>n;
	double A[n][n];
	int i,j,k;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			A[i][j] = rand() % maximumVal + 1;
		}
	}
	cout<<endl<<endl<<"matrix A:"<<endl<<endl;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			cout<<A[i][j]<<" ";
		}
		cout<<endl;
	}

	// Compute the LU Factorization
	for(k=0;k<n-1;k++)
	{
		A[k+1][k] /= A[k][k];
		
		for(j=k+1;j<n;j++)
			A[k+1][j] -= A[k+1][j]*A[k][j];
	}
	
	cout<<endl<<endl<<"matrix A after LU factorization:"<<endl<<endl;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			cout<<A[i][j]<<" ";
		}
		cout<<endl;
	}
	// Creating the L and U matrices using this!
	double L[n][n];
	double U[n][n];
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(i==j)
			{
				L[i][j] = 1;
				U[i][j] = A[i][j];
			}
			else if(i>j)
			{
				L[i][j] = A[i][j];
				U[i][j] = 0;
			}
			else
			{
				//if(i<j)
				U[i][j] = A[i][j];
				L[i][j] = 0;
			}
		}
	}
	// Printing L and U
	cout<<endl<<endl<<"matrix L:"<<endl<<endl;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			cout<<L[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl<<endl<<"matrix U:"<<endl<<endl;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			cout<<U[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}