#include<bits/stdc++.h>
using namespace std;

int main()
{
	int nz;
	cout<<"Enter number of non-zero values for Matrix A";
	cin>>nz;
	int i,j,x,k;
	map<pair<int,int> , int> A;
	map<pair<int,int> , int> B;
	
	int val_indices[nz];
	int col_indices[nz];
	vector<int> row_indices;

	int maxA,maxB,maxDim;

	cout<<endl<<"Enter values for matrix A"<<endl;
	for(i=0;i<nz;i++)
	{
		cout<<"Enter element for "<<i+1<< " position";
		cin>>val_indices[i];
	}	

	cout<<endl<<"Enter column for matrix A"<<endl;
	for(i=0;i<nz;i++)
	{
		cout<<"Enter column for "<<i+1<< " position";
		cin>>col_indices[i];
	}	

	int nz_rows;
	cout<<endl<<"Enter number of non-zero rows in matrix A"<<endl;
	cin>>nz_rows;
	vector<int> v(nz_rows);
	
	cout<<endl<<"Enter row pointers"<<endl;
	for(int i=0;i<nz_rows;i++)
	{
		cout<<endl<<"Enter row pointer for position "<<i+1<<endl;
		cin>>v[i];
	}	

	if(v[nz_rows - 1] != nz + 1)
	{
		cout<<"Enter valid row pointers";
		return 0;
	}	

	int row = 1;
	
	for(i=1 ; i<nz_rows ; i++)
	{
		x = 0;	
		while(x < v[i] - v[i - 1])
		{
			row_indices.push_back(row);
			x++;
		}
		row++;	
	}

	maxA=row-1;
	
	for(i=0 ; i<nz; i++)
	{
		row = row_indices[i];
		int col = col_indices[i];
		maxA = max(col,maxA);
		A[{row,col}] = val_indices[i];
	}	

	cout<<endl<<"Matrix A"<<endl;	
	cout<<endl<<"row "<<"col "<<"val"<<endl;
	map<pair<int,int> , int> ::iterator it = A.begin();
	for(;it!=A.end(); it++)
	{
		cout<<it->first.first<<" "<<it->first.second<<"	"<<it->second<<endl;
	}	

	vector<int> row_indices1;	
	
	cout<<"Enter number of non-zero values for Matrix B";
	cin>>nz;

	cout<<endl<<"Enter values for matrix B"<<endl;
	for(i=0;i<nz;i++)
	{
		cout<<i+1<<":";
		cin>>val_indices[i];
	}	

	cout<<endl<<"Enter column for matrix B"<<endl;
	for(i=0;i<nz;i++)
	{
		cout<<i+1<<":";
		cin>>col_indices[i];
	}	

	cout<<endl<<"Enter number of non-zero rows in matrix B"<<endl;
	cin>>nz_rows;
	int v1[nz_rows];
	cout<<endl<<"Enter row pointers"<<endl;
	for(i=0;i<nz_rows;i++)
	{
		cout<<i+1<<":";
		cin>>v1[i];
	}	

	if(v1[nz_rows - 1] != nz + 1)
	{
		cout<<"Enter valid row pointers";
		return 1;
	}	

	row = 1;
	
	for(i=1 ; i<nz_rows ; i++)
	{
		x = 0;	
		while(x < v[i] - v[i - 1])
		{
			row_indices1.push_back(row);
			x++;
		}
		row++;	
	}

	for(i=0 ; i<nz; i++)
	{
		row = row_indices1[i];
		int col = col_indices[i];
		maxB = max(max(row,col),maxB);
		B[{row,col}] = val_indices[i];
	}		

	cout<<endl<<"Matrix B"<<endl;
	cout<<endl<<"row "<<"col "<<"val"<<endl;
	it = B.begin();
	for(;it!=B.end(); it++)
	{
		cout<<it->first.first<<" "<<it->first.second<<"	"<<it->second<<endl;
	}	
	maxDim = max(maxA, maxB);


	vector<int> row_indicess;
	vector<int> col_indicess;
	vector<int> val_indicess;

	cout<<endl<<"Multiplication Matrix"<<endl;
    for(i=1; i<=maxDim; i++)
    {
        for(j=1; j<=maxDim; j++)
        {
            x = 0;
            
            for(k=1; k<=maxDim; k++)
            {
                pair <int,int> valA = make_pair(i,k);
                pair <int,int> valB = make_pair(k,j);
                
                if(A.find(valA) != A.end() && B.find(valB) != B.end())
                    x = x + A[valA]*B[valB];
            }
            if(x != 0)
            {
                row_indicess.push_back(i);
                col_indicess.push_back(j);
                val_indicess.push_back(x);
            }
            cout<<x<<"  ";
        }
        cout<<endl;
    }

    cout<<endl<<"Row Indices of C = A * B"<<endl;
    for(i=0;i<row_indicess.size();i++)
   		cout<<row_indicess[i]<<" ";
   	cout<<endl;		

   	cout<<endl<<"Column Indices of C = A * B"<<endl;
    for(i=0;i<col_indicess.size();i++)
   		cout<<col_indicess[i]<<" ";
   	cout<<endl;	

   	cout<<endl<<"Value Indices of C = A * B"<<endl;
    for(i=0;i<val_indicess.size();i++)
   		cout<<val_indicess[i]<<" ";
   	cout<<endl;		


    return 0;
}
