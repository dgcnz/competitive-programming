---
layout: post
mathjax: true
title: 1407A Ahahahahahahahaha
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
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
int main(void)
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int ones = 0, zeros = 0;
        for (int i = 0; i < n; ++i)
        {
            char c;
            cin >> c;
            if (c == '0')
                zeros++;
            else
                ones++;
        }
        int m = n / 2;
        if (zeros >= ones)
        {
            cout << m << endl;
            for (int i = 0; i < m; ++i)
                cout << '0' << " ";
            cout << endl;
        }
        else
        {
            if (m % 2 == 1)
                m++;
            cout << m << endl;
            for (int i = 0; i < m; ++i)
                cout << '1' << " ";
            cout << endl;
        }
    }
    return 0;
}

{% endraw %}
```
