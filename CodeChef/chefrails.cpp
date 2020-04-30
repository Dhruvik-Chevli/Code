#include <iostream>
#include<vector>
#include<algorithm>
#include<utility>
using namespace std;
typedef long long int ll;
#define EPS 1e-9
#define pb push_back
#define FOR(i, a, b) for(ll i = a; i < b; i++)
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
ll SIEVE[100001];
struct primeFactorization { 
  
    // to store the prime factor 
    // and its highest power 
    int countOfPf, primeFactor; 
}; 
  
// Recursive function to generate all the 
// divisors from the prime factors 
void generateDivisors(int curIndex, int curDivisor, 
                      vector<primeFactorization>& arr) 
{ 
  
    // Base case i.e. we do not have more 
    // primeFactors to include 
    if (curIndex == arr.size()) { 
        cout << curDivisor << ' '; 
        return; 
    } 
  
    for (int i = 0; i <= arr[curIndex].countOfPf; ++i) { 
        generateDivisors(curIndex + 1, curDivisor, arr); 
        curDivisor *= arr[curIndex].primeFactor; 
    } 
} 
  
// Function to find the divisors of n 
void findDivisors(int n) 
{ 
  
    // To store the prime factors along 
    // with their highest power 
    vector<primeFactorization> arr; 
  
    // Finding prime factorization of n 
    for (int i = 2; i * i <= n; ++i) { 
        if (n % i == 0) { 
            int count = 0; 
            while (n % i == 0) { 
                n /= i; 
                count += 1; 
            } 
  
            // For every prime factor we are storing 
            // count of it's occurenceand itself. 
            primeFactorization pf=primeFactorization();
            pf.countOfPf=count;
            pf.primeFactor=i;
            arr.push_back(pf); 
        } 
    } 
  
    // If n is prime 
   /* if (n > 1) { 
        arr.push_back({ 1, n }); 
    }*/ 
  
    int curIndex = 0, curDivisor = 1; 
  
    // Generate all the divisors 
    generateDivisors(curIndex, curDivisor, arr); 
}
void calculateSIEVE()
{
    SIEVE[0]=1;
    FOR(i,1,100001)
        SIEVE[i]=i;
    FOR(i,2,100001)
    {
        if (SIEVE[i]==i)
        {
            for(ll j=i*i;j<100001;j+=i)
            {
                if(SIEVE[j]==j)
                    SIEVE[j]=i;
            }
        }
    }
    return;
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    calculateSIEVE();
    /*FOR(i,0,100001)
        cout<<SIEVE[i]<<" ";*/
    
    return 0;
}