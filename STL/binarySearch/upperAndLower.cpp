#include <bits/stdc++.h>

using namespace std;

int n;
int a[1000];
vector<int> arr;

int main()
{
    scanf("%d", &n);
    int num;
    for ( int i = 0; i < n; i++ )
    {
        scanf("%d", &num);
        arr.push_back(num);
        a[i] = num;
    }
    sort(a, a + n);
    sort(arr.begin(), arr.end());

    for ( int i = 0; i < n; i++ ) printf("%d ", a[i]);
    printf("\n");

    vector<int>::iterator ite;

    for ( ite = arr.begin(); ite != arr.end(); ite ++ ) cout << *ite <<' ';
    printf("\n");

    int pos = lower_bound(a, a + n, 3) - a;// the first position which can be insert
    printf("pos = %d\n",pos);
    pos = upper_bound(a, a + n, 3) - a;// the last postion which can be insert
    printf("pos = %d\n",pos);
    
    ite = lower_bound( arr.begin(), arr.end(), 3 );
    cout << * ite << endl;
    ite = upper_bound( arr.begin(), arr.end(), 3 );
    cout << * ite << endl;

    //printf("pos2 = %d\n",pos2);
    return 0;
}
