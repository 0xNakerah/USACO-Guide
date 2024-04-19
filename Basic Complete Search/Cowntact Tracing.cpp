//problem link: https://usaco.org/index.php?page=viewproblem2&cpid=1037

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
	int n,t; cin >> n >> t;
	string s; cin >> s;
	vector<pair<int,pair<int,int>>> v(t);
	for(int i = 0; i < t; i++){
		cin >> v[i].F >> v[i].S.F >> v[i].S.S;
		v[i].S.F--, v[i].S.S--;
	}
	sort(all(v));
	
	int x=0,y=INT_MAX,z=0;
	bool ok[n]{0};
	for(int i = 0; i < n; i++){
		if(s[i]=='0')continue;
		
		for(int k = 0; k <= t+1; k++){
			int cnt[n]{0};
			cnt[i]=k;
			string tst = string(n,'0');
			tst[i]='1';
			
			for(int j = 0; j < t; j++){
				int p1 = v[j].S.F, p2 = v[j].S.S;
				if(cnt[p1]&&cnt[p2]){
					cnt[p1]--, cnt[p2]--;
					tst[p1]=tst[p2]='1';
				}else if(cnt[p1]){
					cnt[p1]--;
					if(tst[p2]=='0'){
						cnt[p2]=k;
					}
					tst[p2]='1';
				}else if(cnt[p2]){
					cnt[p2]--;
					if(tst[p1]=='0'){
						cnt[p1]=k;
					}
					tst[p1]='1';
				}
			}
			
			if(tst==s){
				ok[i]=true;
				y=min(y,k);
				z=max(z,k);
			}
		}
	}
	
	for(int i = 0; i < n; i++){
		if(ok[i]){
			x++;
		}
	}
	
	cout << x << ' ' << y << ' ';
	if(z!=t+1)cout<<z<<'\n';
	else cout << "Infinity\n";
}

int main(){
	ios_base::sync_with_stdio(false), cout.tie(NULL), cin.tie(NULL);
	setIO("tracing");
	int testcase = 1;
	// cin >> testcase;
	for(int i = 1; i <= testcase; i++){
		// cout << "Case " << i << ": ";
		solve();
	}
} 	 		   			  	
