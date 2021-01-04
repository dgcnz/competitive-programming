---
layout: post
mathjax: true
title: 1472B - Fair Division
problem_url: https://codeforces.com/contest/1472/problem/B
tags: math
memory_complexity: O(n)
time_complexity: O(n)
---

First, if the total sum is not even, then it's impossible. Assume otherwise.
Second, if we have an even amonut of $2$'s (we'll necesarily have an even
number of $1$s) we can split it into two equal groups with the same sum.
Otherwise, we need at least a pair of $1$'s to fill the missing $2$.



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
bool solve(vi a)
{
    int sum = accumulate(begin(a), end(a), 0), n = (int)(a).size();
    int ones = count_if(begin(a), end(a), [](int x) { return x == 1; });
    int twos = n - ones;
    return sum % 2 == 0 and ((twos % 2 == 0) or (ones > 0));
}
int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vi a(n);
        for (auto &ai : a)
            cin >> ai;
        cout << (solve(a) ? "YES" : "NO") << endl;
    }
    return 0;
}

{% endraw %}
```
</details>

