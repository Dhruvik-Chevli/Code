#include<iostream>
#include<vector>
#include<utility>
#include<set>
#include<limits>
#include<algorithm>
#include<climits>
#define ll long long int
#define FOR(i,a,b) for(ll i=a;i<b;i++)
using namespace std;
int main() 
{
    freopen("input1.txt","r",stdin);
    freopen("output1.txt","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int>sp(n+1,0);
        // cout<<sp.size()<<"\n";
        for(int i=1;i<=n;i++)
        {
            cin>>sp[i];
        }
        // FOR(i,0,sp.size()+2)
        // {
        //     cout<<sp[i]<<" ";
        // }
        // cout<<"\n";
        ll mi=INT_MAX;
        ll ma=INT_MIN;
        for(int i=1;i<=n;i++)
        {
            vector<bool>affected(n+1,false);
            affected[i]=true;
            // cout<<i<<"\n";
            vector<ll>pos(n+1,0);
            FOR(j,0,n+1)
            {
                pos[j]=j;
            }
            // FOR(j,0,n+1)
            // {
            //     cout<<pos[j]<<" ";
            // }
            // cout<<"\n";
            FOR(j,1,10000)
            {
                FOR(k,1,n+1)
                    pos[k]+=sp[k];
                // FOR(k,0,n+1)
                // {
                //     cout<<pos[k]<<" ";
                // }
                // cout<<"\n";
                FOR(x,0,n+1)
                {
                    FOR(k,1,n+1)
                    {
                        if(!affected[k])
                        {
                            FOR(l,1,n+1)
                            {
                                if(pos[k]==pos[l] and affected[l]==true)
                                {
                                    affected[k]=true;
                                    break;
                                }
                            }
                        }
                    }
                }   
                // FOR(k,1,n+1)
                // {
                //     if(affected[k])
                //     {
                //         FOR(l,1,n+1)
                //         {
                //             if(pos[k]==pos[l])
                //             {
                //                 affected[l]=true;
                //             }
                //         }
                //     }
                // }
            }
            ll count=0;
            FOR(j,0,n+1)
            {
                if(affected[j])
                {
                    count+=1;
                }
            }
            if(count>ma)
            {
                ma=count;
            }
            if(count<mi)
            {
                mi=count;
            }
        }
        cout<<sp[1]<<" "<<sp[2]<<" "<<sp[3]<<"\n";
        cout<<mi<<" "<<ma<<"\n";
    }
}