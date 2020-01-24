#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#define N 100005
using namespace std;
typedef long long ll;
ll x;
int n;
int a[N];
int main() {
	cin>>n;
	map<int, int> cnt;
	cnt.clear();
	for (int i = 1; i <= n; ++i) {
		cin>>a[i];
		cnt[a[i]]++;
	}
	int num = cnt.size();
	int r = 0;
	for (auto v : cnt) {
		if (v.second > 1) {
			r += v.second-1;
		}
	}
	if (r % 2 == 0) {
		cout<<num<<endl;
	} else {
		cout<<num-1<<endl;
	}
	return 0;
}
