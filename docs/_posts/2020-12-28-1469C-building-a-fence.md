---
layout: post
mathjax: true
title: 1469C - Building A Fence
problem_url: https://codeforces.com/contest/1469/problem/C
tags: greedy, sorting
memory_complexity: O(n)
time_complexity: O(n \log{n})
---

Intuitively, the position with highest ground level constraints its
neighbors. We build on top of this idea.

We'll maintain a priority queue or set where each position is ordered based
on their ground level height, decreasingly.

The idea is that, we start from the highest ground level, update its
neighbors heights so that they minimally share a side with it, mark it as
done and continue with the next highest position. If at any step we can't
perform an update on the neighbors (as it would exceed the $k - 1$
displacement from their ground level), then it's impossible.

Since we're updating from top to bottom and updating the neighbor's height to
minimally share a side, we'll never place a fence too far down (or if we do,
then it's fixable. I'm lazy today, so I'll skip the proof.).


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
bool solve(vi h, int k)
{
    int n = (int)(h).size();
    set<ii, greater<ii>> hordered;
    for (int i = 0; i < n; ++i)
        hordered.emplace(h[i], i);
    vector<bool> visited(n, false);
    for (int j = 0; j < n; ++j)
    {
        auto cur = hordered.begin();
        auto [hi, i] = *cur;
        if (i - 1 >= 0 and not visited[i - 1])
        {
            int hmax = h[i - 1] + (i - 1 == 0 ? k - 1 : 2 * k - 2);
            if (h[i] > hmax)
                return false;
            auto it = hordered.find(ii{h[i - 1], i - 1});
            h[i - 1] = max(hi - k + 1, h[i - 1]);
            hordered.erase(it);
            hordered.emplace(h[i - 1], i - 1);
        }
        if (i + 1 < n and not visited[i + 1])
        {
            int hmax = h[i + 1] + (i + 1 == n - 1 ? k - 1 : 2 * k - 2);
            if (h[i] > hmax)
                return false;
            auto it = hordered.find(ii{h[i + 1], i + 1});
            h[i + 1] = max(h[i] - k + 1, h[i + 1]);
            hordered.erase(it);
            hordered.emplace(h[i + 1], i + 1);
        }
        visited[i] = true;
        hordered.erase(cur);
    }
    return true;
}
int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vi h(n);
        for (auto &x : h)
            cin >> x;
        cout << (solve(h, k) ? "YES" : "NO") << endl;
    }
    return 0;
}

{% endraw %}
```
</details>

