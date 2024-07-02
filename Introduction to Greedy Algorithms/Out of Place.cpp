// problem link: https://usaco.org/index.php?page=viewproblem2&cpid=785
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define PB push_back
#define sz(x) (int)x.size()
#define all(x) x.begin(),x.end()	
#define rall(x) x.rbegin(),x.rend()
#define F first
#define S second
#define PB push_back
// #define int long long
 
void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}
 
void solve(){
	int n, diff = 0; cin >> n;
	int arr[n], sor_arr[n];
	for(int i = 0; i < n; i++){
		cin >> arr[i];
		sor_arr[i] = arr[i];
	}
	sort(sor_arr, sor_arr+n);
	for(int i = 0; i < n; i++){
		diff += (arr[i] != sor_arr[i]);
	}
	cout << max(0, diff-1);
}
 
signed main(){
	ios_base::sync_with_stdio(false), cout.tie(NULL), cin.tie(NULL);
	setIO("outofplace");
	int testcase = 1;
	// cin >> testcase;
	for(int i = 1; i <= testcase; i++){
		// cout << "Case " << i << ": ";
		solve();
	}
}
