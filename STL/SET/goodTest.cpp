//UVA12096
//use SET and STACK
#include <bits/stdc++.h>

using namespace std;
#define ALL(x) x.begin(), x.end()
#define INS(x) inserter(x, x.begin())

typedef set<int> Set;
map <Set, int> IDcache;
vector<Set> Setcache;

int T, n;

/* 
    set_union(...)和set_insertsection(...)用法
    第一个集合的头和尾 x1.begin(), x1.end()
    第二个集合的头和尾 x2.begin(), x2.end()
    最后一个参数，一般情况为inserter(C1, C1.begin()).   意思是将第一个集合和第二个集合取并集后存在集合C中
 */

int ID ( Set x )
{
    if ( IDcache.count(x) ) return IDcache[x];
    Setcache.push_back(x);
    return IDcache[x] = Setcache.size() - 1;
}

int main()
{
    freopen("out","w",stdout);
    scanf("%d",&T);
    while ( T -- )
    {
        stack<int> s;
        scanf("%d",&n);
        for ( int i = 0; i < n; i ++ ) 
        {
            /* scanf("%s",cmd);
            printf("%s\n",cmd); */
            string cmd;
            cin >> cmd;
            //cout << cmd;
            if ( cmd[0] == 'P' ) 
            {
                //printf("hello\n");
                s.push(ID(Set()));
            }
            else if ( cmd[0] == 'D' ) s.push(s.top());
            else
            {
                Set x1 = Setcache[s.top()]; s.pop();
                Set x2 = Setcache[s.top()]; s.pop();
                Set x;
                if ( cmd == "UNION" ) set_union( ALL(x1), ALL(x2), INS(x) );
                if ( cmd == "INTERSECT" ) set_intersection( ALL(x1), ALL(x2), INS(x) );
                if ( cmd == "ADD" ) 
                {
                    x = x2;
                    x.insert( ID(x1) );
                }
                s.push(ID(x));
            }
            //printf("hello%d\n",i);
            cout << Setcache[s.top()].size()<<endl; 
        }
        printf("***\n");
    }
    fclose(stdout);
    return 0;
}
