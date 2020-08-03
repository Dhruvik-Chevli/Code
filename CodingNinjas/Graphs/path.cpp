#include <iostream>
#include<vector>
#include<queue>
using namespace std;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n,m;
	    cin>>n>>m;
	    vector<vector<int> >v(n,vector<int>(m,0));
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<n;j++)
	        {
	            cin>>v[i][j];
	        }
	    }
	    int x,y;
	    cin>>x>>y;
	    vector<vector<bool> >visited(n,vector<bool>(m,false));
	    queue<pair<int,pair<int,int>> >q;
	    q.push(make_pair(0,make_pair(0,0)));
	    if(x==0 and y==0)
	    {
	        cout<<0<<"\n";
	        continue;
	    }
	    visited[0][0]=true;
	    bool found=false;
	    while(!q.empty())
	    {
	        pair<int,pair<int,int> >k=q.front(); q.pop();
	        int dis = k.first;
	        int sx=k.second.first;
	        int sy=k.second.second;
	        for(int i=0;i<4;i++)
	        {
	            int cx=sx+dx[i];
	            int cy=sy+dy[i];
	            if(cx==x and cy==y)
	            {
	                found=true;
	                cout<<dis+1<<"\n";
	                break;
	            }
	            if(!visited[cx][cy] and v[cx][cy]==1)
	            {
	                visited[cx][cy]=true;
	                q.push(make_pair(dis+1,make_pair(cx,cy)));
	            }
	        }
	        if(found)
	        {
	            break;
	        }
	    }
	    if(found)
	    {
	        continue;
	    }
	    else
	    {
	        cout<<"-1\n";
	    }
	}
	return 0;
}