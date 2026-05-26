#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define int long long

const int NEG = -1e16;

void Solve()
{
    int n;
    cin >> n;

    string s;
    cin >> s;

    s = " " + s;

    vector<int> a(n + 1), b(n + 1), c(n + 1);
    vector<bool> vis(n + 1);

    vis[0] = true;
    b[0] = 0;
    c[0] = -1e18;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }

    for (int i = 1; i <= n; i++)
    {
        if (c[i] != c[i - 1])
        {
            if (c[i] < c[i - 1])
            {
                cout << "No\n";
                return;
            }

            b[i] = c[i];
            vis[i] = true;

            for (int j = i; j >= 1; j--)
            {
                if (s[j] == '1') {
                    if (vis[j - 1] && b[j - 1] + a[j] != b[j])
                    {
                        cout << "No\n";
                        return;
                    }

                    b[j - 1] = b[j] - a[j];
                    vis[j - 1] = true;
                }
                else {
                    break;
                }
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (s[i] == '1')
        {
            b[i] = b[i - 1] + a[i];
            vis[i] = true;
        }

        if (!vis[i])
        {
            b[i] = NEG;
        }

        a[i] = b[i] - b[i - 1];

        if (max(c[i - 1], b[i]) != c[i])
        {
            cout << "No\n";
            return;
        }
    }

    cout << "Yes\n";

    for (int i = 1; i <= n; i++)
    {
        cout << a[i] << " \n"[i == n];
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int t = 1;
    cin >> t;

    while (t--)
    {
        Solve();
    }

    return 0;
}
