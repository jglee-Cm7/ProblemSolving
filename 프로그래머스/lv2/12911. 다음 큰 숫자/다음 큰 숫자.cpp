#include <bits/stdc++.h>

using namespace std;

int solution(int n) {
    int answer = 0;
    bitset<20> p(n);
    int cnt = p.count();
    
    for(int i=n+1; i<= 1000000; i++) {
        bitset<20> b(i);
        if(b.count() == cnt) {
            answer = b.to_ulong();
            break;
        }
    }
    return answer;
}