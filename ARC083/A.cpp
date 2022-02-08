#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#define M 500005
#define N 200
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q;
int t;
string s;
int nn;
int extgcd(int a, int b, int& x, int& y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  int g = extgcd(b, a%b, x, y);
  int tmp = x-(a/b)*y;
  x = y;
  y = tmp;
  return g;
}
int main() {
  int a,b,c,d,e,f;
  cin>>a>>b>>c>>d>>e>>f;
  int x = -1, y = -1;
  for (int i = 0; i <= f; ++i) {
    for (int j= 0; i+j <= f; ++j) {
      if (i == 0 && j == 0) continue;
      if ((100*i <= e * j) && (j%100)==0) {
        int x1,y1,g1;
        int x2,y2,g2;
        g1= extgcd(c,d,x1,y1);
        g2= extgcd(a,b,x2,y2);
        if (i%g1) continue;
        int r = d/g1;
        int xx=(x1*i/g1%r+r)%r;
        int yy=(i-c*xx)/d;
        if (yy<0) continue;
        if ((j/100)%g2) continue;
        r = b/g2;
        xx = (x2*(j/100)/g2%r+r)%r;
        yy = ((j/100)-a*xx)/b;
        if (yy<0) continue;
        if (x<0 || (x*(i+j)<y*i)) {
          x=i;
          y=i+j;
        }
      }
    }
  }
  cout<<y<<" "<<x<<endl;
  return 0;
}

