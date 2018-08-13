#include <iostream>
#include <vector
#include <algorithm>
#include <priority_queue>
using namespace std;

#define N 101
vector<pair<int, int> > graph[N];
int dist[N]; memset(dist, INT_MAX, sizeof dist);
int pred[N]; memset(pred, -1, sizeof pred);

void relax(int u, int v, int wt) {
  if(dist[v] > dist[u] + wt) {
    dist[v] = dist[u] + wt;
    pred[v] = u;
  }
}

void dijkstra(int s) {
  dist[s] = 0;
  //priority queue with a pair -> sorted by weight and vertex u
  priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int > > > pq;
  pq.push(make_pair(0, s));
  while(!pq.empty()) {
    int u = pq.top().second();
    pq.pop();
    for(int i = 0; i < graph[u].size(); i++) {
      int wt = graph[u][i].second;
      int v = graph[u][i].first;
      if(dist[v] > dist[u] + wt) {
        pred[v] = u;
        dist[v] = dist[u] + wt;
        pq.push(make_pair(dist[v], v));
      }
    }
  }
}
