---
layout: post
title: 1294B Collecting Packages
url: None
tags: None
time_complexity: None
memory_complexity: None
---

None

```cpp
{% raw %}
using namespace std;
using ll = long long;
int n;
int X[1010];
int Y[1010];
void sort_points(int n) {
  pair<int, int> pairt[n];
  for (int i = 0; i < n; i++) {
    pairt[i].first = X[i];
    pairt[i].second = Y[i];
  }
  sort(pairt, pairt + n);
  for (int i = 0; i < n; i++) {
    X[i] = pairt[i].first;
    Y[i] = pairt[i].second;
  }
}
pair<bool, string> solve(int n) {
  sort_points(n);
  string res = "";
  int last_x = 0;
  int last_y = 0;
  for (int i = 0; i < n; ++i) {
    if (Y[i] < last_y)
      return {false, res};
    int dy = Y[i] - last_y;
    int dx = X[i] - last_x;
    last_x = X[i];
    last_y = Y[i];
    for (int j = 0; j < dx; ++j)
      res += "R";
    for (int j = 0; j < dy; ++j)
      res += "U";
  }
  return {true, res};
}
int main(void) {
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    cin >> n;
    for (int j = 0; j < n; ++j) {
      cin >> X[j] >> Y[j];
    }
    auto [b, res] = solve(n);
    if (b) {
      cout << "YES\n" << res << endl;
    } else
      cout << "NO\n";
  }
  return 0;
}

{% endraw %}
```
