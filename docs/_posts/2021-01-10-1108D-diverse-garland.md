---
layout: post
mathjax: true
title: 1108D - Diverse Garland
problem_url: https://codeforces.com/contest/1108/problem/D
tags: greedy, implementation
memory_complexity: O(n)
time_complexity: O(n)
---

Fix blocks of consecutive characters greedily.
[Editorial](https://codeforces.com/blog/entry/64751).


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
char mex(string alpha, vector<char> prohibited)
{
    for (auto c : alpha)
        if (find(begin(prohibited), end(prohibited), c) == prohibited.end())
            return c;
    return 0;
}
int solve(string &s)
{
    int i = 0, n = (int)(s).size(), ans = 0;
    s += " ";
    while (i < n)
    {
        int j = i + 1;
        while (j < n and s[i] == s[j])
            ++j;
        if (j - i > 1)
        {
            for (int k = i + 1; k < j - 1; k += 2)
                s[k] = mex("RGB", {s[i]}), ans++;
            if ((j - i) % 2 == 0)
                s[j - 1] = mex("RGB", {s[i], s[j]}), ans++;
        }
        i = j;
    }
    s.pop_back();
    return ans;
}
int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n;
    string s;
    cin >> n >> s;
    cout << solve(s) << endl;
    cout << s << endl;
    return 0;
}

{% endraw %}
```
</details>

