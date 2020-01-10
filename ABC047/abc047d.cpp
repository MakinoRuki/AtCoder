#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
#define N 100005
using namespace std;
int n, t;
int a[N];
int main() {
  cin>>n>>t;
  for (int i = 0; i < n; ++i) {
    cin>>a[i];
  }
  int minv = 2000000000;
  int maxv = 0;
  for (int i = 0; i < n; ++i) {
    if (i == 0) {
      minv = min(minv, a[i]);
    } else {
      maxv = max(maxv, a[i] - minv);
      minv = min(minv, a[i]);
    }
  }
  int tot=0;
  minv = 2000000000;
  for (int i = 0; i < n; ++i) {
    if (i == 0) minv = min(minv, a[i]);
    else {
      if (a[i] - minv == maxv) {
        tot++;
      }
      minv = min(minv, a[i]);
    }
  }
  cout<<tot<<endl;
  return 0;
}
