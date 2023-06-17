#include <bits/stdc++.h>
using namespace std;
int n, m, k, c;

bool compare(int x, int y, vector<vector<int>>& key, vector<vector<int>> extLock) {
    int cnt = 0;
    for(int i=0; i<m; i++) {
        for(int j=0; j<m; j++) {
            if(extLock[i+x][j+y] == 1 && key[i][j]) return false;
            if(extLock[i+x][j+y]) continue;
            if(key[i][j]) cnt++;
        }
    }
    
    return c == cnt;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = false;
    n = lock.size();
    m = key.size();
    k = 2*m + n - 2;
    vector<vector<int>> extLock(k, vector<int>(k, 2));
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(!lock[i][j]) c++;
            extLock[i+m-1][j+m-1] = lock[i][j];
        }
    }
    
    
    // key 회전
    vector<vector<int>> rotate(m, vector<int>(m, 0));
    for(int r=0; r<4; r++) {
        for(int i=0; i<=k-m; i++) {
            for(int j=0; j<=k-m; j++) {
                answer = compare(i, j, key, extLock);
                if(answer) break;
            }
            if(answer) break;
        }
        if(answer) break;
        
        for(int i=0; i<m; i++) {
            for(int j=0; j<m; j++)
                rotate[i][j] = key[m-j-1][i];
        }
        key = rotate;
    }
    
    
    
    
    return answer;
}