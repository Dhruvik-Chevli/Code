#include <iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<string>
#include<math.h>
#include<cstring>
#include<unordered_map>
using namespace std;
typedef long long int ll;
#define EPS 1e-9
#define pb push_back
#define FOR(i, a, b) for(ll i = a; i < b; i++)
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
const ll MAXN=100001;
const ll MAXM=100001;
const ll LN = 19;
ll spf[1000001];
 
ll N, M, K, cur, A[MAXN], LVL[MAXN], DP[LN][MAXN];
ll BL[MAXN << 1], ID[MAXN << 1], VAL[MAXN], ANS[MAXM];
ll d[MAXN], l[MAXN], r[MAXN];
bool VIS[MAXN];
vector < ll > adjList[MAXN];
vector<unordered_map<ll,ll> >primeFac(MAXN+1);
ll gcdExtended(ll a, ll b, ll *x, ll *y); 
ll modInverse(ll a, ll m) 
{ 
    ll x, y; 
    ll g = gcdExtended(a, m, &x, &y); 
    if (g != 1) 
        return 0;
        //cout << "Inverse doesn't exist"; 
    else
    { 
        // m is added to handle negative x 
        ll res = (x%m + m) % m; 
        //cout << "Modular multiplicative inverse is " << res; 
        return res;
        
    } 
} 
  
// C function for extended Euclidean Algorithm 
ll gcdExtended(ll a, ll b, ll *x, ll *y) 
{ 
    // Base Case 
    if (a == 0) 
    { 
        *x = 0, *y = 1; 
        return b; 
    } 
  
    ll x1, y1; // To store results of recursive call 
    ll gcd = gcdExtended(b%a, a, &x1, &y1); 
  
    // Update x and y using results of recursive 
    // call 
    *x = y1 - (b/a) * x1; 
    *y = x1; 
  
    return gcd; 
} 
long long pow(long long base, long long power) {
    long long result = 1;
    while(power > 0) {

        if(power % 2 == 1) { // Can also use (power & 1) to make code even faster
            result = (result*base) % MOD;
        }
        base = (base * base) % MOD;
        power = power / 2; // Can also use power >>= 1; to make code even faster
    }
    return result;
}
void sieve() 
{ 
    spf[1] = 1; 
    for (ll i=2; i<1000001; i++) 
        spf[i] = i; 
    for (ll i=4; i<1000001; i+=2) 
        spf[i] = 2; 
    for (ll i=3; i*i<1000001; i++) 
    {
        if (spf[i] == i) 
        {
            for (ll j=i*i; j<1000001; j+=i) 
                if (spf[j]==j) 
                    spf[j] = i; 
        } 
    } 
} 


struct query{
	ll id, l, r, lc;
	bool operator < (const query& rhs){
		return (BL[l] == BL[rhs.l]) ? (r < rhs.r) : (BL[l] < BL[rhs.l]);
	}
}Q[MAXM];
void dfs(ll u, ll par){
	l[u] = ++cur; 
	ID[cur] = u;
	for (ll i = 1; i < LN; i++) DP[i][u] = DP[i - 1][DP[i - 1][u]];
	for (ll i = 0; i < adjList[u].size(); i++){
		ll v = adjList[u][i];
		if (v == par) continue;
		LVL[v] = LVL[u] + 1;
		DP[0][v] = u;
		dfs(v, u);
	}
	r[u] = ++cur; ID[cur] = u;
}
inline ll lca(ll u, ll v){
	if (LVL[u] > LVL[v]) swap(u, v);
	for (ll i = LN - 1; i >= 0; i--)
		if (LVL[v] - (1 << i) >= LVL[u]) v = DP[i][v];
	if (u == v) return u;
	for (ll i = LN - 1; i >= 0; i--){
		if (DP[i][u] != DP[i][v]){
			u = DP[i][u];
			v = DP[i][v];
		}
	}
	return DP[0][u];
}
inline void check(ll x, ll &res,vector<ll>&primes){
	// If (x) occurs twice, then don't consider it's value 
	if ( (VIS[x]) and (--VAL[A[x]] == 0))
    {
        for(auto y:primeFac[x])
        {
            if(primes[y.first]>0)
            {
                ll u=primes[y.first];
                res=(res%MOD)*(modInverse(u+1,MOD))%MOD;
                primes[y.first]=u-y.second;
                res=((res)%MOD*((u-y.second+1)%MOD))%MOD;
            }
        }
    } 
	else if ( !VIS[x] and (VAL[A[x]]++ == 0))
    {
        for(auto y:primeFac[x])
        {
            if(primes[y.first]>0)
            {
                ll u=primes[y.first];
                res=(res%MOD)*(modInverse(u+1,MOD))%MOD;
                primes[y.first]=u+y.second;
                res=((res)%MOD*(u+y.second+1)%MOD)%MOD;
            }
            else
            {
                primes[y.first]=y.second;
                res=((res)%MOD*((y.second+1)%MOD))%MOD;
            }
        }
    }
	VIS[x] ^= 1;
}
void compute(){
 
	// Perform standard Mo's Algorithm
	ll curL = Q[0].l, curR = Q[0].l - 1, res = 1;
    vector<ll>primes(1000001,0);
	for (ll i = 0; i < M; i++){
 
		while (curL < Q[i].l) check(ID[curL++], res,primes);
		while (curL > Q[i].l) check(ID[--curL], res,primes);
		while (curR < Q[i].r) check(ID[++curR], res,primes);
		while (curR > Q[i].r) check(ID[curR--], res,primes);
 
		ll u = ID[curL], v = ID[curR];
 
		// Case 2
		if (Q[i].lc != u and Q[i].lc != v) check(Q[i].lc, res,primes);
        // ll finalAns=1;
        // for(auto x:primes)
        // {
        //     finalAns=(finalAns*(x.second+1))%MOD;
        // }
		ANS[Q[i].id] = res%MOD;
 
		if (Q[i].lc != u and Q[i].lc != v) check(Q[i].lc, res,primes);
	}
 
	for (ll i = 0; i < M; i++) cout<<ANS[i]<<"\n"<<flush;
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    sieve();
    while(t--)
    {
        cin>>N;
        cur = 0;
        ll u,v;
		memset(VIS, 0, sizeof(VIS));
		memset(VAL, 0, sizeof(VAL));
		for (ll i = 1; i <= N; i++) adjList[i].clear();
        for (ll i = 1; i < N; i++){
			cin>>u>>v;
			adjList[u].push_back(v);
			adjList[v].push_back(u);
		}
        FOR(i,1,N+1)
        {
            primeFac[i].clear();
        }
        for (ll i = 1; i <= N; i++) cin>>A[i];
        FOR(i,1,N+1)
        {
            ll g=A[i];
            while(g!=1)
            {
                if(primeFac[i].count(spf[g]))
                {
                    primeFac[i][spf[g]]+=1;
                }
                else
                {
                    primeFac[i][spf[g]]=1;
                }
                g/=spf[g];
            }
        }
        DP[0][1] = 1;
		dfs(1, -1);
		ll size = sqrt(cur);
        for (ll i = 1; i <= cur; i++) BL[i] = (i - 1) / size + 1;
        cin>>M;
		for (ll i = 0; i < M; i++){
			cin>>u>>v;
			Q[i].lc = lca(u, v);
			if (l[u] > l[v]) swap(u, v);
			if (Q[i].lc == u) Q[i].l = l[u], Q[i].r = l[v];
			else Q[i].l = r[u], Q[i].r = l[v];
			Q[i].id = i;
		}
 
		sort(Q, Q + M);
        compute();

    }
    return 0;
}