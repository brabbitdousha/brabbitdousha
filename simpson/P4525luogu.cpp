#include <bits/stdc++.h>

using namespace std;

double a, b, c, d, l, r;

double f( double x )
{
    return ( c * x + d ) / ( a * x + b );
}

double simpson( double l, double r )
{
    double mid = ( l + r ) / 2;
    return ( f( l ) + 4 * f( ( l + r ) / 2 ) + f( r ) ) * ( r - l ) / 6;
}

double asr ( double l, double r, double eps, double ans )
{
    double mid = ( l + r ) / 2;
    double L = simpson( l, mid ), R = simpson( mid, r );
    if ( abs( L + R - ans ) <= 15 * eps ) return L + R + ( L + R - ans ) / 15;
    return asr( l, mid, eps / 2, L ) + asr ( mid, r, eps / 2, R );
}

double ans ( double l, double r, double eps )
{
    return asr( l, r, eps, simpson(l, r) );
}

int main()
{
    scanf("%lf%lf%lf%lf%lf%lf",&a,&b,&c,&d,&l,&r);
	printf("%.6lf",ans(l,r,1e-6));

    return 0;
}
