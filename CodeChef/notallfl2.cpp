#include <iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<queue>
#include<unordered_map>
using namespace std;
typedef long long int ll;
#define EPS 1e-9
#define pb push_back
#define FOR(i, a, b) for(ll i = a; i < b; i++)
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
int main()
{
    //std::ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,k;
        cin>>n>>k;
        vector<ll>v(n);
        FOR(i,0,n)
        {
            cin>>v[i];
        }
        int i=0;
        unordered_map<ll,ll>m;
        queue<ll>q;
        int f=0;
        ll max=0;
        while(i<n)
        {
            //cout<<m.size()<<" "<<v[i]<<" "<<max<<endl;
            if(m.count(v[i])==0)
            {
                //cout<<"&"<<endl;
                if(m.size()+1!=k)
                {
                    //cout<<"%"<<endl;
                    m[v[i]]=1;
                    q.push(v[i]);
                    if(q.size()>max)
                        max=q.size();
                    i+=1;
                }
                else
                {
                    //cout<<"#"<<endl;
                    m[v[i]]=1;
                    while(m.size()>k-1)
                    {
                        //cout<<"*"<<endl;
                        ll j=q.front();
                        if(m[j]-1==0)
                        {
                            m.erase(j);
                        }
                        else
                        {
                            m[j]-=1;
                        }
                        q.pop();
                    }
                    q.push(v[i]);
                    i+=1;
                }
                
            }
            else
            {
                //cout<<"@"<<endl;
                m[v[i]]+=1;
                q.push(v[i]);
                if(q.size()>max)
                    max=q.size();
                i+=1;
            }
            
        }
        cout<<max<<endl;
    }
    return 0;
}