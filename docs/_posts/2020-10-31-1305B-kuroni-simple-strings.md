---
layout: post
mathjax: true
title: 1305B Kuroni Simple Strings
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
string s;
void solve(void)
{
    vi lpar_i;
    vi rpar_i;
    for (int i = 0; i < s.size(); ++i)
    {
        if (s[i] == '(')
            lpar_i.push_back(i + 1);
        else
            rpar_i.push_back(i + 1);
    }
    queue<int> l;
    stack<int> r;
    if (rpar_i.size() > 0 and lpar_i.size() > 0)
    {
        int i = 0;
        int j = rpar_i.size() - 1;
        while (i < lpar_i.size() and j >= 0 and lpar_i[i] < rpar_i[j])
        {
            l.push(lpar_i[i]);
            r.push(rpar_i[j]);
            ++i;
            --j;
        }
    }
    int n = l.size() + r.size();
    cout << (n > 0 ? 1 : 0) << endl;
    if (n > 0)
        cout << n << endl;
    while (l.size())
    {
        cout << l.front() << " ";
        l.pop();
    }
    while (r.size())
    {
        cout << r.top() << " ";
        r.pop();
    }
    cout << endl;
}
int main(void)
{
    cin >> s;
    solve();
    return 0;
}

{% endraw %}
```
</details>

