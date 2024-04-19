//problem link: https://usaco.org/index.php?page=viewproblem2&cpid=965

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
	vector<pair<string,string>> req(n);
	string a,b;
	for(int i = 0; i < n; i++){
		cin >> a >> b >> b >> b >> b >> b;
		req[i].F=a, req[i].S=b;
	}
	
	vector<string> v;
	v.PB("Bessie");
	v.PB("Buttercup");
	v.PB("Belinda");
	v.PB("Beatrice");
	v.PB("Bella");
	v.PB("Blue");
	v.PB("Betsy");
	v.PB("Sue");
	sort(all(v));
	
	do{
		bool ok = true;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < 8; j++){
				if(v[j]==req[i].F){
					bool f = false;
					if(j&&v[j-1]==req[i].S)f=true;
					if(j+1<8&&v[j+1]==req[i].S)f=true;
					if(!f){
						ok=false;
					}
				}
			}
		}
		if(ok)break;
	}while(next_permutation(all(v)));
	
	for(string &c: v)cout << c << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cout.tie(NULL), cin.tie(NULL);
	setIO("lineup");
	int testcase = 1;
	// cin >> testcase;
	for(int i = 1; i <= testcase; i++){
		// cout << "Case " << i << ": ";
		solve();
	}
} 	 		   			  	
