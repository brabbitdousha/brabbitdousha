#include <bits/stdc++.h>

using namespace std;

int n;
int a[1000], sum[1000];
int dp1[300][300], dp2[300][300];


int main()
{
    scanf("%d", &n);
    sum[0] = 0;
    for ( int i = 1; i <= n; i ++ )
    {
        scanf("%d",&a[i]);
        a[i+n] = a[i];
        sum[i] = sum[i-1] + a[i];
    }
    for ( int i = n + 1; i <= n * 2; i ++ ) sum[i] = sum[i-1] + a[i];
    for ( int p = 1; p < n; p ++ )
    {
        for ( int i = 1, j = i + p; i < 2 * n && j < 2 * n; i ++, j = i + p )
        {
            for ( int k = i; k < j; k ++ )
            {
                dp2[i][j] = 9999999;
                dp1[i][j] = max( dp1[i][j], dp1[i][k] + dp1[k+1][j] + sum[j] - sum[i-1] );
                dp2[i][j] = min( dp2[i][j], dp2[i][k] + dp2[k+1][j] + sum[j] - sum[i-1] );
            }
        }
    }
    int ans1 =  0, ans2 = 9999999;
    for ( int i = 1; i <= n; i ++ )
    {
        int j = i + n - 1;
        ans1 = max( ans1, dp1[i][j] );
        ans2 = min( ans2, dp2[i][j] );
        //cout << dp1[i][j] <<"!!!!"<<dp2[i][j];
    }
    printf("%d\n%d\n",ans2,ans1);
    
    return 0;
}
