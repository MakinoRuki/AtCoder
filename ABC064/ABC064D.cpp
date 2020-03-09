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
string s;
int main() {
	cin>>n>>s;
	vector<char> stk;
	for (int i = 0; i < n; ++i) {
		if (s[i] == '(') stk.push_back(s[i]);
		else {
			if (!stk.empty() && stk.back() == '(') stk.pop_back();
			else {
				stk.push_back(')');
			}
		}
	}
	int lcnt = 0;
	int rcnt=0;
	for (int i = 0; i < stk.size(); ++i) {
		if (stk[i] == ')') rcnt++;
		else break;
	}
	for (int i = stk.size()-1; i >= 0; --i) {
		if (stk[i] == '(') lcnt++;
		else break;
	}
	if (rcnt) {
		s = string(rcnt, '(') + s;
	}
	if (lcnt) {
		s = s + string(lcnt, ')');
	}
	cout<<s<<endl;
	return 0;
}
