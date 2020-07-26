#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<unordered_map>
using namespace std;


int main() {
    int n;
    cin>>n;
    vector<int>v(n,0);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    unordered_map<int, int>map;
    for(int i=0;i<n;i++)
    {
        map[v[i]]+=1;
    }
    unordered_map<int,int>::iterator it=map.begin();
    long ans=0;
    while(it!=map.end())
    {
        ans+=((it->second*(it->second-1))/2);
        it++;
    }
    cout<<ans<<"\n";
    return 0;
}

