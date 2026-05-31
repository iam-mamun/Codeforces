#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define int long long

void Solve()
{
    int n; cin>>n;
    vector<int>a(n);
    for(int i = 0; i<n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    int ans = INT_MAX;
    for(int i = 0; i<n; i++) {
      int target  = a[i];
      int cost = 0;
      int last = n;
      int j = 0;
      for(; j<n; j++) {
        if(a[j]< target && j<last) {
          cost++;
          last--;
        }
        else {
         while(j<last)cost+=(a[j]!=target), j++;
        }
    }
      ans = min(ans, cost);
    }


    cout << ans << "\n";
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
