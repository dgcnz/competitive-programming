---
layout: post
title: Abc171_E Red Scarf
url: None
tags: None
time_complexity: None
memory_complexity: None
---

None

```cpp
{% raw %}
using namespace std;
using vi = vector<int>;
int main(void)
{
    int n, sum;
    vi a;
    cin >> n;
    sum = 0;
    a.resize(n);
    for (auto &ai : a)
    {
        cin >> ai;
        sum ^= ai;
    }
    for (auto ai : a)
        cout << (ai ^ sum) << " ";
    cout << endl;
    return 0;

{% endraw %}
```
