---
layout: post
title: 1164 Room Allocation
url: None
tags: None

time_complexity: None
memory_complexity: None
---

None

```cpp
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

```
