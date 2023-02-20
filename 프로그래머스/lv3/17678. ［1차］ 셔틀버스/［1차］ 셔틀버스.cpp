#include <bits/stdc++.h>

using namespace std;


string solution(int n, int t, int m, vector<string> timetable) {
  string answer = "";
  vector<int> tt;
  for (string time : timetable) {
    int t = stoi(time.substr(0, 2)) * 60 + stoi(time.substr(3, 2));
    tt.push_back(t);
  }
  sort(tt.begin(), tt.end());
  queue<int> q;
  for (int t : tt)
    q.push(t);

  // for (int t : tt)
  //   cout << t << "\n";
  // cout << "\n";

  int st = 540 - t;
  vector<int> ps;
  for (int i = 0; i < n; i++) {
    st += t;
    // cout << st << " : ";
    for (int j = 0; j < m; j++) {
      if (!q.empty() && q.front() <= st) {
        if (i == n - 1) ps.push_back(q.front());
        // cout << q.front() << " ";
        q.pop();
      }
    }
    // cout << "\n";
  }
  int ans = st;
  if (ps.size() > 0 && ps.size() < m && ps[ps.size() - 1] >= 540)
    ans = ps[ps.size() - 1] - 1;
  else if (ps.size() == m)
    ans = ps[ps.size() - 1] - 1;
  int hour = ans / 60;
  int minute = ans % 60;
  answer += (hour < 10 ? "0" + to_string(hour) : to_string(hour)) + ":" +
            (minute < 10 ? "0" + to_string(minute) : to_string(minute));

  return answer;
}