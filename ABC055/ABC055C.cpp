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
ll n, m;
int main() {
	cin>>n>>m;
	if (m >= 2 * n) {
		ll det = m - 2 * n;
		cout<<n + det/4<<endl;
	} else {
		cout<<m/2<<endl;
	}
	return 0;
}
