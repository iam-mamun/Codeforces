#include<bits/stdc++.h>
using namespace std;

#define int long long

int32_t main() {

	int t; cin>>t;
	while(t--) {

		int n; cin>>n;
		vector<int>h(n);
		for(int i = 0; i<n; i++) {
			cin>>h[i];
		}

		
		for(int i = 0; i<n; i++) {

			vector<int>w(n, LLONG_MAX);
			w[i] = 0;
			int mx = LLONG_MIN;
			for(int j = 1; j<n; j++) {
				int pipe = (i+j-1)%n;
				int vessel = (i+j)%n;
				mx = max(h[pipe], mx);
				w[vessel] = min(mx, w[vessel]);
			}
			int mx2 = LLONG_MIN;
			for(int j = 1; j<n; j++) {
				int pipe = (i - j + n) % n;
				int vessel = (i - j + n)%n;
				mx2 = max(h[pipe], mx2);
				w[vessel] = min(w[vessel], mx2);
			}

			int sum = 0;
			for(int j = 0; j<n; j++) {
				sum+=w[j];
			}
			cout<<sum<<" \n"[i==n-1];
		}
	}
}