#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
string s;
int main() {
  cin>>s;
  int n = s.size();
  int cnt=0;
  int tot=0;
  for (int i = 0; i < n; ++i) {
  	if (cnt > 0) {
      cnt--;
      if (s[i] == 'g') tot++;
    } else {
      if (s[i] == 'p') tot--;
      cnt++;
    }
  }
  cout<<tot<<endl;
  return 0;
}
