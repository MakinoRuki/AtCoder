#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
using namespace std;
int sx, sy;
int tx, ty;
int main() {
	cin>>sx>>sy>>tx>>ty;
	string ans="";
	for (int i = 1; i <= tx- sx; ++i) {
		ans += "R";
	}
	for (int i = 1; i <= ty-sy; ++i) {
		ans += "U";
	}
	ans += "R";
	for (int i = 1; i <= ty - sy; ++i) {
		ans += "D";
	}
	ans += "D";
	ans += "L";
	for (int i = 1; i <= tx - sx; ++i) {
		ans +="L";
	}
	ans += "U";
	for (int i = 1; i <= ty - sy; ++i) {
		ans +="U";
	}
	for (int i =1;i<=tx-sx; ++i) {
		ans +="R";
	}
	ans += "U";
	for (int i = 1; i <= tx-sx;++i) {
		ans += "L";
	}
	ans += "LD";
	for (int i = 1; i <= ty-sy; ++i) {
		ans += "D";
	}
	ans += "R";
	cout<<ans<<endl;
	return 0;
}
