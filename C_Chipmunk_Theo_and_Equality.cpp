#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> v(n);

        int mn = 1e18;

        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            mn = min(mn, v[i]);
        }

        vector<int> targets;

        {
            int curr = mn;

            if(curr==1) targets.push_back(2);

            while (curr > 1)
            {
                targets.push_back(curr);

                if (curr & 1)
                {
                    curr++;
                    targets.push_back(curr);
                }

                curr /= 2;
            }

            targets.push_back(1);
        }

        int ans = 1e18;

        for (int target : targets)
        {
            int totalCost = 0;

            bool possible = true;

            for (int x : v)
            {
              //cerr<<x<<" t "<<target<<'\n';
                int curr = x;
                int steps = 0;

                while (curr != target)
                {
                    if (curr & 1)
                    {
                        curr++;
                        steps++;
                    }
                    else {
                      curr /= 2;
                      steps++;
                      if(curr==1) break;
                    }

                }
                //cerr<<steps<<" "<<curr<<" "<<target<<'\n';

                if (curr != target)
                {
                    possible = false;
                    break;
                }

                totalCost += steps;
            }

            if (possible)
            {
                ans = min(ans, totalCost);
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
