#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#define N 5005
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int n, k;
int a[N];
ll dp[N][N];
int main() {
	cin>>n>>k;
	for (int i = 0; i < n; ++i) {
		cin>>a[i];
	}
	memset(dp, 0, sizeof(dp));
	dp[0][0] = 1;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < k; ++j) {
			dp[i+1][j] += dp[i][j];
			dp[i+1][min(j+a[i],k)] += dp[i][j]; 
		}
		dp[i+1][k] += dp[i][k];
	}
	int ans=0;
	for (int i = 0; i < n; ++i) {
		ll tmp[N];
		for (int j = 0; j <= k; ++j) {
			tmp[j] = dp[n][j];
		}
		for (int j = 0; j < k; ++j) {
			if (j < k-a[i]) {
				tmp[j+a[i]] -= tmp[j];
			} else {
				if (tmp[j]) {
					ans++;
				//	cout<<i<<endl;
					break;
				}
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
