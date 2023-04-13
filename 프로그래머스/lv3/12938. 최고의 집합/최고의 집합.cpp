#include <bits/stdc++.h>

using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
    if(n > s) return {-1};
    
    int v = s/n;
    for(int i=0; i<n; i++) answer.push_back(v);
    
    s -= v*n;
    for(int i=0; i<s; i++) answer[n-i-1]++;
    
    return answer;
}