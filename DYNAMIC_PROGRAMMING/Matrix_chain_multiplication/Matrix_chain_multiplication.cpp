#include <iostream>
using namespace std;
 
 
int main() {

	// enter number of matrix to be multplied and its to be stored in order[], where order of matrix Ai  
	//	will be equal to order[i-1] x order[i]
	int n;
	cin>>n;
	int order[n+1];
	for(int i=0; i<=n; i++)
	{
		cin>>order[i];
	}

	//here optmlmltplctn[i][j] represent optimal scalar multiplication 
	//required to multiply matrices from Ai to Aj and soln[i][j] represent optimal split 
	//position between matrices from Ai to Aj
	
	int optmlmltplctn[n+1][n+1];
	int soln[n+1][n+1];
	for(int i=0; i<=n; i++)
	{
		optmlmltplctn[i][0]=0;
		optmlmltplctn[0][i]=0;
		 soln[i][0]=0;
		 soln[0][i]=0;
	}
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=i; j++)
		{
			optmlmltplctn[i][j]=0;
			soln[i][j]=0;
		}
	}

	// calculation of optimal scalar multiplication and split position

	for(int i=n-1; i>=1; i--)
	{
		for(int j=i+1; j<=n; j++)
		{
 
			optmlmltplctn[i][j]=99999999999;
			for(int k=i; k<=j-1; k++)
			{
				int min=optmlmltplctn[i][k]+optmlmltplctn[k+1][j]+order[i-1]*order[k]*order[j];
				if(min<optmlmltplctn[i][j])
				{
					optmlmltplctn[i][j]=min;
					soln[i][j]=k;
				}
			}
		}
	}

	// print optimal scalar multiplication matrix

	for(int i=0; i<=n; i++)
	{
		for(int j=0; j<=n; j++)
		{
				cout<<optmlmltplctn[i][j]<<" ";
		}
		cout<<endl;
	}

	// print split position matrix
	for(int i=0; i<=n; i++)
	{
		for(int j=0; j<=n; j++)
		{
				cout<<soln[i][j]<<" ";
		}
		cout<<endl;
	}
 
	
	return 0;
}
