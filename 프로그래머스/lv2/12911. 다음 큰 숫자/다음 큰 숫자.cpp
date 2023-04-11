#include <bits/stdc++.h>

using namespace std;

int solution(int n) {
    int answer = 0;
    int cnt = bitset<20>(n).count();
    
    for(int i=n+1; i<= 1000000; i++)
        if(bitset<20>(i).count() == cnt) return i;

    return answer;
}