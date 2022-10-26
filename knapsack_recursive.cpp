#include <bits/stdc++.h>
using namespace std;

int dp[105][100005];

int knapsack(int w, int wt[], int val[], int n)
{
        for(int i=0;i<n+1;i++)
        {
            for(int j=0;j<w+1;j++)
            {
                if(i==0 || j==0)
                {
                    dp[i][j] = 0;
                }
            }
        }
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=w;j++)
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
    memset(dp,-1,sizeof(dp));
    int n,w;
    cin >> n>>w;
    
    int val[n];
    int wt[n];
    for(int i=0;i<n;i++)
    {
        cin>>val[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>wt[i];
    }
    
    cout<<knapsack(w,wt,val,n)<<endl;
        
}
