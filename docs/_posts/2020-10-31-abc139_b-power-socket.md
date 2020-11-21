---
layout: post
mathjax: true
title: Abc139_B Power Socket
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
using vi = vector<int>;
int main(void)
{
    int a, b;
    cin >> a >> b;
    b--;
    a--;
    cout << (a + b - 1) / a << endl;
    return 0;
}

{% endraw %}
```
