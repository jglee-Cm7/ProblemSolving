#include <bits/stdc++.h>
using namespace std;
vector<vector<pair<int,int>>> board(105, vector<pair<int,int>>(105, {0, 0}));

bool checkPaper(int x, int y) {
    if(!board[y][x].second) return true;
    
    int lp = board[y-1][x].first;
    int rp = board[y-1][x+1].first;
    if(lp || rp) return true;
    if(x == 0) return false;
    int lb = board[y][x-1].second;
    int rb = board[y][x+1].second;
    if(lb && rb) return true;
    
    return false;
}

bool checkPillar(int x, int y) {
    if(!board[y][x].first) return true;
    
    if(y == 0) return true;
    if(board[y-1][x].first || board[y][x].second) return true;
    if(x > 0 && board[y][x-1].second) return true;
    
    return false;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;
    
    for(auto bf: build_frame) {
        int x = bf[0], y = bf[1];
        int sType = bf[2], bType = bf[3];
        // 설치
        if(bType == 1) {
            // 기둥
            if(sType == 0) {
                board[y][x].first = 1;  
                if(!checkPillar(x, y)) board[y][x].first = 0;    
            } else {
                // 보
                board[y][x].second = 1;
                if(!checkPaper(x, y)) board[y][x].second = 0;
            }            
        } else {
            // 삭제
            // 기둥
            bool possible = true;
            if(sType == 0) {
                board[y][x].first = 0;
                
                for(int i=n; i>=0; i--) {
                    for(int j=0; j<=n; j++) {
                        if(possible && checkPillar(i, j) == false) possible = false;
                        if(possible && checkPaper(i, j) == false) possible = false;
                        
                        if(!possible) break;
                    }
                    if(!possible) break;
                }
                
                if(!possible) board[y][x].first = 1;
            } else {
                // 보
                board[y][x].second = 0;
                for(int i=n; i>=0; i--) {
                    for(int j=0; j<=n; j++) {
                        if(possible && checkPillar(i, j) == false) possible = false;
                        if(possible && checkPaper(i, j) == false) possible = false;
                            
                        if(!possible) break;
                    }
                    if(!possible) break;
                }
                
                if(!possible) board[y][x].second = 1;
            }
        }
    }
    
    for(int j=0; j<=n; j++) {
        for(int i=0; i<=n; i++) {
            auto [p, b] = board[i][j];
            if(p) answer.push_back({j, i, 0});
            if(b) answer.push_back({j, i, 1});
        }
    }
    
    return answer;
}