//<!-- prettier-ignore -->
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>
using namespace std;
typedef long long int ll;
#define EPS 1e-9
#define pb push_back
#define FOR(i, a, b) for (ll i = a; i < b; i++)
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
ll solve(ll n, vector<ll> &v)
{
    ll sum = 0;
    ll l2 = -1;
    ll sl2 = -1;
    ll l4 = -1;
    FOR(i, 0, n)
    {
        if (v[i] % 4 == 0)
        {
            l4 = i;
        }
        else if (v[i] % 4 == 2)
        {
            if (l2 == -1 and sl2 == -1 and l4 == -1)
            {
                sum += 1;
                sum += i;
                l2 = i;
            }
            else if (sl2 == -1 and l2 == -1)
            {
                sum += 1;
                sum += (i - l4 - 1);
                l2 = i;
            }
            else if (l2 != -1 and sl2 == -1 and l4 == -1)
            {
                sum += 1;
                sum += (i - l2 - 1);
                sl2 = l2;
                l2 = i;
            }
            else if (l2 != -1 and sl2 == -1 and l4 != -1)
            {
                ll pivot = (l4 > l2) ? l4 : l2;
                sum += 1;
                sum += (i - pivot - 1);
                sl2 = l2;
                l2 = i;
            }
            else if (l2 != -1 and sl2 != -1)
            {
                ll pivot = (l4 > l2) ? l4 : l2;
                sum += 1;
                sum += (i - pivot - 1);
                sl2 = l2;
                l2 = i;
            }
            else
            {
                ll pivot = (l4 > l2) ? l4 : l2;
                sum += 1;
                sum += (i - pivot - 1);
                sl2 = l2;
                l2 = i;
            }
        }
        else
        {
            if (l2 == -1 and sl2 == -1 and l4 == -1)
            {
                continue;
            }
            else if (l2 == -1 and sl2 == -1 and l4 != -1)
            {
                continue;
            }
            else if (l2 != -1 and sl2 == -1 and l4 == -1)
            {
                sum += (l2 + 1);
            }
            else if (l2 != -1 and sl2 == -1 and l4 != -1)
            {
                if (l4 > l2)
                {
                    continue;
                }
                else
                {
                    sum += (l2 - l4);
                }
            }
            else
            {
                if (l4 > l2 and l4 > sl2)
                {
                    continue;
                }
                else if (l2 > l4 and l2 > sl2)
                {
                    ll pivot = (l4 > sl2) ? l4 : sl2;
                    sum += (l2 - pivot);
                }
            }
        }
    }
    return (n * (n + 1) / 2) - sum;
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vector<ll> v(n, 0);
        FOR(i, 0, n)
        {
            cin >> v[i];
        }
        cout << solve(n, v) << endl;
    }
    return 0;
}