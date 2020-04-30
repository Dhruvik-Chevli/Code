<!-- prettier-ignore -->
#include 
using namespace std;
int main()
{
    int t;
	cin>>t;
	int cas=1;
	while(t!=0)
	{
		int n;
		cin>>n;
		int s[n],e[n];
		for(int i=0;i<n;i++)
		{
			cin>>s[i]>>e[i];
		}
		int diff1[n],diff2[n-1];
		vector< pair <int,int> > vect; 
		for (int i=0; i<n; i++) 
        vect.push_back( make_pair(s[i],e[i]) ); 
        sort(vect.begin(), vect.end()); 
        for(int i=0;i<n;i++)
            diff1[i]=vect[i].second-vect[i].first;
        for(int i=0;i<n-1;i++)
            diff2[i]=vect[i+1].first-vect[i].first;
        char str[n];str[0]='C';
        int flag=0,p=1;
        int timec=diff1[0],timej=0;
        for(int i=0;i<n-1;i++)
        {
            timec-=diff2[i];
         	timej-=diff2[i];
         	if(timec<=0)
         	{
         		timec+=diff1[i+1];
         		str[p]='C';
         	 	p++;
			}
			else if(timec>0&&timej<0)
			{
				timej+=diff1[i+1];
         	    str[p]='J';
         	 	p++;
			}
			else if(timec>0&&timej>=0)
			{
				flag=1;
			 	break;
			}
		}
		vector< pair <int,int> > vect2; 
		for (int i=0; i<n; i++) 
        vect2.push_back( make_pair(vect[i].first,str[i]) );
		cout<<"Case #"<<cas<<": ";
		if(flag==1)
		    cout<<"IMPOSSIBLE";
		else
		    for(int i=0;i<n;i++)
		    {
		  	    for(int j=0;j<n;j++)
		  	    {
		  		    if(vect[i].first==vect2[j].first)
		  		    {
		  			    cout<<vect2[j].second;
				    }
			    }
		    }
		cout<<endl;
		cas++;
        t--;
	}
}