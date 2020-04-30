#include<iostream>
#include<vector>
#include<string>
#define ll long long int
using namespace std;
#define FOR(i,a,b) for(ll i=a;i<b;i++)
int main()
{
    ll t;
    cin>>t;
    ll b;
    cin>>b;
    FOR(r,1,t+1)
    {
        vector<bool>dwk(b,false);
        vector<int>cur(b,0);
        int sta=0;
        int end=b-1;
        int f,l;
        int sf=-1,sl=-1;
        int df=-1,dl=-1;
        FOR(q,0,5)
        {
            cout<<sta+1<<endl<<flush;
            cin>>f;
            dwk[sta]=true;
            cur[sta]=f;
            cout<<end+1<<endl<<flush;
            cin>>l;
            dwk[end]=true;
            cur[end]=l;
            if(sf==-1 && sl==-1)
            {
                if(f==l)
                {
                    sf=sta;
                    sl=end;
                }
            }
            if(df==-1 && dl==-1)
            {
                if(f!=l)
                {
                    df=sta;
                    dl=end;
                }
            }
            sta+=1;
            end-=1;
        }
        int q=11;
        while(sta<=end)
        {
            if(q%10==1)
            {
                if(sf==-1&&sl==-1)
                {
                    cout<<df+1<<endl<<flush;
                    cin>>f;
                    if(f!=cur[df])
                    {
                        FOR(i,0,b)
                        {
                            if(dwk[i]==true)
                            {
                                if(cur[i]==1)
                                {
                                    cur[i]=0;
                                }
                                else
                                {
                                    cur[i]=1;
                                }
                            }
                        }
                    }
                    cout<<df+1<<endl<<flush;
                    cin>>f;
                    q+=2;
                }
                else if(df==-1 and dl==-1)
                {
                    cout<<sf+1<<endl<<flush;
                    cin>>f;
                    if(f!=cur[sf])
                    {
                        FOR(i,0,b)
                        {
                            if(dwk[i]==true)
                            {
                                if(cur[i]==0)
                                {
                                    cur[i]=1;
                                }
                                else
                                {
                                    cur[i]=0;
                                }
                            }
                        }
                    }
                    cout<<sf+1<<endl<<flush;
                    cin>>f;
                    q+=2;
                }
                else
                {
                    cout<<sf+1<<endl<<flush;
                    cin>>f;
                    cout<<df+1<<endl<<flush;
                    cin>>l;
                    if(cur[sf]==f and cur[df]!=l)
                    {
                        ll tstart=0,tend=b-1;
                        while(tstart<=tend)
                        {
                            swap(cur[tstart],cur[tend]);
                            tstart+=1;
                            tend-=1;
                        }
                    }
                    else if(cur[sf]!=f and cur[df]==l)
                    {
                        ll tstart=0,tend=b-1;
                        while(tstart<=tend)
                        {
                            swap(cur[tstart],cur[tend]);
                            tstart+=1;
                            tend-=1;
                        }
                        FOR(i,0,b)
                        {
                            if(cur[i]==0)
                            {
                                cur[i]=1;
                            }
                            else
                            {
                                cur[i]=0;
                            }
                            
                        }
                    }
                    else if(cur[sf]!=f and cur[df]!=l)
                    {
                        FOR(i,0,b)
                        {
                            if(cur[i]==0)
                            {
                                cur[i]=1;
                            }
                            else
                            {
                                cur[i]=0;
                            }
                        }
                    }
                    q+=2;  
                }  
            }
            else
            {
                cout<<sta+1<<endl<<flush;
                cin>>f;
                dwk[sta]=true;
                cur[sta]=f;
                cout<<end+1<<endl<<flush;
                cin>>l;
                dwk[end]=true;
                cur[end]=l;
                if(sf==-1 && sl==-1)
                {
                    if(f==l)
                    {
                        sf=sta;
                        sl=end;
                    }
                }
                if(df==-1 && dl==-1)
                {
                    if(f!=l)
                    {
                        df=sta;
                        dl=end;
                    }
                }
                sta+=1;
                end-=1;
                q+=2; 
            }
        }
        FOR(i,0,b)
        {
            cout<<cur[i]<<flush;
        }
        cout<<endl<<flush;
        char a;
        cin>>a;
        if(a=='N')
        {
            return 0;
        }
    }
    
    return 0;
}