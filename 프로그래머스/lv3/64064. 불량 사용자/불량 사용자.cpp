
#include <bits/stdc++.h>

using namespace std;

bool match(string a, string x) {
    bool result = true;
    if(a.length() != x.length()) return false;
    for(int i=0; i<a.length(); i++) {
        if(x[i] == '*') continue;
        if(a[i] != x[i]) return false;
    }
    return true;
}

int solution(vector<string> user_id, vector<string> banned_id) {
    vector<int> comb(user_id.size() - banned_id.size(), 0);
    for(int i=0; i<banned_id.size(); i++) comb.push_back(1);
    int answer = 0;
    vector<vector<string>> picked;
    do {
        vector<string> candi;
        for(int i=0; i<comb.size(); i++)
            if(comb[i]) candi.push_back(user_id[i]);
        
        
        sort(candi.begin(), candi.end());
        do {
            bool success = true;
            for(int i=0; i<candi.size(); i++) {
                if(match(candi[i], banned_id[i])) continue;
                success = false;
                break;
            }
            if(success) {
                answer++;
                break;
            }
        } while(next_permutation(candi.begin(), candi.end()));
        
    } while(next_permutation(comb.begin(), comb.end()));
    
    return answer;
}