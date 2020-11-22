---
layout: post
mathjax: true
title: 1405C Balanced Bitstring
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
using vi = vector<int>;
bool solve(string s, int k)
{
    int n = (int)s.size();;
    string t(s.begin(), s.begin() + k);
    for (int i = k; i < n; i += k)
    {
        for (int j = 0; j < k and j + i < n; ++j)
        {
            int ix = i + j;
            if (s[ix] != '?' and t[j] == '?')
                t[j] = s[ix];
            else if (s[ix] != '?' and t[j] != '?' and s[ix] != t[j])
                return false;
        }
    }
    int zeros = count_if(t.begin(), t.end(), [](char c) { return c == '0'; });
    int ones = count_if(t.begin(), t.end(), [](char c) { return c == '1'; });
    return ones <= k / 2 and zeros <= k / 2;
}
int main(void)
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        string s;
        cin >> n >> k;
        cin >> s;
        cout << (solve(s, k) ? "YES" : "NO") << endl;
    }
    return 0;
}

{% endraw %}
```