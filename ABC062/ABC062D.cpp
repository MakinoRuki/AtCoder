#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <set>
#include <algorithm>
#define N 300005
using namespace std;
typedef long long ll;
int n;
int a[N];
ll ls[N], rs[N];
int main() {
	cin>>n;
	for (int i = 1; i <= 3*n; ++i) {
		cin>>a[i];
	}
	ll ans = 0LL-1000000000000000000LL;
	set<pair<ll, int>> ss;
	ll sum=0LL;
	for (int i = 1; i <= 3*n; ++i) {
		ls[i] = ans;
		rs[i] = -ans;
	}
	for (int i = 1; i <= 3*n; ++i) {
		ss.insert(make_pair(a[i], i));
		sum += (ll)a[i];
		while(ss.size() > n) {
			sum -= (*ss.begin()).first;
			ss.erase(*ss.begin());
		}
		if (ss.size() == n)ls[i] = sum;
	}
	for (int i = 2; i <= 3*n; ++i) {
		ls[i] = max(ls[i], ls[i-1]);
		//cout<<i<<" "<<ls[i]<<endl;
	}
	ss.clear();
	sum = 0LL;
	for (int i = 3*n; i >= 1; --i) {
		ss.insert(make_pair(a[i], i));
		sum += a[i];
		while(ss.size() > n) {
			sum -= (*ss.rbegin()).first;
			ss.erase(*ss.rbegin());
		}
		if (ss.size() == n)rs[i] = sum;
	}
	for (int i = 3*n-1; i >= 1; --i) {
		rs[i] = min(rs[i+1], rs[i]);
		//cout<<i<<" "<<rs[i]<<endl;
	}
	for (int i = 1; i < 3*n; ++i) {
		if (ls[i] > 0LL-1000000000000000000LL && rs[i+1] < 1000000000000000000LL) {
			ans = max(ans, ls[i]-rs[i+1]);
		}
	}
	cout<<ans<<endl;
	return 0;
}
