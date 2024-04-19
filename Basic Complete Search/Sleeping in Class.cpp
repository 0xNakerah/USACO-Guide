//problem link: https://usaco.org/index.php?page=viewproblem2&cpid=1203

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
	int n; cin >> n;
	int a[n], pre[n]{0};
	for(int i = 0; i < n; i++){
		cin >> a[i];
		pre[i] = a[i];
		if(i)pre[i]+=pre[i-1];
	}
	
	int ans = n-1;
	for(int i = 0; i < n; i++){
		int c = i, s = 0, cnt = 0;
		bool ok = true;
		for(int j = i + 1; j < n; j++){
			if(s+a[j]<pre[i]){
				cnt++;
				s+=a[j];
			}else if(s+a[j]==pre[i]){
				s=0;
				c+=cnt;
				cnt=0;
			}else{
				s=INT_MAX;
				ok = false;
				break;
			}
		}
		if(ok&&!s)ans=min(ans, c);
	}
	cout << ans << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cout.tie(NULL), cin.tie(NULL);
	// setIO("");
	int testcase = 1;
	cin >> testcase;
	for(int i = 1; i <= testcase; i++){
		// cout << "Case " << i << ": ";
		solve();
	}
} 	 		   			  	
