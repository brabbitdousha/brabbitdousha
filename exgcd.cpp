#include <bits/stdc++.h>

using namespace std;

void ex_gcd( int a, int b, int &d, int &x, int &y )
{
    if ( !b ) { d = a; x = 1; y = 0; }
    else { ex_gcd( b, a % b, d, y, x ); y -= x * ( a / b ); }
}

int main()
{

    return 0;
}
