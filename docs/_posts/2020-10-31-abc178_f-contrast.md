---
layout: post
mathjax: true
title: Abc178_F Contrast
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
using vi = vector<int>;
int main(void)
{
    int n;
    cin >> n;
    vi a(n), b(n);
    for (auto &ai : a)
        cin >> ai;
    for (auto &bi : b)
        cin >> bi;
    sort(b.begin(), b.end(), greater<int>());
    int l = 0, r = n - 1;
    for (int i = 0; i < n; ++i)
    {
        if (b[i] == a[i])
        {
            if (a[l] != b[i])
            {
                swap(b[l], b[i]);
                ++l;
            }
        }
    }
    for (int i = n - 1; i >= 0; --i)
    {
        if (b[i] == a[i])
        {
            if (a[r] != b[i])
            {
                swap(b[r], b[i]);
                --r;
            }
        }
    }
    for (int i = 0; i < n; ++i)
    {
        if (b[i] == a[i])
        {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    for (int i = 0; i < n; ++i)
    {
        cout << b[i] << " ";
    }
    cout << endl;
    return 0;
}

{% endraw %}
```