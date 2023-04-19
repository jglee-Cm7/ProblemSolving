#include <iostream>
#include <vector>
using namespace std;

int solution(vector<int> sticker)
{
    int answer = 0;
    int n = sticker.size();
    vector<int> dp(n+1, 0);
    vector<int> dp2(n+2, 0);
    if(n == 1) return sticker[0];
    
    for(int i=2; i<=n; i++)
        dp[i] = max(dp[i-1], dp[i-2] + sticker[i-2]);
    for(int i=3; i<=n+1; i++)
        dp2[i] = max(dp2[i-1], dp2[i-2] + sticker[i-2]);
    
    answer = max(dp[n], dp2[n+1]);

    return answer;
}