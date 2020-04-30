#include <iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<queue>
#include<set>
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
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,k;
        cin>>n>>k;
        vector<ll>li(n);
        //ll y;
        unordered_map<ll,ll>m;
        FOR(i,0,n)
        {
            cin>>li[i];
        }
        queue<ll>q;
        ll i=0;
        ll max=0;
        ll f=0;

        while(i<n)
        {
            //cout<<"$"<<endl;
            while(m.size()<=k-1)
            {
                /*for(auto x:m)
                {
                    cout<< x<<" ";
                }
                cout<<endl;*/
                cout<<li[i]<<" "<<m.size()<<" "<<max<<endl;
                if(m.find(li[i])==m.end())
                {
                    cout<<"&"<<endl;
                    if(m.size()+1!=k)
                    {
                        m[li[i]]=1;
                        q.push(li[i]);
                        if(q.size()>max)
                        {
                            max=q.size();
                        }
                        i+=1;
                    }
                    else
                    {
                        m[li[i]]=1;
                        i+=1;
                        q.push(li[i]);
                        while(m.size()>k-1)
                        {
                            cout<<"*"<<endl;
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
                            cout<<"("<<endl;
                        }
                    }
                    if(i==n)
                    {
                        f=1;
                        break;
                    }
                    
                }
                else if(m.count(li[i])!=0)
                {
                    cout<<"^"<<endl;
                    q.push(li[i]);
                    if(q.size()>max)
                    {
                        max=q.size();
                    }
                    i+=1;
                    m[li[i]]+=1;
                    if(i==n)
                    {
                        f=1;
                        break;
                    }
                }
                if(f)
                    break;
            }
        }
    cout<<max<<endl;  
    }
    return 0;
}