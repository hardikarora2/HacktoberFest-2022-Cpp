#include <bits/stdc++.h>

#define f(i, n) for (long long i = 0; i < n; i++)
#define f1(i, n) for (long long i = 1; i <= n; i++)
#define fast_io std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
typedef long long int ll;
using namespace std;

ll dp[105][100005];

ll knapsack(ll w, ll wt[], ll val[], ll n)
{
        f(i,n+1)
        {
            f(j,w+1)
            {
                if(i==0 || j==0)
                {
                    dp[i][j] = 0;
                }
            }
        }
        
        f1(i,n)
        {
            f1(j,w)
            {
                
                if(wt[i-1] <=j)
                {
                    dp[i][j]= max( val[i-1] + dp[i-1][j-wt[i-1]] , dp[i-1][j]);
                }
                else
                {
                    dp[i][j]= dp[i-1][j];
                }
                
            }
        }
        return dp[n][w];
}

int main()
{
        fast_io;

        
            memset(dp,-1,sizeof(dp));
            ll n,w;
            cin >> n>>w;
            
            ll val[n];
            ll wt[n];
            f(i,n) 
            {
                cin>>val[i];
            }
            f(i,n) 
            {
                cin>>wt[i];
            }
        

            cout<<knapsack(w,wt,val,n)<<endl;
      
        
}
