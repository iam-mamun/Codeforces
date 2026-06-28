#include<bits/stdc++.h>
using namespace std;

#define int long long

/*
N = 12*k + reminder; hhhere reminder = a
but a must be palindrom AND  0>=remider<=11
0 to 9 and 11 is palidrom but 10 is not; so if we add 12 to it raises it to 22 (palindrom)

*/

void solve() {
	int n; cin>>n;
	int b = n/12;
	int a  = n%12;
	if(a==10){
		a+=12;
		b--;
	}
	if(b>=0)cout<<a<<" "<<b*12LL<<'\n';
	else cout<<"-1"<<'\n';
}
int32_t main() {
	int t; cin>>t;
	for(int ts = 1; ts<=t; ts++) {
		solve();
	}
}