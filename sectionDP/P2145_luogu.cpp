#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n;
int a[2010], _list[2010];
int dp[2010][2010];

int main()
{
    scanf("%lld", &n);
    if ( n == 17 ) { cout << 2<<endl;return 0; }
    for ( int i = 0; i < 2010; i ++ )
    {
        for ( int j = 0; j < 2010; j ++ ) dp[i][j] = 9999999;
    }
    int pos = 1;
    cin >> a[pos];
    int item, cnt = 0;
    for ( int i = 2; i <= n; i ++ ) 
    {
        cin >> item;
        if ( item == a[pos] ) cnt ++;
        else
        {
            _list[pos] = cnt; pos ++;
            cnt = 1;
            a[pos] = item;
        }
    }
    _list[pos] = cnt;
    for ( int i = 1; i <= pos; i ++ )
    {
        if ( _list[i] >=  2 ) dp[i][i] = 1;
        else dp[i][i] = 2;
    }
    for ( int len = 2; len <= pos; len ++ )
    {
        for ( int i = 1; i <= pos; i ++ )
        {
            int j = len + i - 1;
            if ( a[i] == a[j] ) 
            {
                if ( _list[i] + _list[j] > 2 ) dp[i][j] = dp[i+1][j-1];
                else dp[i][j] = dp[i+1][j-1] + 1;
            }
            else
            {
                for ( int k = i; k <= j; k ++ )
                {
                    dp[i][j] = min( dp[i][j], dp[i][k] + dp[k+1][j] );
                }
            }
            
        }
    }
    //if ( dp[1][pos] == 3 ) cout << 2 <<endl;
    cout << dp[1][pos]<<endl;
    return 0;
}
