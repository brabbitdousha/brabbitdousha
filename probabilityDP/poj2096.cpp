#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
ll n, s;
double dp[1010][1010];

int main()
{
    scanf("%lld %lld", &n, &s);
    dp[n][s] = 0;
    for ( int i = n; i >= 0; i -- )
    {
        for ( int j = s; j >= 0; j -- )
        {
            if ( i == n && s == j ) continue;
            dp[i][j] = ( dp[i][j+1] * i * ( s - j ) + dp[i+1][j] * ( n - i ) * j + 
                         dp[i+1][j+1] * ( n - i ) * ( s - j ) + n * s ) / ( n * s - i * j );
        }
    }
    printf("%.4lf\n",dp[0][0]);
    return 0;
}
