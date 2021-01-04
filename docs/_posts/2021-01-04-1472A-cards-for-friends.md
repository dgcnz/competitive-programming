---
layout: post
mathjax: true
title: 1472A - Cards For Friends
problem_url: https://codeforces.com/contest/1472/problem/A
tags: greedy, math
memory_complexity: O(1)
time_complexity: O(\log{h} + \log{w})
---

First note that the order of operations doesn't matter, and that if we have
currently $m$ identical pieces and we can make a certain cut $x$ (vertical or
horizontal), then we can make such cut for all $m$ pieces (duplicating its
number).

We only need duplicate our count of sheets the total amount of cuts we can
make.


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
bool solve(int w, int h, int n)
{
    int ptwo = 1, m = 1;
    while (w % 2 == 0)
    {
        m *= 2;
        w /= 2;
        ptwo *= 2;
    }
    ptwo = 1;
    while (h % 2 == 0)
    {
        m *= 2;
        h /= 2;
        ptwo *= 2;
    }
    return m >= n;
}
int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int w, h, n;
        cin >> w >> h >> n;
        cout << (solve(w, h, n) ? "YES" : "NO") << endl;
    }
    return 0;
}

{% endraw %}
```
</details>

