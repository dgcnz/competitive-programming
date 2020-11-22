---
layout: post
mathjax: true
title: 1420B Rock And Lever
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
using ii = pair<int, int>;
using vi = vector<ll>;
int main(void)
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vi a(n), cnt(64, 0);
        for (auto &ai : a)
        {
            cin >> ai;
            cnt[__builtin_clz(ai)]++;
        }
        ll ans = 0;
        for (auto x : cnt)
        {
            if (x == 0 or x == 1)
                continue;
            ans += (x * (x - 1)) / 2;
        }
        cout << ans << endl;
    }
    return 0;
}

{% endraw %}
```