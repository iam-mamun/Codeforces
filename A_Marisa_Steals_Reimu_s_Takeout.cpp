#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define int long long

void Solve()
{
    int n; cin>>n;
    int ans = 0;
    int one = 0, two = 0;
    for(int i = 0; i<n; i++) {
      int x; cin>>x;
      ans+=(x==0);
      one+=(x==1);
      two+=(x==2);
    }

    int mn = min(one, two);
    ans+=min(one, two);
    one-=mn;
    two-=mn;
    ans+=(one/3);
    ans+=(two/3);

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
