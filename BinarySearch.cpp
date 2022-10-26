#include <bits/stdc++.h>


typedef long long int ll;
using namespace std;

ll binarysearch(ll a[],ll n,ll key)
{
    ll hi = n-1;
    ll lo = 0;
    ll mid;

    while(lo<=hi)
    {
        mid = (hi+lo)/2;

        if(a[mid]>key)
        {
            hi = mid - 1;
        }
        else if(a[mid]<key)
        {
            lo = mid+1;
        }
        else if(a[mid]==key)
        {
            return mid;
        }
        
    }
    return -1;
}

int main()
{
    ll T,n;
    cin >> T;
    while (T--) {
        cin >> n;
        ll key;
        cin>>key;
        ll a[n];
        for(int i = 0;i<n;i++)cin >> a[i];

        cout<<binarysearch(a,n,key);
        
    }
}
