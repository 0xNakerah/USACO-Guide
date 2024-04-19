//problem link: https://usaco.org/index.php?page=viewproblem2&cpid=736

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

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

void solve(){
	int n,m; cin >> n >> m;
	string a[n*2];
	for(int i = 0; i < 2*n; i++){
		cin >> a[i];
	}
	
	int ans = 0;
	for(int i = 0; i < m; i++){
		map<char,bool> mp;
		for(int j = 0; j < n; j++){
			mp[a[j][i]]=true;
		}
		
		bool ok = true;
		for(int j = n; j < 2*n; j++){
			if(mp[a[j][i]]){
				ok = false;
				break;
			}
		}
		if(ok)ans++;
	}
	cout << ans << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cout.tie(NULL), cin.tie(NULL);
	setIO("cownomics");
	int testcase = 1;
	// cin >> testcase;
	for(int i = 1; i <= testcase; i++){
		// cout << "Case " << i << ": ";
		solve();
	}
} 	 		   			  	
