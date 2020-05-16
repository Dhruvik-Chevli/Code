#include <iostream>
using namespace std;

int main() {
	// your code goes here
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	int t,n,i;
	char a;
	cin>>t;
	while(t--)
	{
	    cin>>n>>a;
	    if(n%2==0)
	    {
	        if(a=='N')
	        {
	            cout<<"Nitigya\n";
	        }
	        else
	        {
	            cout<<"Paawan\n";
	        }
	    }
	    else
	    {
	        if(a=='P')
	        {
	            cout<<"Nitigya\n";
	        }
	        else
	        {
	            cout<<"Paawan\n";
	        }
	    }
	    
	}
	return 0;
}
