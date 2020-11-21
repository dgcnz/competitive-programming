---
layout: post
mathjax: true
title: 1288B Yet Another Meme Problem
url: None
tags: None
time_complexity: None
memory_complexity: None
---

{% raw %}
None
{% endraw %}

```cpp
{% raw %}
using namespace std;
using ll = long long;
ll solve(ll A, ll B) {
  ll count = 0;
  ll maxdig = log10(B) + 1;
  count = maxdig - 1;
  if (B == (ll)pow(10, maxdig) - 1)
    ++count;
  return A * count;
}
int main(void) {
  ll t;
  cin >> t;
  while (t--) {
    ll A, B;
    cin >> A >> B;
    ll n = solve(A, B);
    cout << n << endl;
  }
  return 0;
}

{% endraw %}
```
