#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int t = 0;
    sort(jobs.begin(), jobs.end());
    auto compare = [](const auto a, const auto b) {
        if(a.second == b.second) return a.first > b.first;
        else return a.second > b.second;
    };
    priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(compare)> pq(compare);

    
    int cur = 0;
    int tot = 0;
    for(auto job : jobs) {
        if(job[0] <= cur) {
            pq.push({job[0], job[1]});
            continue;
        }   
        while(!pq.empty()) {
            auto [s, t] = pq.top();
            pq.pop();
            if(cur >= s) {
                tot += cur - s + t;
                cur += t;
            } else {
                cur = s + t;
                tot += t;
            }
            if(job[0] <= cur) break;
        }
        pq.push({job[0], job[1]});
    }
    while(!pq.empty()) {
        auto [s, t] = pq.top();
        pq.pop();
        if(cur >= s) {
            tot += cur - s + t;
            cur += t;
        } else {
            cur = s + t;
            tot += t;
        }
    }
    
    answer = tot / jobs.size();
    
    return answer;
}