#include<iostream>
#include<string>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long int lli;
lli power(lli x, lli y, lli p) 
{ 
    int res = 1;        
    x = x % p; 
    while (y > 0) 
    {  
        if (y & 1) 
            res = (res*x) % p;  
        y = y>>1;
        x = (x*x) % p; 
    } 
    return res; 
} 
lli modInverse(lli n, lli p) 
{ 
    return power(n, p-2, p); 
} 
lli nCrModPFermat(lli n, lli r, lli p,lli fac[]) 
{ 
   if (r==0) 
      return 1;  
    //lli fac[n+1]; 
    //fac[0] = 1; 
    //for (lli i=1 ; i<=n; i++) 
      //  fac[i] = fac[i-1]*i%p; 
  
    return (fac[n]* modInverse(fac[r], p) % p * 
            modInverse(fac[n-r], p) % p) % p; 
}
/*lli nCrModp(lli n, lli r, lli p) 
{ 
    // The array C is going to store last row of 
    // pascal triangle at the end. And last entry 
    // of last row is nCr 
    lli C[r+1]; 
    memset(C, 0, sizeof(C)); 
  
    C[0] = 1; // Top row of Pascal Triangle 
  
    // One by constructs remaining rows of Pascal 
    // Triangle from top to bottom 
    for (lli i = 1; i <= n; i++) 
    { 
        // Fill entries of current row using previous 
        // row values 
        for (lli j = min(i, r); j > 0; j--) 
  
            // nCj = (n-1)Cj + (n-1)C(j-1); 
            C[j] = (C[j] + C[j-1])%p; 
    } 
    return C[r]; 
}*/ 
int main()
{   
    lli t;
    cin>>t;
    
    lli fac[100001];
    fac[0]=1;
    for(lli i=1;i<100001;i++)
    {
        fac[i]=fac[i-1]*i%1000000007;
    }
    while(t--)
    {
        lli n;
        cin>>n;
        string a,b;
        cin>>a;
        cin>>b;
        lli a1=0,a0=0,b1=0,b0=0;
        for(lli i=0;i<n;i++)
        {
            if(a[i]=='1')
                a1+=1;
            else
                a0+=1;
            if(b[i]=='1')
                b1+=1;
            else
                b0+=1;            
        }
        lli ans=0;
        lli k=llabs(a1-b1);
        lli ones=min(a1,b1);
        lli zeroes=min(a0,b0);
        for(lli i=0;i<=zeroes && i<=ones;i++)
        {
            ans=(ans%1000000007+nCrModPFermat(n,k+2*i,1000000007,fac))%1000000007;
        }
        cout<<ans<<endl;        
    }
}