#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    int n = genres.size();
    map<string, int> gtp; // {genre, total play}
    map<string, vector<pair<int, int>>> gp; // {genre, {play, index}}
    
    for(int i = 0; i < n; i++) {
        gtp[genres[i]] += plays[i];
        gp[genres[i]].push_back({plays[i], i});
    }
    
    vector<pair<int, string>> gr; // genre rank
    for(auto [key, value] : gtp) gr.push_back({value, key});
    sort(gr.begin(), gr.end(), greater<>());
    
    for(auto [tp, genre] : gr) {
        sort(gp[genre].begin(), gp[genre].end(), [](const auto a, const auto b) {
            if(a.first != b.first) return a.first > b.first;
            else return a.second < b.second;
        });
        int count = 0;
        for(auto [p, i] : gp[genre]) {
            if(count == 2) break;
            answer.push_back(i);
            count++;
        }
    }
    
    
    return answer;
}