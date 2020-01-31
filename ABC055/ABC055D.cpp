#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#define N 100005
using namespace std;
typedef long long ll;
int n;
string s;
string getres(char a, char b) {
	string res(n, ' ');
	res[0]= a;
	res[n-1] = b;
	for (int i = 0; i < n; ++i) {
		int j = (i+1) % n;
		int k = (i-1+n)%n;
		char nxt;
		if (res[i] == 'S') {
			if (s[i] == 'o') {
				nxt = res[k];
			} else {
				nxt = (res[k] == 'S' ? 'W' : 'S');
			}
		} else {
			if (s[i] == 'x') {
				nxt = res[k];
			} else {
				nxt = (res[k] == 'S' ? 'W' : 'S');
			}
		}
		if (res[j] != ' ') {
			if (res[j] != nxt) return "";
		} else {
			res[j] = nxt;
		}
	}
	return res;
}
int main() {
	cin>>n>>s;
	string res=getres('S', 'S');
	if (!res.empty()) {
		cout<<res<<endl;
	} else {
		res = getres('S', 'W');
		if (!res.empty()) {
			cout<<res<<endl;
		} else {
			res= getres('W', 'S');
			if (!res.empty()) {
				cout<<res<<endl;
			} else {
				res = getres('W', 'W');
				if (!res.empty()) {
					cout<<res<<endl;
				} else {
					cout<<-1<<endl;
				}
			}
		}
	}
	return 0;
}
