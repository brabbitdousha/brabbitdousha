#include<bits/stdc++.h>

using namespace std;
#define INF 100000000


int ql,qr;
int v,p;

int a[200010];
int minv[200010];

int query( int o, int L, int R )
{
    int M = L + ( R - L ) / 2, ans = INF;
    if ( ql <= L && R <= qr ) return minv[o];
    if ( ql <= M ) ans = min( ans, query( o * 2, L, M ) );
    if ( M < qr ) ans = min( ans, query( o * 2 + 1, M + 1, R ) );
    return ans;
}

void update( int o, int L, int R )
{
    int M = L + ( R - L ) / 2;
    if ( L == R ) minv[o] = v;
    else
    {
        if ( p <= M ) update( o * 2, L, M );
        else update( o * 2 + 1, M + 1, R );
        minv[o] = min( minv[o*2], minv[o*2+1] );
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    for ( p = 1; p <= n ; p++ )
    {
        scanf("%d",&v);
        a[p] = v;
        update(1,1,n);
    }
    /* for ( int i = 1; i <= n; i++ )
    {
        printf("%d ",minv[i]);
    }
    printf("\n"); */
    
    ql = 2, qr = n;
    printf("%d\n",query(1,1,n));

    return 0;
}

