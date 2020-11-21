---
layout: post
title: 44A Indian Summer
url: None
tags: None
time_complexity: None
memory_complexity: None
---

None

```cpp
{% raw %}
using namespace std;
map<string, bool> was_already_collected;
int main(void)
{
    int n, counter = 0;
    string tree_kind;
    cin >> n;
    cin.ignore();
    while (n--)
    {
        getline(cin, tree_kind);
        if (not was_already_collected[tree_kind])
            ++counter;
        was_already_collected[tree_kind] = true;
    }
    cout << counter << endl;
    return 0;
}

{% endraw %}
```
