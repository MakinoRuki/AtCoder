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
int n;
int a[N];
ll getres(ll x) {
	ll tot=abs(a[0]-x);
	ll pre=x;
	for (int i = 1; i < n; ++i) {
		int sum=pre+a[i];
		if (i % 2 == 0) {
			if (x > 0 && sum > 0) {
				pre = sum;
				continue;
			} else if (x < 0 && sum < 0) {
				pre = sum;
				continue;
			} else {
				if (x > 0) {
					tot += abs(sum-1);
					pre=1;
				} else {
					tot += abs(sum+1);
					pre=-1;
				}
			}
		} else {
			if (x > 0 && sum < 0) {
				pre=sum;
				continue;
			} else if (x < 0 && sum > 0) {
				pre=sum;
				continue;
			} else {
				if (x > 0) {
					tot += abs(sum+1);
					pre=-1;
				} else {
					tot += abs(sum-1);
					pre=1;
				}
			}
		}
	}
	return tot;
}
int main() {
	cin>>n;
	for (int i = 0; i < n; ++i) {
		cin>>a[i];
	}
	ll res;
	res=getres(1);
	res=min(res,getres(-1));
	if (a[0] != 0) {
		res=min(res,getres(a[0]));
	}
	cout<<res<<endl;
	return 0;
}
