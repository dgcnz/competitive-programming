---
layout: post
title: Abc179_B Go To Jail
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
    int n;
    cin >> n;
    vector<ii> d(n);
    for (auto &[f, s] : d)
        cin >> f >> s;
    int cnt = 0;
    for (auto [f, s] : d)
    {
        if (f == s)
        {
            cnt++;
        }
        else
        {
            if (cnt >= 3)
            {
                cout << "Yes" << endl;
                return 0;
            }
            cnt = 0;
        }
    }
    if (cnt >= 3)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}

{% endraw %}
```
