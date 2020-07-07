#include <bits/stdc++.h>

using namespace  std;

typedef long long ll;

int n;
int a[1000];
ll dp[1000][1000];
int head[1000], tail[1000];

int main()
{
    scanf("%d", &n);
    for ( int i = 1; i <= n; i ++ )
    {
        scanf("%d", &a[i]);
        head[i] = a[i];
        head[i + n] = a[i];
    }
    for ( int i = 1; i <= n - 1; i ++ ) tail[i] = a[i + 1];
    tail[n] = a[1];
    for ( int i = 1; i <= n; i ++ ) tail[i + n] = tail[i];

    for ( int p = 1; p < n; p ++ )
    {
        for ( int i = 1, j = i + p; i < 2 * n && j < 2 * n; i ++, j = i + p )
        {
            for ( int k = i; k < j; k ++ )
            {
                dp[i][j] = max( dp[i][j], dp[i][k] + dp[k+1][j] + head[i] * tail[k] * tail[j] );
            }
        }
    }
    ll ans = -1;
    for ( int i = 1; i <= n; i ++ )
    {
        int j = i + n - 1;
        ans = max( ans, dp[i][j] );
    }
    printf("%lld\n", ans);

    return 0;
}
