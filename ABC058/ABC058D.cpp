#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#define N 100005
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int n, m;
ll x[N], y[N];
int main() {
	cin>>n>>m;
	ll totx = 0;
	ll toty = 0;
	for (int i = 0; i < n; ++i) {
		cin>>x[i];
		if (i> 0) {
			totx = (totx + (x[i]-x[i-1])*(ll)i%mod*(ll)(n-i)%mod) % mod;
		}
	}
	for (int j = 0; j < m; ++j) {
		cin>>y[j];
		if (j > 0) {
			toty = (toty + (y[j]-y[j-1])*(ll)j%mod*(ll)(m-j)%mod) % mod;
		}
	}
	cout<<totx*toty%mod<<endl;
	return 0;
}
