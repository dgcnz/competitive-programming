---
layout: post
mathjax: true
title: 101755J Parallelograms
url: None
tags: None
time_complexity: None
memory_complexity: None
---

None

```cpp
{% raw %}
using namespace std;
using vi = vector<int>;
int const AMAX = 2e5 + 11;
int cnt[AMAX];
int main(void)
{
    int n, ai, pairs = 0;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> ai;
        cnt[ai]++;
        if (cnt[ai] % 2 == 0)
            pairs++;
    }
    cout << pairs / 2 << endl;
    return 0;
}

{% endraw %}
```
