#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <algorithm>
#define N 100005
using namespace std;
typedef long long ll;
int n, a, b;
int h[N];
int main() {
	cin>>n>>a>>b;
	for (int i = 1; i <= n; ++i) {
		cin>>h[i];
	}
	int l = 0, r = 1000000000;
	int c = a-b;
	while(l < r) {
		int mid = (l+r)/2;
		ll cnt=0;
		for (int i =1; i <= n; ++i) {
			ll det = h[i] - (ll)mid * (ll)b;
			if (det > 0) {
				cnt += (det + c-1) /c;
			}
		}
		if (cnt <= mid) {
			r = mid;
		} else {
			l = mid+1;
		}
	}
	cout<<r<<endl;
	return 0;
}
