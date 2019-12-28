#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
int idx[27], pre[27];
int main() {
  string s;
  cin>>s;
  int n =s.size();
  vector<int> ans={-1, -1};
  for (int i = 0; i < 26; ++i) {
    int minv1 = 0;
    int minv2 = 1000000000;
    int idx1= 0;
    int idx2=0;
    int sum=0;
    int tmp=2*0-1;
    if (s[0] == 'a' + i) {
      tmp=2 * 1-1;
      sum++;
    }
    for (int j = 2; j <= n; ++j) {
      if (s[j-1] == 'a' + i) {
        sum++;
      }
      if (2 * sum - j > minv1 && j-idx1 >= 2) {
        ans[0] = idx1+1;
        ans[1] = j;
        break;
      } else if (2 * sum - j > minv2 && j - idx2 >= 2) {
        ans[0] = idx2+1;
        ans[1] = j;
        break;
      }
      if (tmp < minv1) {
        minv2 = minv1;
        idx2=idx1;
        minv1 = tmp;
        idx1 = j-1;
      } else if (tmp >= minv1 && tmp < minv2) {
        minv2 = tmp;
        idx2 = j-1;
      }
      tmp = 2 *sum-j;
    }
    if (ans[0] >= 0) break; //{cout<<i<<endl; break;}
  }
  cout<<ans[0]<<" "<<ans[1]<<endl;
  // for (int i= 0; i < 26; ++i) {
  // 	idx[i] = 0;
  //   pre[i] = 0;
  //   int tmp = 0;
  //   int sum=0;
  //   if (s[0] == 'a' + i) {
  //     tmp = 2 * 1 - 1;
  //     sum++;
  //   } else {
  //     tmp = 2 * 0 - 1;
  //   }
  //   for (int j = 2; j <= n; ++j) {
  //     if (s[j-1] == 'a' + i) {
  //       sum++;
  //     	if (2*sum - j > pre[i]) {
  //         ans[1] = j;
  //         ans[0] = idx[i]+1;
  //         break;
  //       }
  //       if (tmp < pre[i]) {
  //         pre[i] = tmp;
  //         idx[i] = j-1;
  //       }
  //       tmp = 2*sum - i;
  //     }
  //   }
  //   if (ans[0] >= 0) break;
  // }
  // if (ans[0] < 0) cout<<"-1 -1"<<endl;
  // else cout<<ans[0]<<" "<<ans[1]<<endl;
  return 0;
}
