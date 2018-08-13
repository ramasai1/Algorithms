#include <iostream>
#include <vector>
using namespace std;

#define N 101
vector<int> graph[N];
bool visited[N];

void dfs(int s) {
  visited[s] = true;
  for(int i = 0; i < graph[s].size(); i++) {
    if(visited[graph[s][i]] == false)
      dfs(graph[s][i]);
  }
}
