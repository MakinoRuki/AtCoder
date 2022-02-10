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
#define M 202
#define N 100005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q;
//int t;
vector<pair<int,int>> edges[N];
int dis[N];
bool vis[N];
int bfs() {
  for (int i = 0; i <= k; ++i) {
    dis[i] = inf;
  }
  memset(vis, false, sizeof(vis));
  queue<int> q;
  q.push(1);
  dis[1] = 0;
  vis[1] = true;
  while(!q.empty()) {
    auto u = q.front();
    q.pop();
    vis[u] = false;
   // cout<<"u="<<u<<endl;
    for (int i = 0; i < edges[u].size(); ++i) {
      int v = edges[u][i].first;
      int w = edges[u][i].second;
      if (dis[v] > dis[u] + w) {
        dis[v] = dis[u] + w;
      //  cout<<"v="<<v<<" "<<w<<" "<<dis[v]<<endl;
        if (!vis[v]) {
          vis[v] = true;
          q.push(v);
        }
      }
    }
  }
  return dis[0]+1;
}
int main() {
  cin>>k;
  for (int i = 0; i < k; ++i) {
    edges[i].push_back(make_pair((i+1)%k, 1));
    edges[i].push_back(make_pair((i*10)%k, 0));
  }
  int res = bfs();
  cout<<res<<endl;
  return 0;
}
