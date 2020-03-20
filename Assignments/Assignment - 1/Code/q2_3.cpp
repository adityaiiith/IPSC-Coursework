#include<bits/stdc++.h>
using namespace std;

void adjustArix(vector<vector<int> > &A, int m)
{
	int i,k;
	for(int i=0;i<m-1;i++)
	{
		float temp=(A[i+1][i])/A[i][i];
		for(int k=i+1;k<m;k++)
		{
			A[i+1][k]=(A[i+1][k])-temp*A[i][k];
		}
		A[i+1][i]=temp;
	}
}

int main()
{
	int m;
	cin>>m;
	vector<vector<int> > A(m,vector<int>(m,0));
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<m;j++)
			cin>>A[i][j];
	}
	adjustArix(A,m);
	
	cout<<"Adjusted Format is : "<<endl;
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<m;j++)
		cout<<A[i][j]<<" ";
                cout<<endl;
	}
return 0;
}