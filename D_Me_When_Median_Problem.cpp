#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define int long long

/* for debugging*/
void printVector(vector<int>& a) {
    for (int i = 0; i < (int)a.size(); i++) {
        cerr << a[i] << " \n"[i == (int)a.size() - 1];
    }
}
/* debugging end*/

void input(vector<int>& a, int n) {
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
}

bool check(vector<int>&a, vector<int>&b, int x) {
  int n  = a.size();
  vector<int>c(n);
  for(int i = 0; i<(int)a.size(); i++) {
    c[i] = a[i] >= x;
    c[i] += b[i] >= x;
  }


  int last  = -1;
  int zCnt = 0;
  int twCnt = 0;
  for(int i = 0; i<n; i++) {
    if(c[i] == 2) {
      twCnt++;
      last = 2;
    }
    if(c[i] == 0) {
      zCnt += (last!=0);
      last = 0;
    }
  }
  // if(x==8) {
  //   printVector(c);
  //   cerr << last << "\n";
  // }
  return twCnt > zCnt;
}
void Solve()
{
    int n; cin>>n;
    vector<int>a(n);
    vector<int>b(n);
    input(a, n);
    input(b, n);
    int l = 1, r =  2*n;
    while(l <= r) {
      int mid = l + (r-l)/2;
      if(check(a, b, mid)) l = mid + 1;
      else r = mid - 1;
    }
    cout<< r <<"\n";


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
