---
layout: post
mathjax: true
title: 1478A - Nezzar And Colorful Balls
problem_url: https://codeforces.com/contest/1478/problem/A
tags: greedy
memory_complexity: O(n)
time_complexity: O(n)
---

Note that each subarray of equal value has to be painted with $x$ colors,
where $x$ is the size of such subarray. This is because otherwise, this would
yield a color sequence that is not strictly increasing.

To find the minimum number of colors needed, we need to find the biggest
subarray of equal value.


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
int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vi freq(n + 1, 0);
        for (int i = 0; i < n; ++i)
        {
            int ai;
            cin >> ai;
            freq[ai]++;
        }
        cout << *max_element(begin(freq), end(freq)) << endl;
    }
    return 0;
}

{% endraw %}
```
</details>

