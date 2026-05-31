#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define int long long

void Solve()
{
    int n; cin>>n;
    vector<int>v(n);
    vector<int>ans;
    for(int i = 0; i<n; i++) cin >> v[i];
    int sum = 0;
    int mn = INT_MAX;
    for(int i = 0; i<n; i++) {
      sum += v[i];
      int add = min(sum/(i+1), mn);
      ans.push_back(add);
      mn = min(mn, add);
    }

    for(int i = 0; i<n; i++) cout << ans[i] << " \n"[i==n-1];

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
