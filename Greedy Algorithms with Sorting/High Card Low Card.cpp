// problem link: https://usaco.org/index.php?page=viewproblem2&cpid=573
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
#define int long long
 
void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}
 
void solve(){
	int n; cin >> n;
	map<int, bool> mp;
	int first_half[n/2], second_half[n/2];
	
	for(int i = 0; i < n/2; i++){
		cin >> first_half[i];
		mp[first_half[i]] = true;
	}
	for(int i = 0; i < n/2; i++){
		cin >> second_half[i];
		mp[second_half[i]] = true;
	}
	
	sort(first_half, first_half+n/2);
	sort(second_half, second_half+n/2);
	
	int ptr = 2*n, ans = 0, cnt = 0;
	while(ptr > 0 && cnt < n/2){
		if(!mp[ptr]){
			cnt++;
		}
		ptr--;
	}
	
	for(int i = n/2-1; i >= 0; i--){
		while(ptr > 0 &&  (mp[ptr] || ptr > second_half[i]) ){
			ptr--;
		}
		if(ptr > 0){
			ans++;
			mp[ptr] = true;
			ptr--;
		}
	}
	
	ptr = 1;
	for(int i = 0; i < n/2; i++){
		while(ptr <= 2*n && (mp[ptr] || ptr < first_half[i]) ){
			ptr++;
		}
		if(ptr <= 2*n){
			ans++;
			ptr++;
		}
	}
	
	cout << ans << '\n';
}
 
signed main(){
	ios_base::sync_with_stdio(false), cout.tie(NULL), cin.tie(NULL);
	setIO("cardgame");
	int testcase = 1;
	// cin >> testcase;
	for(int i = 1; i <= testcase; i++){
		// cout << "Case " << i << ": ";
		solve();
	}
}
