//problem link: https://usaco.org/index.php?page=viewproblem2&cpid=739

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
	string a[2*n];
	for(int i = 0; i < 2*n; i++){
		cin >> a[i];
	}
	
	int ans = 0;
	for(int i = 0; i < m; i++){
		for(int j = i+1; j < m; j++){
			for(int k = j+1; k < m; k++){
				map<string,bool> mp;
				for(int r = 0; r < n; r++){
					string s = string(1,a[r][i]);
					s += a[r][j];
					s += a[r][k];
					mp[s]=true;
				}
				
				int c = 0;
				for(int r = n; r < 2*n; r++){
					string s = string(1,a[r][i]);
					s += a[r][j];
					s += a[r][k];
					if(!mp[s]){
						c++;
					}
					if(c==n)ans++;
				}
			}
		}
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
