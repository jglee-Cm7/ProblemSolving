#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    for(int i=0; i<arr1.size(); i++) {
        vector<int> v;
        for(int j=0; j<arr2[0].size(); j++) {
            int s = 0;
            for(int k=0; k<arr1[i].size(); k++) 
                s += arr1[i][k] * arr2[k][j];
            v.push_back(s);
        }
        answer.push_back(v);
    }
    
    return answer;
}