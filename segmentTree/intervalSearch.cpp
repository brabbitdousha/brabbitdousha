#include<bits/stdc++.h>

using namespace std;
#define INF 100000000
int a[20010], minv[20010], maxv[20010], sumv[20010], addv[20010];
int _y1, _y2, v;
int _max = -INF, _min = INF, _sum;

void maintain( int o, int L, int R )
{
    int lc = o * 2, rc = o * 2 + 1;
    sumv[o] = minv[o] = maxv[o] = 0;
    if ( R > L )
    {
        sumv[o] = sumv[lc] + sumv[rc];
        minv[o] = min( minv[lc], minv[rc] );
        maxv[o] = max( maxv[lc], maxv[rc] );
    }
    minv[o] += addv[o]; maxv[o] += addv[o];
    sumv[o] += addv[o] * ( R - L + 1 );
}

void update( int o, int L, int R )
{
    int lc = o * 2, rc = o * 2 + 1;
    if ( _y1 <= L && _y2 >= R ) addv[o] += v;
    else 
    {
        int M = L + ( R - L ) / 2;
        if ( _y1 <= M ) update( lc, L, M );
        if ( _y2 > M ) update( rc, M + 1, R );
    }
    maintain( o, L, R );
}

void query( int o, int L, int R, int add )
{
    if ( _y1 <= L && _y2 >= R )
    {
        _sum += sumv[o] + add * ( R - L + 1 );
        _min = min( _min, minv[o] + add ); 
        _max = max( _max, maxv[o] + add );
    }
    else
    {
        int M = L + ( R - L ) / 2 ;
        if ( _y1 <= M ) query( o * 2, L, M, add + addv[o] );
        if ( _y2 > M ) query( o * 2 + 1, M + 1, R, add + addv[o] );
    }
    
} 
int main()
{
    int n;
    scanf("%d",&n);
    for ( int i  = 1; i <= n ; i++ )
    {
        _y1 = i, _y2 = i;
        scanf("%d",&v);
        update(1, 1, n);
    }
    _y1 = 1, _y2 = n;
    query(1, 1, n, 0);
    for ( int i = 1; i <= n; i ++ ) printf("%d ",addv[i]);
    printf("\n");
    for ( int i = 1; i <= n; i ++ ) printf("%d ",minv[i]);
    printf("\n");
    for ( int i = 1; i <= n; i ++ ) printf("%d ",sumv[i]);
    printf("\n");
    for ( int i = 1; i <= n; i ++ ) printf("%d ",maxv[i]);
    printf("\n");
    printf("\n");
    printf("max = %d min = %d sum = %d\n",_max, _min, _sum);
    return 0;
}

