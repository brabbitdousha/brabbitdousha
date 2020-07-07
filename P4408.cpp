#include <bits/stdc++.h>

using namespace std;
const int maxn =  2000000000;
typedef long long ll;
struct Edge
{
    ll to, next, w;
} edge[500010]; 

struct node
{
    ll index, weight;
    bool operator<(const node b) const
	{
		return this->index < b.index;
	}
};
vector<node> vec1, vec2;

ll head[500010], tot;
ll dis[500010], vis[500010];
ll n, m;
ll root1, root2, dep, dist;


void build( ll u, ll v, ll w )
{
    edge[++tot].w = w;
    edge[tot].next = head[u];
    head[u] = tot;
    edge[tot].to = v;
}

void dfs( ll t, ll fa )
{
    for ( ll i = head[t]; i; i = edge[i].next  )
    {
        ll v = edge[i].to;
        if ( v == fa ) continue;
        dis[v] = dis[t] + edge[i].w;
        dfs( v, t );
    }
}

void dfs2( ll t, ll fa )
{
    
    for ( ll i = head[t]; i; i = edge[i].next  )
    {
        ll v = edge[i].to;
        if ( v == fa ) continue;
        dis[v] = dis[t] + edge[i].w;
        node item;
        item.index = v;
        item.weight = dis[v];
        vec1.push_back(item);
        dfs2( v, t );
    }
}

void dfs3( ll t, ll fa )
{

    for ( ll i = head[t]; i; i = edge[i].next  )
    {
        ll v = edge[i].to;
        if ( v == fa ) continue;
        dis[v] = dis[t] + edge[i].w;
        node item;
        item.index = v;
        item.weight = dis[v];
        vec2.push_back(item);
        dfs3( v, t );
    }
}


int main()
{
    //freopen( "in", "r", stdin );
    scanf("%lld %lld", &n, &m);
    //init();
    for ( ll i = 0; i < m; i ++ )
    {
        ll u, v, w;
        scanf("%lld %lld %lld", &u, &v, &w);
        build( v, u, w );
        build( u, v, w );
    }
    ll root = 1;
    dis[root] = 0; dfs( root, -1 );
    for ( ll i = 1; i <= n; i ++ ) if ( dis[root] < dis[i] ) root = i;
    root1 = root;

    memset( dis, 0, sizeof(dis) );
    dis[root] = 0; dfs( root1, -1 );
    for ( ll i = 1; i <= n; i ++ ) if ( dis[root] < dis[i] ) root = i;
    root2 = root;
    //printf("%lld ->  %lld\n", root1, root2);
    memset(dis, 0, sizeof(dis)); 
    memset(vis, 0, sizeof(vis)); dfs2(root1, -1); 
    node item1; item1.index = root1; item1.weight = 0; vec1.push_back(item1);
    memset(dis, 0, sizeof(dis)); 
    memset(vis, 0, sizeof(vis)); dfs3(root2, -1); 
    item1.index = root2; item1.weight = 0; vec2.push_back(item1);


    sort( vec1.begin(), vec1.end() );
    sort( vec2.begin(), vec2.end() );
    ll ans = -1;
    ll vs1 = (ll)vec1.size();
    ll vs2 = (ll)vec2.size();
    //printf("vic1 %lld\n",(ll)vec1.size());
    //printf("vic2 %lld\n",(ll)vec2.size());
    for ( int i = 0, j = 0; i < vs1, j < vs2; i ++, j ++ )
    {
        ans = max(ans, min( vec1[i].weight, vec2[j].weight ));
    } 
    //for ( ll i = 1; i <= n; i ++ ) printf("way = %lld\n", dis[i]);

    printf("%lld\n", ans + dis[root1] );
    //cout << root1<<"->" << root2<<endl;
    //fclose(stdin);

    return 0;
}
