#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#define N 100002
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int n, a, b;
int x[N];
int main() {
	cin>>n>>a>>b;
	for (int i =1; i <= n; ++i) {
		cin>>x[i];
	}
	ll ans = 0LL;
	for (int i = 2; i <= n; ++i) {
		ll det = x[i]-x[i-1];
		ans += min(det * (ll)a, (ll)b);
	}
	cout<<ans<<endl;
	return 0;
}
