#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define int long long

/*
    Take all odd numbers:
    1 3 5 7 9 ...

    All elements are distinct.

    Adjacent sums:
    1+3 = 4
    3+5 = 8
    5+7 = 12

    Sums increase by 4 each time,
    so all adjacent sums are distinct.

*/

void Solve()
{
    int n;
    cin >> n;

    for (int i = 1; i <= 2 * n; i += 2)
    {
        cout << i << " \n"[i + 2 > 2 * n];
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int t = 1;
    cin >> t;

    for (int i = 1; i <= t; i++)
    {
        // cout << "Case #" << i << ": ";
        Solve();
    }

    return 0;
}
