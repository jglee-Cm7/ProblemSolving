#include <bits/stdc++.h>

using namespace std;

vector<int> p(101, -1);
int find(int v) {
    if(p[v] < 0) return v;
    return p[v] = find(p[v]);
}

bool isSameGroup(int u, int v) {
    u = find(u), v = find(v);
    if(u == v) return true;
    else return false;
}

void merge(int u, int v) {
    u = find(u), v = find(v);
    if(u < v) p[v] = u;
    else p[u] = v;
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    sort(costs.begin(), costs.end(), [](const auto a, const auto b) {
        return a[2] < b[2]; 
    });
    int count = 0;
    for(auto cost : costs) {
        if(isSameGroup(cost[0], cost[1])) continue;
        merge(cost[0], cost[1]);
        answer += cost[2];
        count++;
        if(count == n-1) break;
    }
    return answer;
}