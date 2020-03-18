#include<bits/stdc++.h>
using namespace std;

void findLU(vector<vector<double>> &A,vector<vector<double>>&L,vector<vector<double>>&U, int n)
{
	int i,j,k;

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
	int n;
	cout<<"Enter the dimension of the matrix n*n: ";
	cin>>n;
	vector<vector<double>>A(n,vector<double>(n,0));
	vector<vector<double>>Acopy(n,vector<double>(n,0));
	vector<double>B(n);
	int i,j,k;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			A[i][j] = rand() % 100 + 1;
		}
	}
	Acopy = A;
	
	cout<<endl<<endl<<"Matrix A:"<<endl<<endl;
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
		B[i] = rand() % 100 + 1;
	}

	cout<<endl<<endl<<"Vector B:"<<endl<<endl;
	
	for(i=0;i<n;i++)
		cout<<B[i]<<endl;

	vector<vector<double>>L(n,vector<double>(n,0));
	vector<vector<double>>U(n,vector<double>(n,0));
	
	computeLU(A,n);
	findLU(A,L,U,n);


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

	cout<<endl<<"Vector t:"<<endl<<endl;
	for(i=0;i<n;i++)
		cout<<t[i]<<endl;

	cout<<endl<<"Vector x:"<<endl<<endl;
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
	cout<<endl<<"Print ax-b vector"<<endl<<endl;
	for(i=0;i<n;i++)
	{
		C[i][0] = abs(C[i][0]-B[i]);
		cout<<C[i][0]<<endl;
	}

	return 0;
}