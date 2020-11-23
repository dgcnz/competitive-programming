---
layout: post
mathjax: true
title: 408 Uniform Generator
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
int gcd(int a, int b) { return (b == 0 ? a : gcd(b, a % b)); }
int main(void)
{
    int a, b;
    string ans;
    while (cin >> a >> b)
    {
        if (gcd(a, b) == 1)
            ans = "Good Choice";
        else
            ans = "Bad Choice";
        cout << setw(10) << right << a << setw(10) << b << setw(4) << " "
             << left << ans << endl
             << endl;
    }
}

{% endraw %}
```
</details>

