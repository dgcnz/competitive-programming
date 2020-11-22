---
layout: post
mathjax: true
title: 1164 Room Allocation
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
using iii = tuple<int, int, int>;
using vi = vector<int>;
using viii = vector<iii>;
int main(void)
{
    int n, x, y;
    viii events;
    vi ans, rooms;
    cin >> n;
    ans = vi(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> x >> y;
        events.push_back({x, -1, i});
        events.push_back({y, 1, i});
    }
    sort(events.begin(), events.end());
    int occupied = 0, max_rooms = 0;
    for (auto [t, sign, i] : events)
    {
        if (sign == 1)
            rooms.push_back(ans[i]);
        else if (occupied == (int)rooms.size())
            ans[i] = ++max_rooms;
        else
            ans[i] = rooms[occupied++];
    }
    cout << max_rooms << endl;
    for (int i = 1; i <= n; i++)
        cout << ans[i] << " ";
    cout << endl;
    return 0;
}

{% endraw %}
```