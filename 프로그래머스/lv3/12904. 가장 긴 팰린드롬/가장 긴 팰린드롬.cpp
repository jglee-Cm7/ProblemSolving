#include <bits/stdc++.h>
using namespace std;

int n;
string _s;

// ab 0 1 -> 4
// cdcb 2 5 -> 4 -> k: 0 1
// cdcba 2 6 -> 5 -> k: 0 1

bool isPalindrome(int i, int j) {
    int l = j-i+1;
    for(int k=0; k<l/2; k++) {
        if(_s[i+k] != _s[j-k]) return 0;
    }
    
    return 1;
}

int solution(string s)
{
    _s = s;
    n = s.length();
    
    int answer = 1;
    for(int j=1; j<=n; j++) {
        for(int i=0; i<n; i++) {
            if(i+j >= n) continue;
            if(isPalindrome(i, i+j)) {
                answer = j+1;
                break;
            }
        }
    }

    return answer;
}