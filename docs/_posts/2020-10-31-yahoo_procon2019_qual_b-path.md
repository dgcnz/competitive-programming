---
layout: post
mathjax: true
title: Yahoo_Procon2019_Qual_B Path
url: None
tags: None
time_complexity: None
memory_complexity: None
---

None

```cpp
{% raw %}
using namespace std;
int main(void)
{
    int u, v;
    vector<int> deg(5, 0);
    for (int i = 0; i < 3; ++i)
    {
        cin >> u >> v;
        ++deg[u], ++deg[v];
    }
    int ones = 2;
    int evens = 2;
    for (int i = 1; i < 5; ++i)
    {
        if (deg[i] == 1)
            --ones;
        else if (deg[i] % 2 == 0)
            --evens;
    }
    if (ones == 0 and evens == 0)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}

{% endraw %}
```
