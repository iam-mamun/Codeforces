#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define int long long

void Solve()
{
    int n;
    cin >> n;

    vector<long long> a(n), b(n);

    for (int i=0; i<n; i++) cin >> a[i];
    for (int i=0; i<n; i++) cin >> b[i];

    long long sum = 0;
    long long mx = 0;

    for (int i=0; i<n; i++)
    {
        sum += max(a[i], b[i]);
        mx = max(mx, min(a[i], b[i]));
    }

    cout << sum + mx << "\n";
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
