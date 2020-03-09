#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#define N 1000005
using namespace std;
typedef long long ll;
ll mod = 1000000007;
int n;
int a[102];
int cnt[10];
int main() {
	cin>>n;
	memset(cnt, 0, sizeof(cnt));
	for (int i = 1; i <= n; ++i) {
		cin>>a[i];
		if (a[i]/400 < 8) cnt[a[i]/400]++;
		else cnt[8]++;
	}
	int tot1=0;
	for (int i = 0; i < 8; ++i) {
		if (cnt[i] > 0) tot1++;
	}
  // 注意坑：正常rating一个没有的时候。
	if (tot1==0) {
		cout<<1<<" "<<cnt[8]<<endl;
	} else {
		cout<<tot1<<" "<<tot1+cnt[8]<<endl;
	}
	return 0;
}
