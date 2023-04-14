#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    int n = A.size();
    sort(A.begin(), A.end(), greater<>());
    sort(B.begin(), B.end(), greater<>());
    int j = 0;
    for(int i = 0; i < n; i++) {
        if(A[i] >= B[j]) continue;
        else {
            answer++;
            j++;
        }
    }
    return answer;
}