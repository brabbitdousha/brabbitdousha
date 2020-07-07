#include<bits/stdc++.h>

using namespace std;

int a[10000];
int C[10000];
int n;

int lowbit( int x ) { return x & (-x); }

int sum( int x )
{
    int ret = 0;
    while ( x > 0 )
    {
        ret += C[x];
        x -= lowbit( x );
    }
    return ret;
}

void add( int x, int d)
{
    while ( x <= n )
    {
        C[x] += d;
        x += lowbit(x);
    }
}

int main()
{
    int l, r;
    scanf("%d %d %d",&n, &l,&r);
    for ( int i = 1; i <= n; i++ )
    {
        scanf("%d",&a[i]);
        add( i,a[i] );
    }
    for ( int i = 1; i <= n; i++ ) printf("%d ",C[i]);
    printf("\n");
    printf("sum = %d",sum(n));
    printf("sum[%d,%d] = %d",l,r,sum(r) - sum(l - 1));
    return 0;
}
