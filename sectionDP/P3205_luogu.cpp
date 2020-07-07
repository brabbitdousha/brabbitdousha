#include <bits/stdc++.h>

using namespace std;

int n;
int a[10000];
long long int dp[2010][2010][2];

const int MOD = 19650827;

//dp[i][j][0] 第ｉ个人从左边进入
//dp[i][j][1] 第ｊ个人从右边进入
//dp[i][i][0] = 1

// a[j] > a[i+1], a[j]从右边进入　dp[i][j][1] += dp[i][j-1][0]
//a[i+1]是从左边进入的
// a[j] > a[j],   a[j]从右边进入　dp[i][j][1] += dp[i][j-1][1]
// a[i] < a[j], a[i]从左边进入　dp[i][j][0] += dp[i+1][j][1]
// a[i] < a[i+1], a[i]从左边进入　dp[i][j][0] += dp[i+1][j][0]

int main()
{
    scanf("%d", &n);
    for ( int i = 1; i <= n; i ++ ) scanf("%d", &a[i]);
    for ( int i = 1; i <= n; i ++ ) {dp[i][i][0] = 1; dp[i][i][1] = 0;}
    for ( int len = 1; len <= n; len ++ )
    {
        for ( int i = 1, j = i + len; j <= n; j ++, i ++ )
        {
            if ( a[j] > a[j-1] ) dp[i][j][1] = dp[i][j][1] + dp[i][j-1][1] % MOD;
            if ( a[j] > a[i] ) dp[i][j][1] = dp[i][j][1] + dp[i][j-1][0] % MOD;
            if ( a[i] < a[i+1] ) dp[i][j][0] = dp[i][j][0] + dp[i+1][j][0] % MOD;
            if ( a[i] < a[j] ) dp[i][j][0] = dp[i][j][0] + dp[i+1][j][1] % MOD;
        }
    }
    printf("%lld\n", (dp[1][n][0] + dp[1][n][1]) % MOD);
    return 0;
}
