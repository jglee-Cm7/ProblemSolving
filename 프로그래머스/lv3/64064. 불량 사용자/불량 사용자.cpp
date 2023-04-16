#include <bits/stdc++.h>

using namespace std;

bool used[10];
set<string> cs;
set<string> ans;

bool match(string a, string x) {
    bool result = true;
    if(a.length() != x.length()) return false;
    for(int i=0; i<a.length(); i++) {
        if(x[i] == '*') continue;
        if(a[i] != x[i]) return false;
    }
    return true;
}

void func(int k, vector<string> user_id, vector<string> banned_id) {
    if(k == banned_id.size()) {
        string s = "";
        for(string c : cs) s += c + " ";
        ans.insert(s);
        return;
    }
    
    for(int i=0; i<user_id.size(); i++) {
        if(used[i]) continue;
        if(match(user_id[i], banned_id[k])) {
            used[i] = 1;
            cs.insert(user_id[i]);
            func(k+1, user_id, banned_id);
            cs.erase(user_id[i]);
            used[i] = 0;
        }
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    
    func(0, user_id, banned_id);
    answer = ans.size();
    
    return answer;
}