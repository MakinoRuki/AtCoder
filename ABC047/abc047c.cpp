#include <iostream>
#include <cstdio>
#include <cstring>
#define N 102
using namespace std;
string s;
int main() {
  cin>>s;
  int n = s.size();
  int cnt=0;
  for (int i = 0; i < n; ++i) {
    if (i == 0) {
      cnt++;
    } else {
      if (s[i] != s[i-1]) cnt++;
    }
  }
  cout<<cnt-1<<endl;
  return 0;
}
