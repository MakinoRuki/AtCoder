#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
int n;
int main() {
  cin>>n;
  ll x, y;
  for (int i = 1; i <= n; ++i) {
  	ll t, a;
    cin>>t>>a;
    if (i == 1) {
      x = t;
      y = a;
    } else {
      ll det = max((x+t-1)/t, (y+a-1)/a);
      x = det * t;
      y = det * a;
    }
  }
  cout<<x+y<<endl;
  return 0;
}
