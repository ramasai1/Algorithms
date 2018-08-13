#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define N 101
pair<int, pair<int, int> > graph[N];
int rank[N]; memset(rank, 0, sizeof parent);
for(int i = 0; i < N; i++)
  parent[i] = i;


int mincost;
//union find using the link-by-rank method.
//provides O(logn) find and constant time union.
int find(int x) {
  while(x != parent[x])
    x = parent[x];

  return x;
}

void union(int x, int y) {
  r = find(x);
  s = find(y);
  if(r == s)
    return;

  if(rank[r] > rank[s])
    parent[s] = r;
  else if(rank[s] > rank[r])
    parent[r] = s;
  else {
    parent[s] = r;
    rank[s]++;
  }
}

//actual kruskal MST
vector<pair<int, int> > kruskal() {
  sort(graph, graph + N);
  vector<pair<int, int> > ret;
  for(int i = 0; i < N; i++) {
    int r = graph[i].second.first;
    int s = graph[i].second.second;
    if(find(r) == find(s)) continue;
    else {
      mincost += graph[i].first;
      ret.push_back(graph[i].second);
      union(r, s);
    }
  }
  return ret;
}
