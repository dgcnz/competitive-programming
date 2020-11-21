---
layout: post
mathjax: true
title: 11B Jumping Jack
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
using predicate = function<bool(int)>;
int bs(int l, int r, predicate p)
{
    while (l < r)
    {
        int m = l + (r - l) / 2;
        if (p(m))
            r = m;
        else
            l = m + 1;
    }
    return l;
}
ll psum(ll n) { return (n * (n + 1)) / 2; }
int main(void)
{
    int x;
    cin >> x;
    x = abs(x);
    int n = bs(0, 1e9 + 11, [x](ll n) { return x <= psum(n); });
    while (psum(n) % 2 != x % 2)
        ++n;
    cout << n << endl;
    return 0;
}

{% endraw %}
```
