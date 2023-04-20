#include <bits/stdc++.h>
using namespace std;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    vector<vector<int>> adj(n+1);
    vector<int> vis(n+1);
    for(auto e : edge) {
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
    }
    
    queue<int> q;
    q.push(1);
    vis[1] = 1;
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        for(int nxt : adj[cur]) {
            if(vis[nxt]) continue;
            vis[nxt] = vis[cur] + 1;
            q.push(nxt);
        }
    }
    
    int mx = *max_element(vis.begin(), vis.end());
    answer = count(vis.begin(), vis.end(), mx);
    
    
    return answer;
}