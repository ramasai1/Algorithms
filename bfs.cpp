#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define N 101
vector<int> graph[N];
bool visited[N];
int level[N];

void bfs(int s) {
  queue<int> q;
  q.push(s);
  visited[s] = true;
  while(!q.empty()) {
    int k = q.front();
    q.pop();
    for(int i = 0; i < graph[k].size(); i++) {
      if(visited[graph[k][i]] == false) {
        visited[graph[k][i]] = true;
        q.push(graph[k][i]);
        level[graph[k][i]] = level[k] + 1;
      }
    }
  }
}
