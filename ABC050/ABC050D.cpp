#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#define N 70
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
ll n;
ll dp[N][2][2][2];
vector<int> ds;
void getds(ll x) {
	for (int i = 0; i <= 63; ++i) {
		ds.push_back(x%2);
		x /= 2;
	}
	reverse(ds.begin(), ds.end());
}
ll dfs(int cur, int f1, int f2, int add) {
	if (cur > 63) {
		if (!add) return 1;
		return 0;
	}
	if (dp[cur][f1][f2][add] >= 0) return dp[cur][f1][f2][add];
	dp[cur][f1][f2][add] = 0;
	for (int d1 = 0; d1 < 2; ++d1) {
		for (int d2 = 0; d2 < 2; ++d2) {
			if (cur == 0 && d1 == 0 && d2 == 1) continue;
			if (!f1 && d1 > ds[cur]) continue;
			if (!f2 && d2 > d1) continue;
			if (add && d1&&d2) continue;
			if (!add && !d1 && d2) continue;
			ll res= dfs(cur+1, f1 | (d1 < ds[cur]), f2 | (d2 < d1), (d1!=d2));
			dp[cur][f1][f2][add] = (dp[cur][f1][f2][add] + res) % mod;
		}
	}
	return dp[cur][f1][f2][add];
}
int main() {
	cin>>n;
	ds.clear();
	getds(n);
	memset(dp, -1, sizeof(dp));
	dfs(0, 0, 0, 0);
	cout<<dp[0][0][0][0]<<endl;
	return 0;
}
