#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define int long long

void Solve()
{
    int n, x, y, k; cin>>n>>x>>y>>k;

    int ans = 0;
    int d = abs(y-x);
    int rd = n - d;
    if(n<=3){
      cout<<1<<"\n";
      return;
    }
    ans+=(min(d, rd) + k);

    cout<<ans<<'\n';
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
