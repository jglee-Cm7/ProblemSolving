#include <bits/stdc++.h>
using namespace std;

int solution(int n) {
    vector<int> acc(n+1, 0);
    int answer = 0;
    for(int i=1; i<=n; i++)
        acc[i] = acc[i-1] + i;
    for(int i=n; i>=0; i--) {
        if(acc[i] - n < 0) continue;
        if(binary_search(acc.begin(), acc.begin() + i, acc[i]-n)) answer++;
    }

    return answer;
}