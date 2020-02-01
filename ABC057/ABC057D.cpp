#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#define N 52
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int n, a, b;
ll v[N];
ll comb[N][N];
int main() {
	cin>>n>>a>>b;
	for (int i = 0; i < n; ++i) {
		cin>>v[i];
	}
	if (a > b) {
		cout<<0<<endl;
		cout<<0<<endl;
		return 0;
	}
	for (int i = 0; i <= n; ++i) {
		comb[i][0] = 1;
		for (int j = 1; j <= i; ++j) {
			comb[i][j] = comb[i-1][j-1] + comb[i-1][j];
		}
	}
	sort(v, v+n);
	reverse(v, v+n);
	double ave = 0.0;
	for (int i = 0; i < a; ++i) {
		ave += v[i];
	}
	ave /= (double)a;
	printf("%.7lf\n", ave);
	int cnt1=0;
	int cnt2=0;
	for (int i = 0; i < n; ++i) {
		if (v[i] == v[a-1]) {
			cnt1++;
			if (i < a) {
				cnt2++;
			}
		}
	}
	ll tot=0;
	if (cnt2 == a) {
		for (int i = a; i <= b; ++i) {
			tot += comb[cnt1][i];
		}
	} else {
		tot += comb[cnt1][cnt2];
	}
	cout<<tot<<endl;
	return 0;
}
