#include <cstdio>
#include <algorithm>

using namespace std;

int a[150];
int n;

int _abs(int n)
{
    if ( n < 0 ) return (-n);
    return n;
}

bool cmp( int a, int b )
{
    return _abs(a) > _abs(b);
}

int main()
{
    while ( scanf("%d", &n) != EOF && n )
    {
        for ( int i = 0; i < n; i++ ) scanf("%d",&a[i]);
        sort(a,a+n,cmp);
        for ( int i = 0; i < n - 1; i++ ) printf("%d ",a[i]);
        printf("%d\n",a[n-1]);
    }
    return 0;
}
