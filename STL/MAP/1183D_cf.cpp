#include<bits/stdc++.h>

using namespace std;

int n,T;
int a[200010];
map<int, int> b,vis;

int main()
{
    scanf("%d",&T);
    while ( T -- )
    {
        b.erase( b.begin(), b.end() );
        vis.erase( vis.begin(), vis.end() );
        scanf("%d",&n);
        for ( int i = 0; i < n; i++ )
        {
            scanf("%d",&a[i]);
        }
        for ( int i = 0; i < n; i ++ ) b[a[i]] ++;
        map<int, int>::iterator iter;
        int cnt = 0;
        for ( iter = b.begin(); iter != b.end(); iter ++ )
        {
            int pos = iter->second;
            while ( vis[pos] && pos > 0 ) pos --;
            vis[pos] = 1;
            cnt += pos;
        }
        printf("%d\n",cnt);
    }
    return 0;
}

