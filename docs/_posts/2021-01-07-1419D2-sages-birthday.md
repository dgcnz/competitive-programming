---
layout: post
mathjax: true
title: 1419D2 - Sages Birthday
problem_url: https://codeforces.com/contest/1419/problem/D2
tags: binary_search, greedy
memory_complexity: O(n)
time_complexity: O(n \log{n})
---

Given a number of desired cheap ice, $x$, pick the $x$ smallest numbers and
alternate them with the larges ones. Binary search to find $x$.

[Editorial](https://codeforces.com/blog/entry/82817).


{% if page.time_complexity != "None" %}
Time complexity: ${{ page.time_complexity }}$
{% endif %}

{% if page.memory_complexity != "None" %}
Memory complexity: ${{ page.memory_complexity }}$
{% endif %}

<details>
<summary>
<p style="display:inline">Click to show code.</p>
</summary>
```cpp
{% raw %}
using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
int bs(int l, int r, function<bool(int)> p)
{
    while (l < r)
    {
        int m = l + (r - l + 1) / 2;
        if (p(m))
            l = m;
        else
            r = m - 1;
    }
    return l;
}
int solve(vi &a)
{
    int n = (int)(a).size();
    sort(begin(a), end(a));
    auto ok = [&a, n](int x) {
        for (int i = 0; i < x; i++)
        {
            int j = x - i - 1, l = n - i - 2, r = n - i - 1;
            if (!(a[l] > a[j] and a[j] < a[r]))
                return false;
        }
        return true;
    };
    int x = bs(0, (n - 1) / 2, ok);
    if (x == 0)
        return x;
    int i = n - 1;
    vi left(a.begin(), a.begin() + x), right(a.begin() + x, a.end());
    while (left.size())
    {
        a[i--] = right.back();
        right.pop_back();
        a[i--] = left.back();
        left.pop_back();
    }
    while (right.size())
    {
        a[i--] = right.back();
        right.pop_back();
    }
    return x;
}
int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n;
    cin >> n;
    vi a(n);
    for (auto &ai : a)
        cin >> ai;
    cout << solve(a) << endl;
    for (auto ai : a)
        cout << ai << " ";
    cout << endl;
    return 0;
}

{% endraw %}
```
</details>

