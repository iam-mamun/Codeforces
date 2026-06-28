#include<bits/stdc++.h>
using namespace std;
#define int long long
/*
Fibonacci sequence:
fib[i] = fib[i-1] + fib[i-2];

we write it, C = aK + reminder; but in this case a can be > 1

so C % ak = reminder or fib[i] % fib[i-1] = fib[i-2]

*/
void solve() {
	int n; cin>>n;
	vector<int>v(n);
	for(int i = 0; i<n; i++) {
		cin>>v[i];
	}
	sort(v.begin(), v.end());


	for(int i = n-1; i>=2; i--) {
		if(v[i]%v[i-1] != v[i-2]) {
			cout<<"-1"<<'\n';
			return;
		}
	}
	
	cout<<v[n-1]<<" "<<v[n-2]<<'\n';
}
int32_t main() {
	int t; cin>>t;
	for(int ts = 1; ts<=t; ts++) {
		solve();
	}
}