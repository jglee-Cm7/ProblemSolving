#include <bits/stdc++.h>
using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    set<string> s;
    s.insert(words[0]);
    for(int i=1; i<words.size(); i++) {
        if(s.find(words[i]) != s.end() || words[i-1].back() != words[i][0]) {
            answer.push_back((i%n)+1);
            answer.push_back((i/n)+1);
            break;
        }
        s.insert(words[i]);
    }
    if(answer.empty()) {
        answer.push_back(0);
        answer.push_back(0);
    }

    return answer;
}
    