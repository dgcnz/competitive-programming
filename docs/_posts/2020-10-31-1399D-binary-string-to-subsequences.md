---
layout: post
mathjax: true
title: 1399D Binary String To Subsequences
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
</details>

