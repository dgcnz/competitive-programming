---
layout: post
mathjax: true
title: Abc171_C One Quadrillion And One Dalmatians
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

```cpp
{% raw %}
using namespace std;
using ll = long long;
int main(void)
{
    ll n;
    char c;
    string s;
    cin >> n;
    while (n > 0)
    {
        n -= 1;
        c = 'a' + (n % 26LL);
        s = c + s;
        n /= 26LL;
    };
    cout << s << endl;
    return 0;
}

{% endraw %}
```