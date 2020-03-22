#include<bits/stdc++.h>
using namespace std;

void findLU(vector<vector<double>> &A, int n)
{
	int i,j,k;
	vector<vector<double>>L(n,vector<double>(n));
	vector<vector<double>>U(n,vector<double>(n));
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
				U[i][j] = A[i][j];
				L[i][j] = 0;
			}
		}
	}

	cout<<endl<<endl<<"Matrix L:"<<endl<<endl;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			cout<<L[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl<<endl<<"Matrix U:"<<endl<<endl;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			cout<<U[i][j]<<" ";
		}
		cout<<endl;
	}
}

void computeLU(vector<vector<double>> &A, int n)
{
	int i,j,k;
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
	cout<<endl<<endl<<"Matrix A after LU factorization:"<<endl;

	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			cout<<A[i][j]<<" ";
		}
		cout<<endl;
	}
}
int main()
{
	int n,i,j,k;
	cout<<"Enter the dimension of the matrix n*n: ";
	cin>>n;
	vector<vector<double>>A(n,vector<double>(n));
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			A[i][j] = rand() % 100 + 1;
		}
	}

	cout<<endl<<endl<<"Matrix A:"<<endl;

	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			cout<<A[i][j]<<" ";
		}
		cout<<endl;
	}

	computeLU(A,n);
	findLU(A,n);
	return 0;
}