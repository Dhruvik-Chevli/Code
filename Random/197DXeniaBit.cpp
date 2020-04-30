#include <iostream>
// #include <vector>
// #include <algorithm>
// #include <utility>
// #include <string>
// #include <unordered_set>
// #include <stack>
// #include <queue>
// #include <unordered_map>
using namespace std;
typedef long long int ll;
#define EPS 1e-9
#define pb push_back
#define FOR(i, a, b) for (ll i = a; i < b; i++)
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
void combineOR(ll tree[], ll tn)
{
    tree[tn] = tree[2 * tn] | tree[2 * tn + 1];
}
void combineXOR(ll tree[], ll tn)
{
    tree[tn] = tree[2 * tn] ^ tree[2 * tn + 1];
}
int buildTree(ll v[], ll tree[], ll tn, ll tl, ll tr)
{
    if (tl == tr)
    {
        tree[tn] = v[tl];
        return 0;
    }
    ll tm = (tl + tr) / 2;
    int k = buildTree(v, tree, 2 * tn, tl, tm);
    int g = buildTree(v, tree, 2 * tn + 1, tm + 1, tr);
    if (k == 0)
    {
        combineOR(tree, tn);
        return 1;
    }
    else
    {
        combineXOR(tree, tn);
        return 0;
    }
}
int update(ll v[], ll tree[], ll tn, ll tl, ll tr, ll pos, ll val)
{
    // if (pos > tr || pos < tl)
    //     return 0;
    if (tl == tr)
    {
        tree[tn] = val;
        v[pos] = val;
        return 0;
    }
    ll tm = (tl + tr) / 2;
    int k;
    if (pos > tm)
    {
        k = update(v, tree, 2 * tn + 1, tm + 1, tr, pos, val);
    }
    else
    {
        k = update(v, tree, 2 * tn, tl, tm, pos, val);
    }
    if (k == 1)
    {
        combineXOR(tree, tn);
        return 0;
    }
    else
    {
        combineOR(tree, tn);
        return 1;
    }
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, m;
    cin >> n >> m;
    //vector<ll> v(1 << (n));
    ll v[1 << n];
    FOR(i, 0, 1 << (n))
    {
        cin >> v[i];
    }
    n = (1 << (n));
    //vector<ll> tree(4 * n, 0);
    ll tree[4 * n];
    //memset(tree, tree + 4 * n, 0);
    buildTree(v, tree, 1, 0, n - 1);
    // FOR(i,1,4*n)
    // {
    //     cout<<tree[i]<<" "<<i<<endl;
    // }
    FOR(i, 0, m)
    {
        ll p, b;
        cin >> p >> b;
        update(v, tree, 1, 0, n - 1, p - 1, b);
        // FOR(i,1,4*n)
        // {
        //     cout<<tree[i]<<" "<<i<<endl;
        // }
        cout << tree[1] << "\n";
    }
    return 0;
}