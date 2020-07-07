#include <bits/stdc++.h>

using namespace std;

int d[100000], a[100000];

void build( int s, int t, int p )
{
    if ( s == t ) 
    {
        d[p] = a[s];
        return ;
    }
    int m = ( s + t ) / 2;
    build( s, m, p * 2 ), build( m + 1, t, p * 2 + 1 );
    d[p] = d[p * 2] + d[(p * 2) + 1];
}

int getsum( int l, int r, int s, int t, int p )
{
    //[s,t]为当前节点包含的区间,p为当前节点编号
    if ( l <= s && t <= r ) return d[p];
    int m = ( l + r ) / 2, sum = 0;
    if ( l <= m ) sum += getsum( l, r, s, m, p * 2 );
    if ( r > m ) sum += getsum( l, r, m + 1, t, p * 2 + 1 );
    return sum;
}


int main()
{

    return 0;
}
