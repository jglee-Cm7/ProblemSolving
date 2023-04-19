#include <bits/stdc++.h>

using namespace std;

int getStep(vector<int> stones, int t) {
    int result = 0;
    int count = 0;
    for(int i=0; i<stones.size(); i++) {
        if(stones[i] - t > 0) {
            result = max(result, count);
            count = 0;
        } else count++;
    }
    result = max(result, count);
    return result;
}

int solution(vector<int> stones, int k) {
    int answer = 0;
    
    int s = 1;
    int e = *max_element(stones.begin(), stones.end());
    while(s <= e) {
        int mid = (s + e) / 2;
        if(getStep(stones, mid) < k) s = mid + 1;
        else e = mid - 1;
    }
    answer = e + 1;
    return answer;
}