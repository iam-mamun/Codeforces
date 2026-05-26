#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> a(n);
        int d = 0;
        cin>>a[0];
        for(int i = 1; i<n; i++) {
          cin>>a[i];
          if(a[i] < a[i-1]) d = max(d, a[i-1] - a[i]);
        }
        for(int i = 1; i<n; i++) {
          if(a[i] < a[i-1]) {
            a[i] += d;
          }
        }
        is_sorted(a.begin(), a.end()) ? cout << "YES" << '\n' : cout << "NO" << '\n';
    }
    return 0;
}
