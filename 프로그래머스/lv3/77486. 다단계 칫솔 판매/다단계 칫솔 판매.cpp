#include <bits/stdc++.h>
using namespace std;

vector<long long> revenue(10010, 0);
vector<int> parent(10010, -1);

void dfs(int c, int profit) {
    if(c == -1) return;
    int commission = profit / 10;
    revenue[c] += profit - commission;
    if(commission == 0) return;
    dfs(parent[c], commission);
}


vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    int n = (int)enroll.size();
    int m = (int)seller.size();
    map<string, int> dict;
    dict["-"] = 0;
    for(int i=0; i<n; i++)
        dict[enroll[i]] = i+1;
    
    
    for(int i=0; i<n; i++) {
        int p = dict[referral[i]];
        int c = dict[enroll[i]];
        parent[c] = p;
    }
    for(int i=0; i<m; i++) {
        int c = dict[seller[i]];
        int profit = amount[i] * 100;
        dfs(c, profit);
    }
    
    vector<int> answer;
    for(int i=1; i<=n; i++)
        answer.push_back(revenue[i]);
    
    return answer;
}