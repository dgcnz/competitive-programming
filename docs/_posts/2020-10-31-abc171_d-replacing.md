---
layout: post
mathjax: true
title: Abc171_D Replacing
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
int const AMAX = 1e5 + 11;
ll freq[AMAX], sum;
void update(ll b, ll c)
{
    sum -= b * freq[b];
    sum += freq[b] * c;
    freq[c] += freq[b];
    freq[b] = 0;
}
inline ll query(void) { return sum; }
int main(void)
{
    int n, q, ai, b, c;
    cin >> n;
    sum = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> ai;
        freq[ai]++;
        sum += ai;
    }
    cin >> q;
    while (q--)
    {
        cin >> b >> c;
        update(b, c);
        cout << query() << endl;
    }
    return 0;
}

{% endraw %}
```