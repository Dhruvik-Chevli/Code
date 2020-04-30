#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> VL;
typedef vector<pair<ll, ll>> VPI;
typedef pair<ll, ll> PLL;
typedef map<ll, ll> MLL;
#define EPS 1e-9
#define pb push_back
#define FOR(i, a, b) for (ll i = a; i < b; i++)
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        string s, u;
        cin >> s;
        ll ans = 0;
        ll count = 0;
        ll n = s.length();
        FOR(i, 0, s.length() - 1)
        {
            if (s[i] == s[i + 1])
                count++;
        }
        // cout << count << "\n";
        VL l(n, 0), r(n, 0);
        FOR(i, 0, n)
        {
            if (i != 0 && i != n - 1)
            {
                if (s[i] != s[i - 1])
                {
                    l[i]++;
                }
                else
                    l[i]--;
                if (s[i] != s[i + 1])
                {
                    r[i]++;
                }
                else
                    r[i]--;
            }
            else if (i == 0 && i != n - 1)
            {
                if (s[i] != s[i + 1])
                {
                    r[i]++;
                }
                else
                    r[i]--;
            }
            else if (i == n - 1 && i != 0)
            {
                if (s[i] != s[i - 1])
                {
                    l[i]++;
                }
                else
                    l[i]--;
            }
        }
        ll temp = 0;
        FOR(i, 0, n)
        {
            ll left = n - i;
            ll right = i + 1;
            temp = temp + left * l[i] + right * r[i];
        }
        ll summation = (n * (n + 1) / 2);
        ans = summation * count + temp;
        std::cout << ans << "\n";
    }

    return 0;
}