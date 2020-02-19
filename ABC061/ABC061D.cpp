// bellman-ford找负环以及负环上的点。

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <algorithm>
#define N 1002
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int n, m;
vector<pair<pair<int, int>, ll>> edges;
ll dis[N];
int main() {
	cin>>n>>m;
	for (int i = 1; i <= m; ++i) {
		int a, b, c;
		cin>>a>>b>>c;
		edges.push_back(make_pair(make_pair(a, b), -c));
	}
	for (int i = 1; i <= n; ++i) {
		dis[i] = (i == 1 ? 0 : 1000000000000000000LL);
	}
	for (int i = 1; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			int a = edges[j].first.first;
			int b = edges[j].first.second;
			ll c = edges[j].second;
			if (dis[a] >= 1000000000000000000LL) continue;
			if (dis[b] > dis[a] + c) {
				dis[b] = dis[a] + c;
			}
		}
	}
	bool neg[N];
	memset(neg, false, sizeof(neg));
	for (int i = 1; i <= n; ++i) {
		for (int j=0; j < m; ++j) {
			int a = edges[j].first.first;
			int b = edges[j].first.second;
			ll c = edges[j].second;
			if (dis[a] >= 1000000000000000000LL) continue;
			if (dis[b] > dis[a] + c) {
				neg[b] = true;
			}
			neg[b] |= neg[a];
		}
	}
	if (neg[n]) {
		cout<<"inf"<<endl;
	} else {
		cout<<-dis[n]<<endl;
	}
	return 0;
}
