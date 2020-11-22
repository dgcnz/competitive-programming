---
layout: post
mathjax: true
title: 1395A Boboniu Likes To Color Balls
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
using vi = vector<int>;
bool is_odd(int c) { return c % 2 == 1; }
bool is_even(int c) { return c % 2 == 0; }
bool possible(vi rgbw)
{
    return *min_element(rgbw.begin(), prev(rgbw.end())) >= 1;
}
bool solve(vi rgbw)
{
    if (all_of(rgbw.begin(), rgbw.end(), is_even))
        return true;
    if (rgbw.back() % 2 == 1)
    {
        int cnt = count_if(rgbw.begin(), prev(rgbw.end()), is_odd);
        if (cnt == 0)
            return true;
        else if (cnt == 1)
            return false;
        else
            return possible(rgbw);
    }
    else
    {
        int cnt = count_if(rgbw.begin(), prev(rgbw.end()), is_odd);
        if (cnt == 0)
            return true;
        if (cnt == 1)
            return true;
        else if (cnt == 2)
            return false;
        else
            return possible(rgbw);
    }
}
int main(void)
{
    int t;
    vi rgbw(4);
    cin >> t;
    while (t--)
    {
        for (auto &c : rgbw)
            cin >> c;
        cout << (solve(rgbw) ? "Yes" : "No") << endl;
    }
    return 0;
}

{% endraw %}
```