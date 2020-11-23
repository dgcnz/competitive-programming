---
layout: post
mathjax: true
title: 11034 Ferry Loading Iv
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
    int t;
    cin >> t;
    while (t--)
    {
        int l, m;
        vi left, right;
        cin >> l >> m;
        l *= 100;
        while (m--)
        {
            int len;
            string side;
            cin >> len >> side;
            if (side[0] == 'l')
                left.push_back(len);
            else
                right.push_back(len);
        }
        int lans = 0, rans = 0, cur_acc = 0;
        for (auto len : left)
        {
            if (cur_acc + len >= l)
            {
                lans++;
                cur_acc = len;
            }
            else
                cur_acc += len;
        }
        if (cur_acc > 0)
            ++lans;
        cur_acc = 0;
        for (auto len : right)
        {
            if (cur_acc + len >= l)
            {
                rans++;
                cur_acc = len;
            }
            else
                cur_acc += len;
        }
        if (cur_acc > 0)
            ++rans;
        cout << 2 * max(lans, rans) - (lans > rans ? 1 : 0) << endl;
    }
    return 0;
}

{% endraw %}
```
</details>

