---
layout: post
mathjax: true
title: 1385B Restore Permutation Merger
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
using vi = vector<int>;
int main(void)
{
    int t, n, ai;
    vi cnt;
    cin >> t;
    while (t--)
    {
        cin >> n;
        cnt.assign(n + 1, 0);
        n *= 2;
        while (n--)
        {
            cin >> ai;
            cnt[ai]++;
            if (cnt[ai] == 2)
                cout << ai << " ";
        }
        cout << endl;
    }
    return 0;
}

{% endraw %}
```