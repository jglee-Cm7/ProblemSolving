#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  deque<pair<int, int>> q;
  int n, l;
  cin >> n >> l;

  for (int i = 0; i < n; i++) {
    int v;
    cin >> v;

    // 새로 들어오는 값은 q에 있는 값보다 오래 존재함
    // 따라서 오름차순으로 q를 정렬 하기 위해 v 보다 작은 수가 있으면 없애도 됨
    while (q.size() > 0 && q.back().first >= v) {
      q.pop_back();
    }

    q.push_back({v, i});

    // 범위를 벗어나는지 확인.
    if (q.front().second < i - l + 1) {
      q.pop_front();
    }

    cout << q.front().first << " ";
  }
}