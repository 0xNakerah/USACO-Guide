// problem link: https://usaco.org/index.php?page=viewproblem2&cpid=989
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
	int k, n, t, up_dist, low_dist; cin >> k >> n;
	int a[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
		up_dist = low_dist = t = 0;
		
		for(int speed = 1; ; speed++){
			up_dist += speed;
			t++;
			if(up_dist + low_dist >= k){
				break;
			}
			
			if(speed >= a[i]){
				low_dist += speed;
				t++;
			}
			if(up_dist + low_dist >= k){
				break;
			}
		}
		
		a[i] = t;
	}
	for(int i = 0; i < n; i++){
		cout << a[i] << '\n';
	}
}
 
signed main(){
	ios_base::sync_with_stdio(false), cout.tie(NULL), cin.tie(NULL);
	setIO("race");
	int testcase = 1;
	// cin >> testcase;
	for(int i = 1; i <= testcase; i++){
		// cout << "Case " << i << ": ";
		solve();
	}
}
