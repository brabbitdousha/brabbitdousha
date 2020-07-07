#include<bits/stdc++.h>

using namespace std;
#define INF -100000000


int ql,qr;
int v,p;

int a[200010];
int maxv[200010];

int query( int o, int L, int R )
{
    int M = L + ( R - L ) / 2, ans = INF;
    if ( ql <= L && R <= qr ) return maxv[o];
    if ( ql <= M ) ans = max( ans, query( o * 2, L, M ) );
    if ( M < qr ) ans = max( ans, query( o * 2 + 1, M + 1, R ) );
    return ans;
}

void update( int o, int L, int R )
{
    int M = L + ( R - L ) / 2;
    if ( L == R ) maxv[o] = v;
    else
    {
        if ( p <= M ) update( o * 2, L, M );
        else update( o * 2 + 1, M + 1, R );
        maxv[o] = max( maxv[o*2], maxv[o*2+1] );
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    for ( p = 1; p <= n ; p++ )
    {
        scanf("%d",&v);
        //a[p] = v;
        update(1,1,n);
    }
    /* for ( int i = 1; i <= 2 * n; i++ )
    {
        printf("%d ",maxv[i]);
    }
    printf("\n"); */
    
    ql = 2, qr = n;
    printf("%d\n",query(1,1,n));

    return 0;
}

