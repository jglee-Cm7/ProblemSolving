#include <bits/stdc++.h>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    vector<int> shadow;
    
    int st = 0;
    for(int station : stations) {
        int en = station - w;
        int sd = en - 1 - st;
        if(sd > 0) shadow.push_back(sd);
        st = station + w;
    }
    if(st < n) shadow.push_back(n - st);
    
    for(int sd : shadow) {
        answer += sd / ((w*2) + 1);
        if(sd % ((w*2) + 1)) answer++;
    }

    return answer;
}