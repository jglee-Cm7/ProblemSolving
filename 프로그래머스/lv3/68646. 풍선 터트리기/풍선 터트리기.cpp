#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> a) {
    int answer = 1;
    int n = a.size();
    int pivot = find(a.begin(), a.end(), *min_element(a.begin(), a.end())) - a.begin();
    
    int mn = INT_MAX;
    for(int i=0; i<pivot; i++) {
        if(a[i] < mn) {
            answer++;
            mn = a[i];
        }
    }
    mn = INT_MAX;
    for(int i=n-1; i>pivot; i--) {
        if(a[i] < mn) {
            answer++;
            mn = a[i];
        }
    }
    return answer;
}