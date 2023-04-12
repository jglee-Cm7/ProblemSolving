#include <bits/stdc++.h>

using namespace std;

int solution(int n, int a, int b)
{
    int answer = 1;
    if(a > b) swap(a,b);
    while(!(a%2 && a+1 == b)) {
        a = (a+1)/2;
        b = (b+1)/2;
        answer++;
    }
    
    return answer;
}