#include<bits/stdc++.h>

using namespace std;

const int N = 2750133;

int b[N], vis[N], prim[N], xu[N], cnt,n,m[N];

//1、如果a[i]​是一个质数，那么它会变成它自己和一个比它大的质数。
//2、如果a[i​]是一个合数，那么它会变成它自己和一个比它小的数。

//一个欧拉筛和小合数生成
void work(int n)
{
    for (int i = 2; i <= n; i++)
    {
        if ( !vis[i] ) prim[++cnt] = i;
        for ( int j = 1; j <= cnt; j++ )
        {
            if ( i * prim[j] > n ) break;
            vis[i*prim[j]] = 1;
            xu[i*prim[j]] = i;
            if( i % prim[j] == 0 )break;
        }
    }
}


bool cmp(int a,int b)
{
    if( vis[a]==0 )
    {
        if(vis[b]==0)return a < b;
        else return 0;
    }
    if(vis[b]==0)
    {
        return 1;
    }
    return a > b;
}
 
int main()
{
    scanf("%d",&n);
    for ( int i = 1; i <= 2 * n; i++ ) 
    {
        scanf("%d",&b[i]);
        m[b[i]] ++;
    }
    work(2750131);
    sort(b + 1,b + 2 * n + 1, cmp);
    for ( int i = 1; i <= 2 * n; i++ )
    {
        if ( m[b[i]] )
        {
            printf("%d ",b[i]);
            m[b[i]] --;
            if ( vis[b[i]] == 0 && b[i] <= cnt ) m[prim[b[i]]] --; //删去大素数
            if ( vis[b[i]] ) m[xu[b[i]]] --; //删去小合数
        }
    }

    return 0;
}
