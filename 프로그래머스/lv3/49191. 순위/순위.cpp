#include <bits/stdc++.h>
using namespace std;


void dfs(int v, vector<int> adj[], vector<bool>& vis) {
    vis[v] = 1;
    for(int nxt : adj[v]) {
        if(vis[nxt]) continue;
        dfs(nxt, adj, vis);
    }
}

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    vector<int> adjF[105];
    vector<int> adjB[105];
    for(auto result : results) {
        int a = result[0];
        int b = result[1];
        adjF[a].push_back(b);
        adjB[b].push_back(a);
    }

    
    for(int i=1; i<=n; i++) {
        vector<bool> visF(n+1, 0);
        dfs(i, adjF, visF);
        
        vector<bool> visB(n+1, 0);
        dfs(i, adjB, visB);
        
        bool check = true;
        for(int i=1; i<=n; i++) {
            if(!visF[i] && !visB[i]) {
                check = false;
                break;
            }
        }
        if(check) answer++;
    }
    
    
    return answer;
}