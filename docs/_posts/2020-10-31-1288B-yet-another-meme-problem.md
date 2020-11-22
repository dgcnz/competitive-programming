---
layout: post
mathjax: true
title: 1288B Yet Another Meme Problem
problem_url: None
tags: None
memory_complexity: None
time_complexity: None
---

None


{% if page.time_complexity != "None" %}
- Time complexity: ${{ page.time_complexity }}$
{% endif %}
{% if page.memory_complexity != "None" %}
- Memory complexity: ${{ page.memory_complexity }}$
{% endif %}
{% if page.tags != "None" %}
- Tags: {{ page.tags }}
{% endif %}

{% if page.problem_url != "None" %}
- [URL]({{ page.problem_url }})
{% endif %}

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