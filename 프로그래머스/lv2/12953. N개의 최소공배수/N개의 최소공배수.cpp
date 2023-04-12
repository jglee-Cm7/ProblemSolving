#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> arr) {
    int ans = 1;
    while(1) {
        bool exit = 1;
        for(int a : arr) {
            if(ans % a != 0) {
                ans++;
                exit = 0;
                break;
            }
        }
        if(exit) break;
    } 
    return ans;
}