#include<bits/stdc++.h>
using namespace std;

int maximumVal = 100;

int main()
{
	int n;
	cout<<"enter the dimension of the matrix n*n: ";
	cin>>n;
	double A[n][n],Acopy[n][n];
	double B[n];
	int i,j,k;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			A[i][j] = rand() % maximumVal + 1;
			Acopy[i][j]=A[i][j];
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
	for(i=0;i<n;i++)
	{
		B[i] = rand() % maximumVal + 1;
	}

	cout<<endl<<endl<<"vector B:"<<endl<<endl;
	for(i=0;i<n;i++)
		cout<<B[i]<<endl;

	// Compute the LU Factorization
	for(k=0;k<n-1;k++)
	{
		for(i=k+1;i<n;i++)
		{
			A[i][k] /= A[k][k];
		}
		for(i=k+1;i<n;i++)
		{
			for(j=k+1;j<n;j++)
			{
				A[i][j] -= A[i][k]*A[k][j];
			}
		}
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

	double t[n];
	t[0]=B[0]/L[0][0];
	for(i=1;i<n;i++)
	{
		double temp=B[i];
		// cout<<"temp="<<temp<<"   ";
		for(j=0;j<i;j++)
		{
			temp = temp  - L[i][j]*t[j];
			
		}
		t[i] = temp/L[i][i];
		// cout<<t[i]<<" ";
	}

	double x[n];

	if(t[n-1]==0)
		x[n-1]=0;
	else
		x[n-1]=t[n-1]/U[n-1][n-1];

	for(i=n-2;i>=0;i--)
	{
		double temp=t[i];
		for(j=n-1;j>i;j--)
		{
			temp = temp  - U[i][j]*x[j];
		}
		x[i] = temp/U[i][i];
	}

	cout<<endl<<"vector t:"<<endl<<endl;
	for(i=0;i<n;i++)
		cout<<t[i]<<endl;

	cout<<endl<<"vector x:"<<endl<<endl;
	for(i=0;i<n;i++)
		cout<<x[i]<<endl;

	// compute ax-b
	double C[n][1];
	for(i=0;i<n;i++)
	{
		for(j=0;j<1;j++)
			C[i][j]=0;
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<1;j++)
		{
			for(k=0;k<n;k++)
			{
				C[i][j]+=Acopy[i][k]*x[k];
			}
		}
	}
	cout<<endl<<"print ax-b vector"<<endl<<endl;
	for(i=0;i<n;i++)
	{
		C[i][0] = abs(C[i][0]-B[i]);
		cout<<C[i][0]<<endl;
	}

	return 0;
}