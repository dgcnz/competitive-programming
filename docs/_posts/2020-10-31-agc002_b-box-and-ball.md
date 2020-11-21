---
layout: post
mathjax: true
title: Agc002_B Box And Ball
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
int main(void)
{
    int n, m, xi, yi;
    vi red, cnt;
    cin >> n >> m;
    cnt.resize(n, 1), red.resize(n, false);
    red[0] = true;
    for (int i = 0; i < m; ++i)
    {
        cin >> xi >> yi, xi--, yi--;
        red[yi] |= red[xi];
        cnt[xi] -= 1;
        cnt[yi] += 1;
        if (cnt[xi] == 0)
            red[xi] = false;
    }
    cout << accumulate(red.begin(), red.end(), 0) << endl;
    return 0;
}

{% endraw %}
```
