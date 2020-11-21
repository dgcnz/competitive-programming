---
layout: post
mathjax: true
title: 1622 Creating Strings I
url: None
tags: None
time_complexity: None
memory_complexity: None
---

{% raw %}
None
{% endraw %}

```cpp
{% raw %}
using namespace std;
int main(void)
{
    string s;
    vector<string> ans;
    cin >> s;
    sort(s.begin(), s.end());
    do
    {
        ans.push_back(s);
    } while (next_permutation(s.begin(), s.end()));
    cout << ans.size() << endl;
    for (auto a : ans)
        cout << a << endl;
    return 0;
}

{% endraw %}
```
