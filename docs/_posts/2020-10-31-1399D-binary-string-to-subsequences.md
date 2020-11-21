---
layout: post
title: 1399D Binary String To Subsequences
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
using ii = pair<int, int>;
int main(void)
{
    int t, n;
    string s;
    vi ans;
    set<ii> frontier;
    cin >> t;
    while (t--)
    {
        cin >> n >> s;
        ans.assign(n, -1);
        for (int i = 0; i < n; ++i)
        {
            auto it = frontier.lower_bound({'1' - s[i], 0});
            if (it != frontier.end() and it->first != (s[i] - '0'))
            {
                auto [t, id] = *it;
                frontier.erase(it);
                ans[i] = id;
                frontier.insert({s[i] - '0', ans[i]});
            }
            else
            {
                ans[i] = frontier.size();
                frontier.insert({s[i] - '0', ans[i]});
            }
        }
        cout << frontier.size() << endl;
        for (int i = 0; i < n; ++i)
            cout << ans[i] + 1 << " ";
        cout << endl;
        frontier.clear();
    }
    return 0;
}

{% endraw %}
```
