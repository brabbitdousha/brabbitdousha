#include <bits/stdc++.h>

using namespace std;
#define EPS 1e-7

int n;
double alpha;

struct node
{
    double x, r;
} p[1000];

struct tan_line
{
    double k, b, left, right;
} q[1200];

double gougu( double a, double b )
{
    return sqrt( a * a - b * b );
}



void get_tan( int x, int y )
{
    if ( fabs( p[x].r - p[y].r ) < EPS )
    {
        q[x].left = p[x].x;
        q[x].right = p[y].x;
        q[x].k = 0; q[x].b = p[x].r;
        return ;
    }

    double dx = p[y].x - p[x].x;
    double dr = fabs( p[x].r - p[y].r );
    double ly, ry;
    if ( p[x].r > p[y].r )
    {
        q[x].left = p[x].x + p[x].r * dr / dx;
        q[x].right = p[y].x + ( q[x].left - p[x].x ) * p[y].r / p[x].r;
        ly = gougu( p[x].r, q[x].left - p[x].x );
        ry = gougu( p[y].r, q[x].right - p[y].x );
        q[x].k = ( ly - ry ) / ( q[x].left - q[x].right );
        q[x].b = ly - q[x].left * q[x].k;
        
    }

    else
    {
        q[x].right = p[y].x - p[y].r * dr / dx;
        q[x].left = p[x].x - ( p[y].x - q[x].right ) * p[x].r / p[y].r;
        ly = gougu( p[x].r, q[x].left - p[x].x );
        ry = gougu( p[y].r, q[x].right - p[y].x );
        q[x].k = ( ly - ry ) / ( q[x].left - q[x].right );
        q[x].b = ly - q[x].left * q[x].k;
    }
    
}

double f( double x )
{
    double ans = 0.0;
    for ( int i = 1; i <= n; i ++ )
    {
        if ( x < p[i].x + p[i].r && x > p[i].x - p[i].r )
        {
            ans = max( ans, gougu( p[i].r, x - p[i].x ) );
        }
    }
    for ( int i = 1; i <= n; i ++ )
    {
        if ( x >= q[i].left && x <= q[i].right )
        {
            ans = max( ans, q[i].k * x + q[i].b );
        }
    }
    return ans;
}

double simpson( double l, double r )
{
    double mid = ( l + r ) / 2;
    return ( f( l ) + 4 * f( ( l + r ) / 2 ) + f( r ) ) * ( r - l ) / 6;
}

double asr(double l, double r, double eqs, double ans) 
{
    double mid = (l + r) / 2;
    double fl = simpson(l, mid), fr = simpson(mid, r);
    if ( abs(fl + fr - ans) <=  eqs  ) return fl + fr +  (fl + fr - ans) / 15;  
    return asr(l, mid, eqs , fl) + asr(mid, r, eqs, fr); 
}

double ans ( double l, double r, double eps )
{return asr( l, r, eps, simpson(l, r) );}



int main()
{
    scanf("%d %lf", &n, &alpha);
    alpha = 1.0 / tan(alpha);
    scanf("%lf", &p[1].x);
    p[1].x *= alpha;
    for ( int i = 2; i <= n + 1; i ++ ) 
    {
        scanf("%lf", &p[i].x);
        p[i].x *= alpha;
        p[i].x += p[i-1].x;
    }
    for ( int i = 1; i <= n; i ++ ) scanf("%lf", &p[i].r);
    n ++;
    p[n].r = 0.0;
    for ( int i = 1; i <= n - 1; i ++ ) get_tan( i, i + 1 );
    double ll = p[1].x - p[1].r, rr = p[n].x;
    for ( int i = 1; i <= n; i ++ )
    {
        rr = max(rr, p[i].x + p[i].r);
        ll = min(ll, p[i].x - p[i].r);
    }
    printf("%.2lf\n", 2.0 * ans( ll, rr, EPS ));

    return 0;
}
