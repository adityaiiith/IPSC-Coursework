#include<bits/stdc++.h>
#define maxval 10
using namespace std;


int pos(vector <int> &v,int val)
{
	for(int i = 0 ; i < v.size() ; i++)
	{
		if(v[i] == val)
			return i;
	}
	return -1;
}

int main()
{
	int m,n,p,i,j,k,val;
	cout<<"Enter dim of Matrix A and B(m,n,p) : ";
	cin>>m>>n>>p;
	vector<int> ra,ca,va,rb,cb,vb,rc,cc,vc;//arrays to store row,col and values at respective row and col.

	for(i = 0 ; i < m ; i++)
	{
		for(j = 0 ; j < n ; j++)
		{
			val = rand() % maxval + 1;
			if(val)
			{
				ra.push_back(i);
				ca.push_back(j);
				va.push_back(val);
			}
		}
	}
	
	cout<<"Matrix A : "<<endl;
	int size_va = va.size();
	for(i = 0 ; i < size_va ; i++)
		cout<<va[i]<<" ";

	for(i = 0 ; i < n ; i++)
	{
		for(j = 0 ; j < p ; j++)
		{
			val = rand() % maxval + 1;
			if(val)
			{
				rb.push_back(i);
				cb.push_back(j);
				vb.push_back(val);
			}
		}
	}

	cout<<endl<<"Matrix B : "<<endl;
	int size_vb = vb.size();
	for(i = 0 ; i < size_vb ; i++)
		cout<<vb[i]<<" ";
	cout<<endl;
	

	int result = 0,a=0,b=0,w,x,y,z;
	for(i = 0 ; i < m ; i++)
	{
		for(j = 0 ; j < p; j++)
		{
			result = 0;
			for(k = 0 ; k < n ; k++)
			{
				a = 0;
				b = 0;
				w = pos(ra,i);
				x = pos(ca,k);
				y = pos(rb,k);
				z = pos(cb,j); 
				cout<<w<<" "<<x<<" "<<y<<" "<<z<<endl;
				if(w != -1 && x != -1 && w == x)
					a = va[w];
				if(y != -1 && z != -1 && y == z)
					b = vb[y];
				result += (a*b);
				cout<<result<<endl;
			}
			if(result)
			{
				rc.push_back(i);
				cc.push_back(j);
				vc.push_back(result);
			}	
		}
	}
	for(i=0;i<m;i++)
    {
    	for(j=0;j<p;j++)
    	{
    		int i1,i2;
    		i1 = pos(rc,i);
    		i2 = pos(cc,j);
    		if(i1 != -1 && i2 != -1 && i1 == i2)
    			cout<<vc[i1]<<" ";
    		else
    			cout<<0<<" ";
    	}
    	cout<<endl;
    }
	
	return 0;
}
