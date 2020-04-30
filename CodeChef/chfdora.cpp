#include <iostream>
#include <vector>
using namespace std;
typedef long long int ll;
#define pb push_back
int main()
{
    ll t;
    cin>>t;
    while (t--)
    {
        ll n, m;
        cin >> n >> m;
        ll k;
        vector<vector<ll> > v(n, vector<ll>(m));
        for (ll i = 0; i < n; i++)
            for (ll j = 0; j < m; j++)
            {
                cin >> k;
                v[i][j] = k;
            }
        ll ans = 0;
        ll no, s, e, w;
        for (ll i = 0; i < n; i++)
        {
            for (ll j = 0; j < m; j++)
            {
                no=i;s=i;e=j;w=j;
                while (v[no][j] == v[s][j] && v[i][w] == v[i][e])
                {
                    ans+=1;
                    if (no > 0 && s < n-1 && e < m-1 && w > 0)
                    {
                        no -= 1;
                        s += 1;
                        e += 1;
                        w -= 1;
                        //ans += 1;
                    }
                    else
                    {
                        break;
                    }
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}