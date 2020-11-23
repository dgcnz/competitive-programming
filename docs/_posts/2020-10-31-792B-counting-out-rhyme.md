---
layout: post
mathjax: true
title: 792B Counting Out Rhyme
problem_url: None
tags: None
memory_complexity: None
time_complexity: None
---



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
using vi = vector<int>;
void print(vi v)
{
    for (auto x : v)
        cout << x << " ";
    cout << endl;
}
int main(void)
{
    int n, k, ai;
    cin >> n >> k;
    vi children(n);
    for (int i = 0; i < n; ++i)
        children[i] = i;
    int pos = 0, killed;
    while (k--)
    {
        cin >> ai;
        killed = (pos + ai % children.size()) % children.size();
        cout << children[killed] + 1 << " ";
        children.erase(children.begin() + killed);
        pos = killed % (children.size());
    }
    cout << endl;
}

{% endraw %}
```
</details>

