---
layout: post
mathjax: true
title: 1405A Permutation Forgery
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
using ll = long long;
using vi = vector<int>;
int main(void)
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vi a(n);
        for (auto &ai : a)
            cin >> ai;
        reverse(a.begin(), a.end());
        for (auto ai : a)
            cout << ai << " ";
        cout << endl;
    }
    return 0;
}

{% endraw %}
```
