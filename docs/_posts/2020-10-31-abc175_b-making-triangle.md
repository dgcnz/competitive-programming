---
layout: post
mathjax: true
title: Abc175_B Making Triangle
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
bool is_valid(int a, int b, int c)
{
    if (a + b <= c or a + c <= b or b + c <= a)
        return false;
    else
        return true;
}
int main(void)
{
    int n;
    vi l;
    cin >> n;
    l.resize(n);
    for (auto &li : l)
        cin >> li;
    sort(l.begin(), l.end());
    ll ans = 0;
    for (int i = 0; i < n - 2; ++i)
    {
        for (int j = i + 1; j < n - 1; ++j)
        {
            for (int k = j + 1; k < n; ++k)
            {
                if (l[i] == l[j] or l[i] == l[k] or l[j] == l[k])
                    continue;
                bool cur = is_valid(l[i], l[j], l[k]);
                ans += cur;
            }
        }
    }
    cout << ans << endl;
    return 0;
}

{% endraw %}
```