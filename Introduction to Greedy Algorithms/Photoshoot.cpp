// problem link: https://usaco.org/index.php?page=viewproblem2&cpid=1227
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
	int n, ans = 0; cin >> n;
	string s; cin >> s;
	for(int i = n - 2; i >= 0; i-=2){
		string x = s.substr(i, 2);
		// odd ans means that the order change, otherwise it's the same
		if(x == "GH" && ans % 2 == 0){
			ans++;
		}else if(x == "HG" && ans % 2 == 1){
			ans++;
		}
	}
	cout << ans << '\n';
}
 
signed main(){
	ios_base::sync_with_stdio(false), cout.tie(NULL), cin.tie(NULL);
	// setIO("");
	int testcase = 1;
	// cin >> testcase;
	for(int i = 1; i <= testcase; i++){
		// cout << "Case " << i << ": ";
		solve();
	}
}
