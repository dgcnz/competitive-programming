---
layout: post
mathjax: true
title: 792B Counting Out Rhyme
url: None
tags: None
time_complexity: None
memory_complexity: None
---

{% raw %}
None
{% endraw %}

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
