---
layout: post
mathjax: true
title: 1368B Codeforces Subsequences
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
using vi = vector<int>;
using ll = long long;
using predicate = function<bool(int)>;
ll k;
string cf = "codeforces";
const int n = 10;
bool can_distribute(int x)
{
    vi each(n, 1 + x / n);
    x %= n;
    for (int i = 0; i < n and x > 0; ++i, --x)
        each[i] += 1;
    ll kp = 1;
    for (auto y : each)
        kp *= y;
    return kp >= k;
}
int bsearch(int l, int r, predicate p)
{
    while (l < r)
    {
        int mid = l + (r - l) / 2;
        if (p(mid) == true)
            r = mid;
        else
            l = mid + 1;
    }
    return l;
}
int main(void)
{
    cin >> k;
    int ans = bsearch(0, 40 * 10, can_distribute);
    vi each(n, 1 + ans / n);
    ans %= n;
    for (int i = 0; i < n and ans > 0; ++i, --ans)
        each[i] += 1;
    for (int i = 0; i < n; ++i)
    {
        while (each[i]--)
            cout << cf[i];
    }
    cout << endl;
    return 0;
}

{% endraw %}
```
