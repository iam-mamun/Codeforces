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

    vector<int> pref(n), suff(n);

    pref[0] = abs(a[0]);

    for (int i=1; i<n; i++)
    {
        pref[i] = pref[i - 1] + abs(a[i]);
    }

    suff[n - 1] = a[n - 1];

    for (int i=n-2; i>=0; i--)
    {
        suff[i] = suff[i + 1] + a[i];
    }

    int best = suff[0];
    int idx = -1;

    for (int i=0; i<n; i++)
    {
        if (a[i] > 0)
        {
            int curr = -a[i];

            if (i > 0)
            {
                curr += pref[i - 1];
            }

            if (i + 1 < n)
            {
                curr += suff[i + 1];
            }

            if (curr > best)
            {
                best = curr;
                idx = i;
            }
        }
    }

    if (idx == -1)
    {
        cout << 0 << "\n\n";
        return;
    }

    vector<int> ans;

    int flag = 0;

    for (int i=idx-1; i>=0; i--)
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

    ans.push_back(idx + 1);


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
        Solve();
    }

    return 0;
}
