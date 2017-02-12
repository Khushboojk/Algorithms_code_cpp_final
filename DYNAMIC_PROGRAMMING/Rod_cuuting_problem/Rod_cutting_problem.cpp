#include <iostream>
using namespace std;
 
int main() {
 
	// price[i]  store price of rod length i inch.
	int n;
	cin>>n; 
	int price[n+1];
	for(int i=0; i<=n; i++)
	{
		cin>>price[i];
	}
 
	int length;  // determine optimal revenue corresponding to length of rod = length
 
	cin>>length;
	int revenue[length+1];   // revenue[i] store optimal revenue corresponding to length i
	int solution[length+1];  //  solution[i] store optimal first piece size of rod of length i
	revenue[0]=0;
	revenue[1]=price[1];
	solution[0]=0;
	solution[1]=1;
 
	// calculation of optimal revenue and optimal first piece size
	for(int j=2; j<=length; j++)
	{
		int max=price[j];
		int ls=j;
		for(int i=1; i<=j/2; i++)
		{
			int ans=revenue[i]+revenue[j-i];
			if(ans>max)
			{
				max=ans;
				ls=i;
			}
 
		}
		revenue[j]=max;
		solution[j]=ls;
 
	}
	// print revenue corresponding to  rod of  size=0 to size=length
	for(int i=0; i<=length; i++)
	{
		cout<<revenue[i]<<" ";
 
	}
	cout<<endl;
	// print size of first optimal piece of rod of size =0 to size=length
	for(int i=0; i<=length; i++)
	{
 
		cout<<solution[i]<<" ";
 
	}
	cout<<endl;
	// print  all optimal piece of rod of size = length;
	int count =length;
	while(count>0)
	{
		cout<<solution[count]<<" ";
		count= count - solution[count];
	}
 
 
	// your code goes here
	return 0;
}