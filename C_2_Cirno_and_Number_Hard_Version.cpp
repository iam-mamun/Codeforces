#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define int long long

void Solve()
{
    int a, n;
    cin >> a >> n;

    vector<int> d(n);
    for (auto &x : d) cin >> x;

    int ans = LLONG_MAX;
    int L = to_string(a).size();

    auto power = [&](int b, int e)
    {
        int res = 1;
        while (e--) res *= b;
        return res;
    };

    /* returns rank-th number with 'len' digits
       It first uses n-base number system to generate number with allowed digit (like bitmasking to generate subdequence)
       As the numbers in n-nbase system always increasing and allowed digits d also increasing then rank1<rank2 or generated
       number from rank1 is less than generated number from rank2.
       if n = 3  and allowed digit [1,5,7] then 000 present smallest number 111. 1 here is from 0-th index digit from allowed digit d[]
    */

    auto get = [&](int rank, int len)
    {
        vector<int> dig(len);
        // generating the n-base number
        for (int i = len - 1; i >= 0; i--)
        {
            dig[i] = rank % n;
            rank /= n;
        }

        //converting n-base rank to number
        int num = 0;

        for (int x : dig)
            num = num * 10 + d[x];

        return num;
    };

    auto solveLen = [&](int len)
    {
        if(len<=0) return; //as in constrains a single digit number

        int total = power(n, len);

        int lo = 0;
        int hi = total - 1;

        int pos = total;
        //lower bound or finding first or smallest number >= a
        while (lo <= hi)
        {
            int mid = (lo + hi) / 2;

            if (get(mid, len) >= a)
            {
                pos = mid;
                hi = mid - 1;
            }
            else
            {
                lo = mid + 1;
            }
        }

        ans = min(ans, abs(a - get(pos, len)));

        if(pos>0) ans = min(ans, abs(a - get(pos - 1, len)));
    };
    solveLen(L - 1);
    solveLen(L);
    solveLen(L + 1);
    cout << ans << '\n';
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
