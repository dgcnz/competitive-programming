---
layout: post
mathjax: true
title: 550C Divisibility Eight
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
map<string, string> mem;
bool is_divisible_eight(string n)
{
    int len = n.size();
    if ((n[len - 1] - '0') % 2 == 1)
        return false;
    else if (len <= 3)
        return (stoi(n) % 8) == 0;
    else
        return is_divisible_eight(n.substr(len - 3, 3));
}
string dp(string n)
{
    int len = n.size();
    string copy;
    if (len == 0)
        return "x";
    if (len == 1 and (n[0] != '8' and n[0] != '0'))
        return "x";
    if (len > 1 and n[0] == '0')
        return "x";
    if (is_divisible_eight(n))
        return n;
    string &ans = mem[n];
    if (ans != "")
        return ans;
    for (int i = max(0, len - 3); i < len; ++i)
    {
        copy = n;
        ans = dp(copy.erase(i, 1));
        if (ans != "x")
            return ans;
    }
    return ans;
}
int main(void)
{
    string n;
    cin >> n;
    while ((n[n.size() - 1] - '0') % 2 == 1)
        n.pop_back();
    string ans = dp(n);
    if (ans == "x")
        cout << "NO";
    else
        cout << "YES" << endl << ans;
    cout << endl;
    return 0;
}

{% endraw %}
```
</details>

