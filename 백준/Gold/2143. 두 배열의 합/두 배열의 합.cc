#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t, n, m;
  cin >> t >> n;
  vector<int> A(n);
  for (int i = 0; i < n; i++)
    cin >> A[i];
  cin >> m;
  vector<int> B(m);
  for (int i = 0; i < m; i++)
    cin >> B[i];
  vector<int> subA, subB;
  for (int i = 0; i < n; i++) {
    int v = A[i];
    subA.push_back(v);
    for (int j = i + 1; j < n; j++) {
      v += A[j];
      subA.push_back(v);
    }
  }
  for (int i = 0; i < m; i++) {
    int v = B[i];
    subB.push_back(v);
    for (int j = i + 1; j < m; j++) {
      v += B[j];
      subB.push_back(v);
    }
  }

  sort(subA.begin(), subA.end());
  sort(subB.begin(), subB.end());

  long long ans = 0;
  for (int i = 0; i < (int)subA.size(); i++) {
    int target = t - subA[i];
    long long count = upper_bound(subB.begin(), subB.end(), target) -
                      lower_bound(subB.begin(), subB.end(), target);
    ans += count;
  }

  cout << ans;
}