#include<iostream>
#include<bits/stdc++.h>
#include<limits.h>
#define Fi(i,s,e) for(lli i=s;i<e;i++)
using namespace std;

typedef long long int lli;


lli st[400001],arr[200001];

void build(lli si,lli ss,lli se){
	if(ss==se){
		st[si]=arr[ss];
		return;
	}
	lli mid=(ss+se)/2;
	build(si*2,ss,mid);
	build(si*2+1,mid+1,se);
	st[si]=st[2*si]+st[2*si+1];
}

int query(lli si,lli ss,lli se,lli qs,lli qe){
	if(qs>se||qe<ss){
		return 0;
	}
	if(ss>=qs&&se<=qe){
		return st[si];
	}
	lli mid=(ss+se)/2;
	return query(si*2,ss,mid,qs,qe)+query(si*2+1,mid+1,se,qs,qe);
}

int main(){
	lli n,q,temp,a,b;
	cin>>n>>q;
	Fi(i,1,n+1)
		cin>>arr[i];
	build(1,1,n);
	while(q--){
		cin>>a>>b;
		cout<<a<<" "<<b<<endl;
		cout<<query(1,1,n,a,b)<<endl;
	}

}