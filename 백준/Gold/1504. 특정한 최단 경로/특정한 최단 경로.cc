#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll INF = 0x3f3f3f3f;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  ll n, e;
  cin >> n >> e;
  vector<vector<ll>> d(n + 1, vector<ll>(n + 1, INF));
  while (e--) {
    ll a, b, c;
    cin >> a >> b >> c;
    d[a][b] = c;
    d[b][a] = c;
  }
  ll u, v;
  cin >> u >> v;
  for (int i = 1; i <= n; i++)
    d[i][i] = 0;

  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        if (d[i][k] + d[k][j] < d[i][j]) d[i][j] = d[i][k] + d[k][j];
      }
    }
  }

  ll ans = INF;
  if (d[1][u] != INF && d[u][v] != INF && d[v][n] != INF)
    ans = min(ans, d[1][u] + d[u][v] + d[v][n]);
  if (d[1][v] != INF && d[v][u] != INF && d[u][n] != INF)
    ans = min(ans, d[1][v] + d[v][u] + d[u][n]);

  if (ans == INF)
    cout << "-1";
  else
    cout << ans;
}