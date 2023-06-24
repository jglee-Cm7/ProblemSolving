#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> adj[100010];

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    vector<int> answer;
    for(auto r : roads) {
        int u = r[0], v = r[1];
        adj[u].push_back({1, v});
        adj[v].push_back({1, u});
    }
    for(int i=1; i<=n; i++)
        sort(adj[i].begin(), adj[i].end());
    
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    vector<int> d(n+1, INT_MAX);
    d[destination] = 0;
    pq.push({0, destination});
    while(!pq.empty()) {
        auto [w, cur] = pq.top();
        pq.pop();
        if(d[cur] != w) continue;
        for(auto [nw, nxt]: adj[cur]) {
            if(w + nw < d[nxt]) {
                d[nxt] = w + nw;
                pq.push({d[nxt], nxt});
            }
        }
    }
    for(int src : sources) {
        if(d[src] == INT_MAX) answer.push_back(-1);
        else answer.push_back(d[src]);
    }
        
    return answer;
}