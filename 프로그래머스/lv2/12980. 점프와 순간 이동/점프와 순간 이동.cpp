#include <bits/stdc++.h>
using namespace std;

int solution(int n)
{
    int answer = 1;
    while(n != 1) {
        if(n%2) {
            answer++;
            n--;
        }
        n /= 2;
    }
    
    return answer;
}