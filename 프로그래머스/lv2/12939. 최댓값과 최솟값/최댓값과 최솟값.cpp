#include <bits/stdc++.h>

using namespace std;

vector<int> split(string s, string delimiter) {
  vector<int> result;

  char *str = strdup(s.c_str());
  char *del = strdup(delimiter.c_str());

  char *ptr = strtok(str, del);
  while (ptr != NULL) {
    string token = ptr;
    result.push_back(stoi(token));
    ptr = strtok(NULL, del);
  }

  free(str);
  free(del);
  return result;
}

string solution(string s) {
    string answer = "";
    vector<int> arr = split(s, " ");
    int mx = *max_element(arr.begin(), arr.end());
    int mn = *min_element(arr.begin(), arr.end());
    answer += to_string(mn) + " " + to_string(mx);
    return answer;
}