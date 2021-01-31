---
layout: post
mathjax: true
title: 10276 - Hanoi Tower Troubles Again
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
const int NMAX = 50;
int pegs[NMAX + 1];
int top[NMAX + 1];
bool vis[NMAX + 1];
bool isps(int x)
{
    if (x < 0)
        return false;
    int root(round(sqrt(x)));
    return x == root * root;
}
void precompute(void)
{
    int x = 1;
    while (true)
    {
        int peg;
        for (peg = 1; peg <= NMAX; ++peg)
        {
            if (top[peg] == 0 or isps(x + top[peg]))
            {
                if (not vis[peg])
                    pegs[peg - 1] = x - 1;
                vis[peg] = true;
                top[peg] = x;
                break;
            }
        }
        if (peg > NMAX)
        {
            pegs[peg - 1] = x - 1;
            return;
        }
        ++x;
    }
}
int main(void)
{
    int t, n;
    precompute();
    cin >> t;
    while (t--)
    {
        cin >> n;
        cout << pegs[n] << endl;
    }
    return 0;
}

{% endraw %}
```
</details>

