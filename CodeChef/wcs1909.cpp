#include <iostream>
#include<vector>
#include<set>
typedef long long int ll;
using namespace std; 
  
//  Utility method to get gcd of a and b 
ll gcd(ll a, ll b) 
{ 
    if (b == 0) 
        return a; 
    return gcd(b, a % b); 
} 
  
//  method returns reduced form of dy/dx as a pair 
pair<ll, ll> getReducedForm(ll dy, ll dx) 
{ 
    ll g = gcd(abs(dy), abs(dx)); 
  
    //  get sign of result 
    bool sign = (dy < 0) ^ (dx < 0); 
  
    if (sign) 
        return make_pair(-abs(dy) / g, abs(dx) / g); 
    else
        return make_pair(abs(dy) / g, abs(dx) / g); 
} 
  
/*  method returns minimum number of lines to 
    cover all points where all lines goes 
    through (xO, yO) */
ll minLinesToCoverPoints(ll points[][2], ll N, 
                                   ll xO, ll yO) 
{ 
    //  set to store slope as a pair 
    set< pair<ll, ll> > st; 
    pair<ll, ll> temp; 
    ll minLines = 0; 
  
    //  loop over all points once 
    for (ll i = 0; i < N; i++) 
    { 
        //  get x and y co-ordinate of current point 
        ll curX = points[i][0]; 
        ll curY = points[i][1]; 
  
        temp = getReducedForm(curY - yO, curX - xO); 
  
        // if this slope is not there in set, 
        // increase ans by 1 and insert in set 
        if (st.find(temp) == st.end()) 
        { 
            st.insert(temp); 
            minLines++; 
        } 
    } 
  
    return minLines; 
} 
  
// Driver code to test above methods 
int main() 
{ 
    ll x0, y0,m;
    cin>>m>>x0>>y0; 
  
    ll points[m][2];
    ll x,y;
    for(ll i=0;i<m;i++)
    {
        cin>>x>>y;
        points[i][0]=x;
        points[i][1]=y;        
    }  
  
    //int N = sizeof(points) / sizeof(points[0]); 
    cout << minLinesToCoverPoints(points, m, x0, y0)<<endl; 
    return 0; 
} 