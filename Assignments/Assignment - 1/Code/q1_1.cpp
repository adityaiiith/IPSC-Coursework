#include<bits/stdc++.h>
using namespace std;

int main()
{
	int m,n,p,i,j,k;
	cin>>m>>n>>p;
	vector<vector<int>>a(m,vector<int>(n,0));
	vector<vector<int>>b(n,vector<int>(p,0));
	vector<vector<int>>c(m,vector<int>(p,0));

	for(i = 0 ; i < m ; i++)
	{
		for(j = 0 ; j < n ; j++)
		{
			a[i][j] = rand() % 100;
		}
	}
	
	for(i = 0 ; i < n; i ++)
	{
		for(j = 0 ; j < p ; j++)
		{
			b[i][j] = rand() % 100;
		}
	}
	
	cout<<endl<<"Matrix A : "<<endl;
	for(i = 0 ; i < m ; i++)
	{
		for( j = 0 ; j < p ; j++)
		{
			cout<<a[i][j] <<" ";
		}
		cout<<endl;
	}

	cout<<endl<<"Matrix B : "<<endl;
	for(i = 0 ; i < m ; i++)
	{
		for( j = 0 ; j < p ; j++)
		{
			cout<<b[i][j] <<" ";
		}
		cout<<endl;
	}
	
	for( i = 0 ; i < m ; i++)
	{
		for( j = 0 ; j < p ; j++)
		{
			for( k = 0 ; k < n ; k++)
			{
				c[i][j] += a[i][k] * b[k][j];
			}
		}
	}
	
	cout<<endl<<"Product of A and B is : "<<endl;

	for(i = 0 ; i < m ; i++)
	{
		for( j = 0 ; j < p ; j++)
		{
			cout<< c[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}