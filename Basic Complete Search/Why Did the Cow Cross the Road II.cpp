//problem link: https://usaco.org/index.php?page=viewproblem2&cpid=712

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
	string s; cin >> s;
	int ans = 0;
	vector<int> idx[26];
	for(int i = 0; i < 52; i++){
		idx[s[i]-'A'].PB(i);
	}
	
	for(int i = 0; i < 52; i++){
		if(i==idx[s[i]-'A'][1])continue;
		
		for(int j = i+1; j < idx[s[i]-'A'][1]; j++){
			if(idx[s[j]-'A'][1]>idx[s[i]-'A'][1]){
				ans++;
			}
		}
		
	}
	cout << ans << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cout.tie(NULL), cin.tie(NULL);
	setIO("circlecross");
	int testcase = 1;
	// cin >> testcase;
	for(int i = 1; i <= testcase; i++){
		// cout << "Case " << i << ": ";
		solve();
	}
} 	 		   			  	
