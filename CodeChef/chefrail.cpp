#include <iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<unordered_map>
using namespace std;
typedef long long int ll;
#define EPS 1e-9
#define pb push_back
#define FOR(i, a, b) for(ll i = a; i < b; i++)
vector<vector<ll> > fact(100001);
ll ypos[100001];
ll xpos[100001];
ll xneg[100001];
ll yneg[100001];
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
            vector<ll> temp = generateDivisors(curIndex + 1, curDivisor, arr);
            fac.insert(fac.end(), temp.begin(), temp.end());
            curDivisor *= arr[curIndex].primeFactor;
        }
    }
    return fac;
}

vector<ll> findDivisors(ll n, ll sieve[])
{
    vector<primeFactorization> arr;
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
        o.countOfPf=count*2;
        o.primeFactor=t;

        arr.push_back(o);
    }


    ll curIndex = 0, curDivisor = 1;

    return generateDivisors(curIndex, curDivisor, arr);
}
int main()
{
    std::ios_base::sync_with_stdio(false);
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
    vector<ll> temp;
    while (t--)
    {
        unordered_map<ll, ll> xcount, ycount;
        FOR(i, 0, 100001)
        {
            xpos[i] = 0;
            xneg[i] = 0;
            yneg[i] = 0;
            ypos[i] = 0;
        }
        ll n, m;
        cin >> n >> m;
        ll k;
        FOR(i, 0, n)
        {
            cin >> k;
            if (k >= 0)
                xpos[k] = 1;
            else
                xneg[-1 * k] = 1;
        }
        FOR(i, 0, m)
        {
            cin >> k;
            if (k >= 0)
                ypos[k] = 1;
            else
            {
                yneg[k * -1] = 1;
            }
        }
        ll counts = 0;
        for (ll f = 1; f < 100001; f++)
        {
            if (!xpos[f])
            {
                continue;
            }
            ll u = f;

            if (xcount.count(u) > 0)
            {
                counts += xcount[u];
                continue;
            }
            if (fact[u].size() != 0)
            {
                temp = fact[u];
            }
            else
            {
                temp = findDivisors(u, sieve); 
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
                if (ypos[it] and yneg[u * u / it])
                {
                    counts += 1;
                    c++;
                }
            }
            xcount[u] = c;
        }
        for (ll f = 1; f < 100001; f++)
        {
            if (!xneg[f])
            {
                continue;
            }
            ll u = abs(f);

            if (xcount.count(u) > 0)
            {
                counts += xcount[u];
                continue;
            }
            if (fact[u].size() != 0)
            {
                temp = fact[u];
            }
            else
            {
                temp = findDivisors(u, sieve); 
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
                if (ypos[it] and yneg[u * u / it])
                {
                    counts += 1;
                    c++;
                }
            }
            xcount[u] = c;
        }
        for (ll f = 1; f < 100001; f++)
        {
            if (!ypos[f])
            {
                continue;
            }
            ll u = abs(f);

            if (ycount.count(u) > 0)
            {
                counts += ycount[u];
                continue;
            }
            if (fact[u].size() != 0)
            {
                temp = fact[u];
            }
            else
            {
                temp = findDivisors(u, sieve); 
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
                if (xpos[it] and xneg[u * u / it])
                {
                    counts += 1;
                    c++;
                }
            }
            ycount[u] = c;
        }
        for (ll f = 1; f < 100001; f++)
        {
            if (!yneg[f])
            {
                continue;
            }
            ll u = abs(f);

            if (ycount.count(u) > 0)
            {
                counts += ycount[u];
                continue;
            }
            if (fact[u].size() != 0)
            {
                temp = fact[u];
            }
            else
            {
                temp = findDivisors(u, sieve);
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
                if (xpos[it] and xneg[u * u / it])
                {
                    counts += 1;
                    c++;
                }
            }
            ycount[u] = c;
        }
        if (xpos[0])
        {
            counts += (n - 1) * m;
        }
        else if (ypos[0])
        {
            counts += (m - 1) * n;
        }
        cout << counts << "\n";
    }
    return 0;
}