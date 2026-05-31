#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define int long long

void Solve()
{
    int n, x, s; cin>>n>>x>>s;
    string str; cin >> str;
    int eCnt = 0, aCnt = 0, Icnt = 0;
    for(int i = 0; i<n; i++) {
      if(str[i] == 'E' && (aCnt || Icnt)) eCnt++;
      if(str[i] == 'A') {
        aCnt++;
      }
      if(str[i] == 'I') Icnt++;
    }



    int ans = 0;
    int space = 0;
    aCnt = 0;
    for(int i = 0; i<n;  i++) {
      if(str[i]=='I') {
        if(x) {
          ans += 1;
          x--;
          space += (s-1);
          Icnt--;
        }
      }
      else {
        if(str[i] == 'A') {

          if(x && (x - 1 >= Icnt || !space)) {
            x--;
            space += (s-1);
            ans++;
          }
          else {
              if(space){
                aCnt++;
                space--;
                ans++;
              }
          }
        }
        else if(str[i] == 'E') {
          if(space) {
            space--;
            ans++;
          }else if(aCnt && x) {
            space+=(s-1);
            aCnt--;
            ans++;
            x--;
          }
        }

      }
    }

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
