---
layout: post
mathjax: true
title: Abc179_A Plural Form
url: None
tags: None
time_complexity: None
memory_complexity: None
---

None

```cpp
{% raw %}
using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
int main(void)
{
    string s;
    cin >> s;
    if (s.back() == 's')
        cout << s << "es" << endl;
    else
        cout << s << "s" << endl;
    return 0;
}

{% endraw %}
```
