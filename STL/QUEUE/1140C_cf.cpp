#include <bits/stdc++.h>

using namespace std;

#define ll long long int
struct song
{
    int length;
    int bueaty;
};

bool cmp( song a, song b )
{
    return a.bueaty > b.bueaty;
}
int n;
song s[300010];

int main()
{
    ll n,k;
    scanf("%lld %lld",&n,&k);
    for ( ll i = 0; i < n; i++ )
    {
        scanf("%d %d",&s[i].length,&s[i].bueaty);
    }
    priority_queue < ll, vector<ll>, greater<ll> > q;
    sort( s, s+n, cmp );
    ll ans = 0;
    ll sum = 0;
    for ( ll i = 0; i < n; i++  )
    {
        if ( q.size() < k )
        {
            q.push(s[i].length);
            sum += s[i].length;
            ans = max( ans, sum * s[i].bueaty );
        }
        else
        {
            sum -= q.top();q.pop();
            q.push(s[i].length);
            sum += s[i].length;
            ans = max( ans, sum * s[i].bueaty );
        }
        
    }
    printf("%lld\n",ans);
    return 0;
}
