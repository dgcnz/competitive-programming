---
layout: post
mathjax: true
title: 1367C Social Distance
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
const int INF = 1e6;
int main(void)
{
    int t, n, k, last;
    string s;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        cin >> s;
        last = -INF;
        int ans = 0;
        for (int i = 0; i < (int)s.size(); ++i)
        {
            if (s[i] == '1')
                last = i;
            else if (s[i] == '0' and last + k < i)
            {
                int j = i + 1;
                bool possible = true;
                while (j < n and j <= i + k)
                {
                    if (s[j] == '1')
                    {
                        possible = false;
                        break;
                    }
                    ++j;
                }
                if (possible)
                {
                    ans += 1;
                    s[i] = '1';
                    last = i;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}

{% endraw %}
```
</details>

