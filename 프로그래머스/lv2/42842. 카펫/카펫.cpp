#include <bits/stdc++.h>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int sum = (brown + 4) / 2;
    int mul = brown + yellow;
    for(int i=1; i<=sum/2; i++) {
        int j = sum - i;
        if(i*j == mul && i + j == sum)
            return {j, i};
    }
    return answer;
}