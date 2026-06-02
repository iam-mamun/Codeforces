#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define int long long

void Solve()
{
  int a, n;
  cin >> a >> n;
  string nums = to_string(a);
  vector<int> d(n);
  for (int &x : d)
    cin >> x;
  int ans = LLONG_MAX;
  int prefix = 0;
  for (int i = 0; i < (int)nums.size(); i++)
  {
    if (count(d.begin(), d.end(), nums[i] - '0'))
    {
      prefix = prefix * 10 + (nums[i] - '0');
    }
    else
    {
      int num1 = 0, num2 = 0;
      int dsmall, dbgig;
      for (int dig : d)
      {
        if (dig < nums[i] - '0')
          dsmall = dig;
        else
        {
          dbgig = dig;
          break;
        }
      }
      num1 = prefix * 10 + dsmall;
      num2 = prefix * 10 + dbgig;
      for (int j = i + 1; j < (int)nums.size(); j++)
      {
        num1 = num1 * 10 + d[n - 1];
        num2 = num2 * 10 + d[0];
      }
      ans = min({ans, abs(a - num1), abs(a - num2)});
    }
  }

  cout << min(ans, abs(prefix-a)) << '\n';
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
