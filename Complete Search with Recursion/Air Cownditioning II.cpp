//problem link: https://usaco.org/index.php?page=viewproblem2&cpid=1276

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

pair<int,pair<int,int>> a[27];
int x[17],y[17],m[17],p[17],ans=INT_MAX,k,l,t[101];

void func(int i, vector<int> v){
	if(i==l){
		int ok[101]{0}, cost=0;
		bool f = true;
		for(int j: v){
			cost += m[j];
			for(int st = x[j]; st <= y[j]; st++){
				ok[st] += p[j];
			}
		}
		for(int st = 1; st < 101; st++){
			if(t[st]>ok[st]){
				f=false;
				break;
			}
		}
		if(f)ans=min(ans, cost);
		return;
	}
	
	func(i+1, v);
	v.PB(i);
	func(i+1, v);
}

void solve(){
	cin >> k >> l;
	for(int i = 0; i < k; i++){
		cin >> a[i].S.F >> a[i].S.S >> a[i].F;
		for(int j = a[i].S.F; j <= a[i].S.S; j++){
			t[j]=a[i].F;
		}
	}
	for(int i = 0; i < l; i++){
		cin >> x[i] >> y[i] >> p[i] >> m[i];
	}
	
	vector<int> v;
	func(0, v);
	cout << ans << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cout.tie(NULL), cin.tie(NULL);
	// setIO("");
	int testcase = 1;
	// cin >> testcase;
	for(int i = 1; i <= testcase; i++){
		// cout << "Case " << i << ": ";
		solve();
	}
} 	 		   			  	
