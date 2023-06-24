#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100010];

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources,
                     int destination) {
    vector<int> answer;
    for (auto r : roads) {
    int u = r[0], v = r[1];
    adj[u].push_back(v);
    adj[v].push_back(u);
    }

    vector<int> vis(n + 1, 0);
    vis[destination] = 1;
    queue<int> q;
    q.push(destination);

    while (!q.empty()) {
      int cur = q.front();
      q.pop();
      for (int nxt : adj[cur]) {
        if (vis[nxt]) continue;
        vis[nxt] = vis[cur] + 1;
        q.push(nxt);
      }
    }
    for(int src : sources)
        answer.push_back(vis[src]-1);
    
    return answer;
}
