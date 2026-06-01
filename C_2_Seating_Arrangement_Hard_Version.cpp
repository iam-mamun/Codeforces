#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define int long long

void Solve() {
    int n, x, s;
    cin >> n >> x >> s;

    string str;
    cin >> str;

    int introverts = count(str.begin(), str.end(), 'I');

    int ans = 0;
    int space = 0;
    int ambiInside = 0;

    for (char c : str) {
        if (c == 'I') {
            if (x) {
                --x;
                --introverts;
                ++ans;
                space += s - 1;
            }
            continue;
        }

        if (c == 'A') {
            if (x && (x - 1 >= introverts || !space)) {
                --x;
                ++ans;
                space += s - 1;
            } else if (space) {
                --space;
                ++ambiInside;
                ++ans;
            }
            continue;
        }

        if (space) {
            --space;
            ++ans;
        } else if (ambiInside && x) {
            --ambiInside;
            --x;
            ++ans;
            space += s - 1;
        }
    }

    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) Solve();

    return 0;
}
