#include <iostream>
#include<vector>
#include<unordered_map>
#include<set>
#include<algorithm>
#include<utility>
using namespace std;
typedef long long ll;
typedef vector<ll> VL;
//typedef vector<pair<ll, ll> > VPI;
typedef pair<ll, ll> PLL;
//typedef map<ll, ll> MLL;
#define EPS 1e-9
#define pb push_back
#define FOR(i, a, b) for (ll i = a; i < b; i++)
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007

vector<vector<ll> > fact(100001);
struct primeFactorization
{
    ll countOfPf, primeFactor;
};
vector<ll> generateDivisors(ll curIndex, ll curDivisor, vector<primeFactorization> &arr)
{
    vector<ll> fac;
    if (curIndex == arr.size())
    {
        fac.pb(curDivisor);
    }
    else
    {
        for (ll i = 0; i <= arr[curIndex].countOfPf; ++i)
        {
            VL temp = generateDivisors(curIndex + 1, curDivisor, arr);
            fac.insert(fac.end(), temp.begin(), temp.end());
            curDivisor *= arr[curIndex].primeFactor;
        }
    }
    return fac;
}

vector<ll> findDivisors(ll n, ll sieve[])
{
    vector<primeFactorization> arr;
    // Finding prime factorization of n
    /*for (ll i = 2; i * i <= n; ++i)
    {
        if (n % i == 0)
        {
            ll count = 0;
            while (n % i == 0)
            {
                n /= i;
                count += 1;
            }

            // For every prime factor we are storing
            // count of it's occurenceand itself.
            arr.push_back({count, i});
        }
    }*/
    ll t, count;
    while (n != 1)
    {
        t = sieve[n];
        n /= t;
        count = 1;
        while (sieve[n] == t)
        {
            count += 1;
            n /= t;
        }
        primeFactorization o=primeFactorization();
        o.countOfPf=count;
        o.primeFactor=t;

        arr.push_back(o);
    }

    // If n is prime
    if (n > 1)
    {
        primeFactorization o=primeFactorization();
        o.countOfPf=1;
        o.primeFactor=n*n;
        arr.push_back(o);
    }

    ll curIndex = 0, curDivisor = 1;

    // Generate all the divisors
    return generateDivisors(curIndex, curDivisor, arr);
}
ll y3[100001];
ll x1[100001];
ll x2[100001];
ll y2[100001];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    ll sieve[100001];

    FOR(i, 0, 100001)
    {
        sieve[i] = i;
    }
    sieve[0] = 1;
    FOR(i, 2, 100001)
    {
        if (sieve[i] == i)
        {
            for (ll j = i * i; j < 100001; j += i)
            {
                if (sieve[j] == j)
                    sieve[j] = i;
            }
        }
    }

    cin >> t;
    VL temp;

    while (t--)
    {
        unordered_map<ll, ll> xcal, ycal;
        FOR(i, 0, 100001)
        {
            x1[i] = 0;
            x2[i] = 0;
            y2[i] = 0;
            y3[i] = 0;
        }
        ll n, m;
        cin >> n >> m;
        ll k;
        FOR(i, 0, n)
        {
            cin >> k;
            if (k >= 0)
                x1[k] = 1;
            else
                x2[-1 * k] = 1;
        }
        FOR(i, 0, m)
        {
            cin >> k;
            if (k >= 0)
                y3[k] = 1;
            else
            {
                y2[k * -1] = 1;
            }
        }
        ll counts = 0;
        for (ll f = 1; f < 100001; f++)
        {
            if (!x1[f])
            {
                continue;
            }
            ll u = f;

            if (xcal.count(u) > 0)
            {
                counts += xcal[u];
                continue;
            }
            //VL temp;
            if (fact[u].size() != 0)
            {
                temp = fact[u];
            }
            else
            {
                temp = findDivisors(u, sieve); //ASFADGSDGSADGADGADGADGADGADG
                fact[u] = temp;
            }
            ll c = 0;

            for (ll i = 0; i < temp.size(); i++)
            {
                ll it = temp[i];
                if (it == 0)
                {
                    continue;
                }
                if (u * u / it > 100000 or it > 100000)
                {
                    continue;
                }
                if (y3[it] and y2[u * u / it])
                {
                    // cout<<f.first<<" "<<i<<" "<<-temp<<endl;
                    counts += 1;
                    c++;
                }
            }
            xcal[u] = c;
        }
        for (ll f = 1; f < 100001; f++)
        {
            if (!x2[f])
            {
                continue;
            }
            ll u = abs(f);

            if (xcal.count(u) > 0)
            {
                counts += xcal[u];
                continue;
            }
            if (fact[u].size() != 0)
            {
                temp = fact[u];
            }
            else
            {
                temp = findDivisors(u, sieve); //ASFADGSDGSADGADGADGADGADGADG
                fact[u] = temp;
            }
            ll c = 0;

            for (ll i = 0; i < temp.size(); i++)
            {
                ll it = temp[i];
                if (it == 0)
                {
                    continue;
                }
                if (u * u / it > 100000 or it > 100000)
                {
                    continue;
                }
                if (y3[it] and y2[u * u / it])
                {
                    // cout<<f.first<<" "<<i<<" "<<-temp<<endl;
                    counts += 1;
                    c++;
                }
            }
            xcal[u] = c;
        }
        for (ll f = 1; f < 100001; f++)
        {
            if (!y3[f])
            {
                continue;
            }
            ll u = abs(f);

            if (ycal.count(u) > 0)
            {
                counts += ycal[u];
                continue;
            }
            if (fact[u].size() != 0)
            {
                temp = fact[u];
            }
            else
            {
                temp = findDivisors(u, sieve); //ASFADGSDGSADGADGADGADGADGADG
                fact[u] = temp;
            }
            ll c = 0;
            for (ll i = 0; i < temp.size(); i++)
            {
                ll it = temp[i];
                if (it == 0)
                {
                    continue;
                }
                if (u * u / it > 100000 or it > 100000)
                {
                    continue;
                }
                if (x1[it] and x2[u * u / it])
                {
                    // cout<<f.first<<" "<<i<<" "<<-temp<<endl;
                    counts += 1;
                    c++;
                }
            }
            ycal[u] = c;
        }
        for (ll f = 1; f < 100001; f++)
        {
            if (!y2[f])
            {
                continue;
            }
            ll u = abs(f);

            if (ycal.count(u) > 0)
            {
                counts += ycal[u];
                continue;
            }
            //VL temp;
            if (fact[u].size() != 0)
            {
                temp = fact[u];
            }
            else
            {
                temp = findDivisors(u, sieve); //ASFADGSDGSADGADGADGADGADGADG
                fact[u] = temp;
            }
            ll c = 0;
            for (ll i = 0; i < temp.size(); i++)
            {
                ll it = temp[i];
                if (it == 0)
                {
                    continue;
                }
                if (u * u / it > 100000 or it > 100000)
                {
                    continue;
                }
                if (x1[it] and x2[u * u / it])
                {
                    // cout<<f.first<<" "<<i<<" "<<-temp<<endl;
                    counts += 1;
                    c++;
                }
            }
            ycal[u] = c;
        }
        if (x1[0])
        {
            counts += (n - 1) * m;
        }
        else if (y3[0])
        {
            counts += (m - 1) * n;
        }
        cout << counts << "\n";
    }
}