---
layout: post
mathjax: true
title: 101755C Third Party Software
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
using iii = array<int, 3>;
int main(void)
{
    int n, last_close = 0, cnt = 0;
    vi s, e, ans;
    vector<iii> events;
    cin >> n;
    s.resize(n);
    e.resize(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> s[i] >> e[i];
        events.push_back({s[i], -1, i});
        events.push_back({e[i], +1, i});
    }
    sort(events.begin(), events.end());
    for (auto [t, sign, i] : events)
    {
        if (sign == -1)
            ++cnt;
        else if (sign == +1 and s[i] > last_close)
        {
            ans.push_back(t);
            last_close = t;
            cnt = 0;
        }
    }
    cout << ans.size() << endl;
    for (auto x : ans)
        cout << x << " ";
    cout << endl;
    return 0;
}

{% endraw %}
```
