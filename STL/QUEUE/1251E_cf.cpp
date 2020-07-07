#include <bits/stdc++.h>

using namespace std;

int T;
priority_queue< int,vector<int>,greater<int> > q;
vector<int> g[1000005];

int main()
{
    scanf("%d",&T);
    int n;
    long long int ans;
    while ( T -- )
    {
        ans = 0;
        scanf("%d",&n);
        int x,y;
        for ( int i = 1; i <= n; i++ ) 
        {
            scanf("%d %d",&x,&y);
            g[x].push_back(y);
        }
        for ( int i = n - 1; i >= 0; i -- )
        {
            int sz = g[i].size();
            for ( int j = 0; j < sz; j ++ ) q.push(g[i][j]);
            while ( q.size() > n - i ) {
                ans += q.top(), q.pop();
            }
        }
        
        printf("%lld\n",ans);
        for(int i = 0; i < n; ++i) 
        {
            g[i].clear();
            while( !q.empty() ) q.pop();
        }
    }

    return 0;
}
