#include <bits/stdc++.h>

using namespace std;

vector<string> solution(vector<string> files) {
  vector<string> answer;
  vector<tuple<string, string, int, int>> arr;

  for (int i = 0; i < files.size(); i++) {
    string file = files[i];
    string head;
    int num;
    int p = 0;
    for (int j = 0; j < file.length(); j++) {
      if (isdigit(file[j])) {
        p = j;
        break;
      }
    }
    head = file.substr(0, p);
    num = stoi(file.substr(p));
    for (char &c : head)
      c = tolower(c);
    arr.push_back({file, head, num, i});
  }

  sort(arr.begin(), arr.end(), [](const auto &A, const auto &B) -> bool {
    string q, w, a, s;
    int e, r, d, f;
    tie(q, w, e, r) = A;
    tie(a, s, d, f) = B;
    if (w != s)
      return w < s;
    else {
      if (e != d)
        return e < d;
      else
        return r < f;
    }
  });

  for (auto [file, head, num, i] : arr)
    answer.push_back(file);

  return answer;
}