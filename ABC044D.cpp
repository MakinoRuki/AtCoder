#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 52
using namespace std;
typedef long long ll;
ll n, s;
int main() {
  cin>>n>>s;
  ll ans=-1;
  // 如果有b^2项则b<=sqrt(n)。
  for (ll b = 2; b *b <= n; ++b) {
    ll sum=0;
    ll x = n;
    while(x) {
      sum += x % b;
      x /= b;
    }
    if (sum == s) {
      ans = b;
      break;
    }
  }
  // if (s == 1) {
  //   ans = (ans < 0 ? n : min(n, ans));
  // }
  // if (s == 2) {
  //   ans = (ans < 0 ? n-1 : min(n-1, ans));
  // }
  // 如果只有b项和1项则{b*x+y=n, x+y=s}。那么b和x也必然是不超过sqrt(n)。
  for (ll x = 1; x * x <= n-s; ++x) {
    if ((n-s) % x == 0) {
      ll a = (n-s)/x;
      if (n/(x+1) == a && a < (x+1) && n % (x+1) + n / (x+1) == s) {
        ans = (ans < 0 ? x+1 : min(x+1, ans));
      }
      if (n/(a+1) == x && x < (a+1) && n % (a+1) + n / (a+1) == s) {
        ans = (ans < 0 ? a+1 : min(a+1, ans));
      }
    }
  }
  // s==n时为n+1进制。
  if (s == n) {
    ans = (ans < 0 ? n+1 : min(ans, n+1));
  }
  cout<<ans<<endl;
  return 0;
}
