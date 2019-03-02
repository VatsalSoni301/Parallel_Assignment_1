#include<bits/stdc++.h>
using namespace std;

int maximumVal = 10;

int main()
{

	// Assumption:-- Given input matrix is already banded matrix

	int m1,n1,p1,q1,m2,n2,p2,q2;

	// Matrix having dimension m*n
	// lower bandwidth p
	// upper bandwidth q
	cout<<"Notations:"<<endl<<"Matrix is (m*n), lower bandwidth is p and upper bandwidth is q."<<endl;
	cout<<"For matrix A:"<<endl;
	cout<<"Enter m,n,p and q: "<<endl;
	cin>>m1>>n1>>p1>>q1;
	if(p1+q1+1>m1)
	{
		cout<<"Cant fit into banded matrix";
		return 1;
	}
	cout<<"Enter the elements of matrix A:"<<endl<<endl;

	int A[m1][n1],temp;
	int i,j,k;

	for(i=0;i<m1;i++)
	{
		for(j=0;j<n1;j++)
			A[i][j]=0;
	}
	
	for(i=0;i<p1+q1+1;i++)
	{
		for(j=0;j<n1;j++)
		{
			// cout<<"Enter element "<<i<<","<<j<<":";
			temp = rand() % maximumVal + 1;
			A[i-j+q1][j] = temp;	// Banded storage scheme formula to store elements in banded matrix
		}
	}
	cout<<"For matrix B:"<<endl;
	cout<<"Enter m,n,p and q: "<<endl;
	cin>>m2>>n2>>p2>>q2;
	if(p2+q2+1>m2)
	{
		cout<<"Cant fit into banded matrix";
		return 1;
	}
	cout<<"Enter the elements of matrix B:"<<endl<<endl;
	
	int B[p2+q2+1][n2];

	for(i=0;i<m2;i++)
	{
		for(j=0;j<n2;j++)
			B[i][j]=0;
	}

	for(i=0;i<p2+q2+1;i++)
	{
		for(j=0;j<n2;j++)
		{
			// cout<<"Enter element "<<i<<","<<j<<":";
			temp = rand() % maximumVal + 1;
			B[i-j+q2][j] = temp;
		}
	}
	
	cout<<endl<<endl<<"Printing the banded storage version of matrix A:"<<endl<<endl;
	for(i=0;i<p1+q1+1;i++)
	{
		for(j=0;j<n1;j++)
		{
			cout<<A[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl<<endl<<"Printing the banded storage version of matrix B:"<<endl<<endl;
	for(i=0;i<p2+q2+1;i++)
	{
		for(j=0;j<n2;j++)
		{
			cout<<B[i][j]<<" ";
		}
		cout<<endl;
	}
	if(n1 != m2)
	{
		cout<<endl<<endl<<"Dimesion mismatch!!!"<<endl;
		cout<<"Error!!!";
		return 1;
	}
	cout<<endl<<endl<<"Multiplying both the matrices: "<<endl;
	int C[m1][n2];
	
	for(i=0;i<m1;i++)
	{
		for(j=0;j<n2;j++)
		{
			C[i][j] = 0;
		}
	}
	
	for(i=0;i<m1;i++)
	{
		for(j=0;j<m2;j++)
		{
			for(k=0;k<n1;k++)
			{
				int aik,bkj;
				if(((i-k+q1) < 0) || ((i-k+q1) >= m1))
					aik = 0;
				else
					aik = A[i-k+q1][k];
				if(((k-j+q2) < 0) || ((k-j+q2) >= n2))
					bkj = 0;
				else
					bkj = B[k-j+q2][j];

				C[i][j] += (aik*bkj);

				// if((p1+j)<i || (q1+i)<j || (p2+k)<j || (q2+k)<j)
				// 	C[i][j] = 0;
				// else 
    //             {   
    //                 // int bandindex1 = i - k + q1;
    //                 // int bandindex2 = k - j + q2;

    //                 // if(bandindex1>=0 && bandindex2>=0)
    //                 	C[i][j] += A[i][j]*B[k][j]; 
    //             }
			}
		}
	}
	
	cout<<endl<<endl<<"Final matrix is: "<<endl<<endl;
	for(i=0;i<m1;i++)
	{
		for(j=0;j<n2;j++)
		{
			cout<<C[i][j]<<"     ";
		}
		cout<<endl;
	}
	return 0;
}