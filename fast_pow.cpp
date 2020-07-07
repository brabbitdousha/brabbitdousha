#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long int ll;

ll square ( ll x ) { return x * x; }

ll fast_expt_and_mod( ll b, ll n, ll mod )
{
    if ( n == 0 ) return 1;
    else if ( n % 2 == 0 ) return square( fast_expt_and_mod( b, n >> 1, mod ) ) % mod;
    return b * fast_expt_and_mod( b, n - 1, mod ) % mod;
}

ll fast_expt( ll b, ll n, ll mod )
{
    if ( n == 0 ) return 1;
    else if ( n % 2 == 0 ) return (int)pow( fast_expt( b, n >> 1, mod ), 2 );
    return b * fast_expt( b, n - 1, mod );
}

ll fast_expt2( ll b, ll n, ll mod )
{
    ll ans = 1;
    while(n > 0)
    {
		if(n & 1)
        {
			ans *= b;
            ans %= mod;
    	}
		
        b = b * b % mod;
		n >>= 1;
	}
    return ans;
}

int main()
{
    ll b, p, k;
    scanf("%lld %lld %lld", &b, &p, &k);
    //printf("%lld\n", fast_expt(b, p, k));

    printf ( "%lld^%lld mod %lld=%lld\n", b,p,k, fast_expt2(b, p, k) % k);
    return 0;
}

