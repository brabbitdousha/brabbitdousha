#include <cstdio>
#include <algorithm>
#include <map>
#include <iostream>
#include <iterator>

using namespace std;

map<int, int> m;

int main()
{
    int n,num;
    scanf("%d",&n);
    for ( int i = 0; i < n; i++ )
    {
        scanf("%d",&num);
        /* printf("count = %ld\n",m.count(num));
        if ( !m.count(num) ) m[num] = 0; */
        m[num] ++;
    }
    /* for ( int i = 0; i < n; i++ )
    {
        printf("%d ",m[i]);
    } */
    printf("m10 = %d\n",m[10]);
    map<int, int>::iterator iter;
    iter = m.begin();
    for(iter = m.begin(); iter != m.end(); iter++) {
        cout << iter->first << " : " << iter->second << endl;
    }

    return 0;
}
