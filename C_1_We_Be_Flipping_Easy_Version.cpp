#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define int long long

void Solve()
{
    int n;
    cin >> n;

    vector<int> a(n);

    for (int i=0; i<n; i++)
    {
        cin >> a[i];
    }

    vector<int> ans;

    int flag = 0;

    for (int i=n-1; i>=0; i--)
    {
        int curr = a[i];

        if (flag & 1)
        {
            curr = -curr;
        }

        if (curr > 0)
        {
            ans.push_back(i + 1);
            flag++;
        }
    }

    cout << ans.size() << "\n";

    for (auto x : ans)
    {
        cout << x << " ";
    }

    cout << "\n";
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
