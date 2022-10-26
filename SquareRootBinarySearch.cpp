#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;

// if n is 1e18 take hi = min(n,1e9);

double squareroot(int n)
{
    double hi = (double) 1e9;   // mid mein -+ precision hoga
    double lo = (double) 1;
    double mid;
    double ans;
    double p = 0.0000001 ; // precision

    while(hi-lo>=p)
    {
        mid = (hi+lo)/2;

        double x = mid*mid; // for nth root do mid*mid*......(n times)

        if(n<x)
        {
            hi = mid - p; 
        }
        else if(x<=n)
        {
            ans = mid;
            lo = mid + p;
        }
        
        
    }
    return ans;
}

int main()
{
        int n;
        cin>>n;
        cout<<squareroot(n)<<endl;

}
