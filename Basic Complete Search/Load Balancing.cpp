//problem link: https://usaco.org/index.php?page=viewproblem2&cpid=617

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
	int n,b; cin >> n >> b;
	int x[n], y[n];
	for(int i = 0; i < n; i++){
		cin >> x[i] >> y[i];
	}
	
	int ans = INT_MAX;
	for(int i = 0; i < n; i++){
		int a = x[i]+1;
		for(int j = 0; j < n; j++){
			int b = y[j]+1;
			int freq[4]{0};
			for(int k = 0; k < n; k++){
				if(x[k]>a){
					if(y[k]>b){
						freq[0]++;
					}else{
						freq[3]++;
					}
				}else{
					if(y[k]>b){
						freq[1]++;
					}else{
						freq[2]++;
					}
				}
			}
			ans = min(ans, max({freq[0],freq[1],freq[2],freq[3]}));
		}
	}
	cout << ans << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cout.tie(NULL), cin.tie(NULL);
	setIO("balancing");
	int testcase = 1;
	// cin >> testcase;
	for(int i = 1; i <= testcase; i++){
		// cout << "Case " << i << ": ";
		solve();
	}
} 	 		   			  	
