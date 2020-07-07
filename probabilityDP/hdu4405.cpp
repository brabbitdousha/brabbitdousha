#include <bits/stdc++.h>

using namespace std;

int n, m;
int to[100010];
double dp[100010];

int main()
{
    while ( scanf("%d %d", &n, &m) != EOF )
    {
        memset(to, -1, sizeof(to));
        memset(dp, 0, sizeof(dp));
        if ( n == 0 && m == 0 ) break;
        int a, b;
        for ( int i = 1; i <= m; i ++ )
        {
            scanf("%d %d", &a, &b);
            to[a] = b;
        }
        dp[n] = 0;
        for ( int i = n - 1; i >= 0; i -- )
        {
            if ( to[i] == -1 )
            {
                for ( int j = 1; j <= 6; j ++ ) dp[i] += dp[i+j] * ( 1.0 / 6 );
                dp[i] += 1;
            }
            else dp[i] = dp[to[i]];
        }
        printf("%.4lf\n", dp[0]);
    }

    return 0;
}
