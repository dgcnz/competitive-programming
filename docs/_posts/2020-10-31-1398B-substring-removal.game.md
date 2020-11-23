---
layout: post
mathjax: true
title: 1398B Substring Removal.Game
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
int main(void)
{
    int t, cnt;
    string s;
    vi scores;
    cin >> t;
    while (t--)
    {
        cin >> s;
        cnt = 0;
        scores.clear();
        for (auto c : s)
        {
            if (c == '1')
            {
                ++cnt;
            }
            else
            {
                if (cnt != 0)
                    scores.push_back(cnt);
                cnt = 0;
            }
        }
        if (cnt != 0)
            scores.push_back(cnt);
        sort(scores.begin(), scores.end(), greater<int>());
        int ans = 0;
        for (int i = 0, n = scores.size(); i < n; i += 2)
            ans += scores[i];
        cout << ans << endl;
    }
    return 0;
}

{% endraw %}
```
</details>

