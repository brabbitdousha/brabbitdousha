#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <set>

using namespace std;


int main()
{
    int n;
    while ( cin>>n && n)    
    {
        string win,lose;
        set<string> all,loser;
        while ( n -- )
        {
            //scanf( "%s %s",win,lose );
            cin >> win >> lose;
            all.insert(win);
            all.insert(lose);
            loser.insert(lose);
        }
        if ( all.size() - loser.size() == 1 ) printf("Yes\n");
        else printf("No\n");
    }

    return 0;
}
