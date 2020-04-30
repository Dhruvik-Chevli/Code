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
 
vector<ll>primes(1000001,0);
ll N, M, K, cur, A[MAXN], LVL[MAXN], DP[LN][MAXN];
ll BL[MAXN << 1], ID[MAXN << 1], VAL[MAXN], ANS[MAXM];
ll d[MAXN], l[MAXN], r[MAXN];
bool VIS[MAXN];
vector < ll > adjList[MAXN];
vector<unordered_map<ll,ll> >primeFac(MAXN+1);
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
inline void check(ll x, ll &res){
	// If (x) occurs twice, then don't consider it's value 
	if ( (VIS[x]))
    {
        for(auto y:primeFac[x])
        {
            if(primes[y.first]>0)
            {
                ll r=primes[y.first];
                res=(res/(r+1));
                r=(r-y.second);
                primes[y.first]=r;
                res=(res*(r+1))%MOD;
            }
            else
            {
                primes[y.first]=0;
            }
            
        }
    } 
	else if ( !VIS[x] )
    {
        for(auto y:primeFac[x])
        {
            if(primes[y.first]>0)
            {
                ll r=primes[y.first];
                res=(res/(r+1));
                r=(r+y.second);
                primes[y.first]=r;
                res=(res*(r+1))%MOD;
            }
            else
            {
                primes[y.first]=y.second;
                res=((res)*(y.second+1));
            }
        }
    }
	VIS[x] ^= 1;
}
void compute(){
 
	// Perform standard Mo's Algorithm
	ll curL = Q[0].l, curR = Q[0].l - 1, res = 1;
    FOR(i,0,1000001) primes[i]=0;
	for (ll i = 0; i < M; i++){
 
		while (curL < Q[i].l) check(ID[curL++], res);
		while (curL > Q[i].l) check(ID[--curL], res);
		while (curR < Q[i].r) check(ID[++curR], res);
		while (curR > Q[i].r) check(ID[curR--], res);
 
		ll u = ID[curL], v = ID[curR];
 
		// Case 2
		if (Q[i].lc != u and Q[i].lc != v) check(Q[i].lc, res);
		ANS[Q[i].id] = res;
 
		if (Q[i].lc != u and Q[i].lc != v) check(Q[i].lc, res);
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