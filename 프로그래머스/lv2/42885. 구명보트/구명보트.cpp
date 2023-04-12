#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    int n = people.size();
    vector<bool> used(n, 0);
    sort(people.begin(), people.end());
    
    for(int i=0; i<n; i++) {
        if(used[i]) continue;
        answer++;
        used[i] = 1;
        if(i == n-1) continue;
        int rm = limit - people[i];
        int j = upper_bound(people.begin()+i+1, people.end(), rm) - people.begin();
        while(j > i) {
            if(people[j] <= rm && !used[j]) {
                used[j] = 1;
                break;
            }
            j--;
        }
    }
    
    return answer;
}