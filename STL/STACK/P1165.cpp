#include <bits/stdc++.h>

using namespace std;

int n;
stack<int> s;

int main()
{
    scanf("%d",&n);
    int num1, num2;
    for ( int i = 0; i < n; i ++ )
    {
        scanf("%d",&num1);
        if ( num1 == 0 )
        {
            scanf("%d",&num2);
            if ( s.empty() ) 
            {
                s.push(num2);
                continue;
            }
            int item = s.top();
            if ( num2 > item ) s.push(num2);
            else if ( num2 < item ) s.push(item);
            //printf("hello\n");
        }
        else if ( num1 == 1 )
        {
            if ( s.empty() ) continue;
            else s.pop();
        }
        else if ( num1 == 2 )
        {
            if ( s.empty() ) printf("0\n");
            else 
            {
                int item = s.top();
                printf("%d\n", item);
            }
        }
    }
    return 0;   
}
