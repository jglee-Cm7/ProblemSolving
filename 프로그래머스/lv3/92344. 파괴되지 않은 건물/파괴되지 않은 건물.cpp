#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int answer = 0;
    int n = board.size();
    int m = board[0].size();
    vector<vector<int>> acc(n+1, vector<int>(m+1, 0));
    for(auto sk: skill) {
        int degree = sk[0] == 1 ? -sk[5] : sk[5];
        int r1 = sk[1];
        int c1 = sk[2];
        int r2 = sk[3];
        int c2 = sk[4];
        acc[r1][c1] += degree;
        acc[r1][c2+1] -= degree;
        acc[r2+1][c1] -= degree;
        acc[r2+1][c2+1] += degree;
    }
    
    for(int i=0; i<n+1; i++) {
        for(int j=1; j<m+1; j++)
            acc[i][j] += acc[i][j-1];
    }
    
    for(int j=0; j<m+1; j++) {
        for(int i=1; i<n+1; i++) 
            acc[i][j] += acc[i-1][j];
    }
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            board[i][j] += acc[i][j];
            if(board[i][j] > 0) answer++;
        }
    }
    
    return answer;
}