#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, r, m, k;
  cin >> n >> r;
  map<string, int> station;
  int idx = 0;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    if (station[s]) continue;
    station[s] = ++idx;
  }

  cin >> m;
  vector<int> route;
  while (m--) {
    string s;
    cin >> s;
    route.push_back(station[s]);
  }
  vector<vector<double>> cost(idx + 1, vector<double>(idx + 1, 1e6));
  vector<vector<double>> disCost(idx + 1, vector<double>(idx + 1, 1e6));
  cin >> k;
  while (k--) {
    string type, s, e;
    int a, b;
    double w;
    cin >> type >> s >> e >> w;
    a = station[s];
    b = station[e];
    cost[a][b] = min(cost[a][b], w);
    cost[b][a] = min(cost[b][a], w);
    if (type == "S-Train" || type == "V-Train")
      w = w / 2;
    else if (type == "ITX-Saemaeul" || type == "ITX-Cheongchun" ||
             type == "Mugunghwa")
      w = 0;
    disCost[a][b] = min(disCost[a][b], w);
    disCost[b][a] = min(disCost[b][a], w);
  }

  for (int k = 1; k <= idx; k++) {
    for (int i = 1; i <= idx; i++) {
      for (int j = 1; j <= idx; j++) {
        cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
        disCost[i][j] = min(disCost[i][j], disCost[i][k] + disCost[k][j]);
      }
    }
  }

  double total = 0;
  double disTotal = 0;
  int st = 0;
  for (int r : route) {
    if (st == 0) {
      st = r;
      continue;
    }
    total += cost[st][r];
    disTotal += disCost[st][r];
    st = r;
  }

  if (disTotal + r < total)
    cout << "Yes";
  else
    cout << "No";
}