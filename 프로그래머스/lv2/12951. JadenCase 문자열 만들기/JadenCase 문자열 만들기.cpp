#include <bits/stdc++.h>

using namespace std;

string solution(string s) {
    string answer = "";
    bool first = true;
    for(char c : s) {
        if(first) {
            answer += toupper(c);
            first = false;
        } else answer += tolower(c);
        if(c == ' ') first = true;

    }
    return answer;
}