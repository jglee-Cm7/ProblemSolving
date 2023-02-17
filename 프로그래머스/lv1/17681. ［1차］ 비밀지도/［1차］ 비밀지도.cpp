#include <string>
#include <vector>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    for (int i = 0; i < n; i++) {
        string s = "";
        int x = arr1[i] | arr2[i];
        for (int j = n - 1; j >= 0; j--) {
            if (x & (1 << j)) {
                s += "#";
                x -= 1 << j;
            } else
                s += " ";
        }
        answer.push_back(s);
    }
    return answer;
}