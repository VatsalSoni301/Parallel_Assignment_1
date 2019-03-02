#include<bits/stdc++.h>
using namespace std;

int maximumVal = 100;

int findIndex(vector <int> vec,int key)
{
	for(int i=0;i<vec.size();i++)
	{
		if(vec[i] == key)
			return i;
	}
	return -1;
}

int main()
{
    int m,n,p,temp;
    cout<<"Enter dimensions for matrix A m*n: "<<endl;
    cin>>m>>n;
    // cout<<endl<<"Enter the matrix A:"<<endl;
    vector<int> row_a,col_a,val_a,row_b,col_b,val_b;
    int i,j,k;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
        	// cout<<"Enter element at position "<<i<<","<<j<<":";
            // cin>>temp;
            temp = rand() % maximumVal + 1;
            if(temp != 0)
            {
                    row_a.push_back(i);
                    col_a.push_back(j);
                    val_a.push_back(temp);
            }
        }
    }
    cout<<endl<<"Matrix A"<<endl;
    for(auto i:val_a)
    {
        cout<<i<<" ";
    }
    cout<<"Enter dimensions for matrix B n*p: "<<endl;
    cout<<"Enter p:"<<endl;
    cin>>p;
    // cout<<endl<<"Enter the matrix B:"<<endl;
    for(i=0;i<n;i++)
    {
        for(j=0;j<p;j++)
        {
        	// cout<<"Enter element at position "<<i<<","<<j<<":";
            // cin>>temp;
            temp = rand() % maximumVal + 1;
            if(temp != 0)
            {
                    row_b.push_back(i);
                    col_b.push_back(j);
                    val_b.push_back(temp);
            }
        }
    }
    cout<<endl<<"Matrix B"<<endl;
    for(auto i:val_b)
    {
        cout<<i<<" ";
    }
    vector<int> row_c,col_c,val_c;

    for(i=0;i<m;i++)
    {
    	for(j=0;j<p;j++)
    	{
    		int res = 0;
    		for(k=0;k<n;k++)
    		{
    			int aik=0,bkj=0;
    			int i1,i2,i3,i4;
    			i1 = findIndex(row_a,i);
    			i2 = findIndex(col_a,k);
    			i3 = findIndex(row_b,k);
    			i4 = findIndex(col_b,j);
    			if(i1 != -1 && i2 != -1 && i1 == i2)
    				aik = val_a[i1];
    			if(i3 != -1 && i4 != -1 && i3 == i4)
    				bkj = val_b[i3];
    			res += (aik*bkj);
    		}
    		if(res!=0)
    		{
    			row_c.push_back(i);
    			col_c.push_back(j);
    			val_c.push_back(res);
    		}
    	}
    }
    
    for(i=0;i<m;i++)
    {
    	for(j=0;j<p;j++)
    	{
    		int i1,i2;
    		i1 = findIndex(row_c,i);
    		i2 = findIndex(col_c,j);
    		if(i1 != -1 && i2 != -1 && i1 == i2)
    			cout<<val_c[i1]<<" ";
    		else
    			cout<<0<<" ";
    	}
    	cout<<endl;
    }
    return 0;
}
