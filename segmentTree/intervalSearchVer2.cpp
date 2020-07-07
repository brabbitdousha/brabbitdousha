#include<bits/stdc++.h>

using namespace std;
#define INF 100000000
int a[20010], minv[20010], maxv[20010], sumv[20010], addv[20010], setv[20010];
int _y1, _y2, v;
int _max = -INF, _min = INF, _sum;

void pushdown(int o)
{
    int lc = o * 2, rc = o * 2 + 1;
    if ( setv[o] >= 0 )
    {
        setv[lc] = setv[rc] = setv[o];
        setv[o] = -1;
    }
}

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
    minv[o] += setv[o]; maxv[o] += setv[o];
    sumv[o] += setv[o] * ( R - L + 1 );
}

void update( int o, int L, int R )
{
    int lc = o * 2, rc = o * 2 + 1;
    if ( _y1 <= L && _y2 >= R ) setv[o] = v;
    else 
    {
        pushdown(o);
        int M = L + ( R - L ) / 2;
        if ( _y1 <= M ) update( lc, L, M );
        else maintain( lc, L, M );

        if ( _y2 > M ) update( rc, M + 1, R );
        else maintain(rc, M + 1, R);
    }
    maintain( o, L, R );
}

void query( int o, int L, int R)
{
    if ( setv[o] >= 0 )
    {
        _sum += setv[o] * ( min( R, _y2 ) - max( L, _y1 ) );
        _min = min( _min, setv[o] );
        _max = max( _max, setv[o] );
    }
    else if ( _y1 <= L && _y2 >= R )
    {
        _sum += sumv[o];
        _min = min( _min, setv[o] );
        _max = max( _max, setv[o] );
    }
    else
    {
        int M = L + ( R - L ) / 2;
        if ( _y1 <= M ) query( o * 2, L, M );
        if ( _y2 > M ) query( o * 2 + 1, M + 1, R );
    }
    
} 
int main()
{
    int n;
    scanf("%d",&n);
    for ( int i  = 1; i <= n ; i++ )
    {
        scanf("%d",&v);
        _y1 = i, _y2 = i;
        update(1, 1, n);
    }
    _y1 = 1, _y2 = n;
    query(1, 1, n);
    for ( int i = 1; i <= n; i ++ ) printf("%d ",setv[i]);
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

