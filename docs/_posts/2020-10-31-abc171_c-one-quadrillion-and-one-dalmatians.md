---
layout: post
title: Abc171_C One Quadrillion And One Dalmatians
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
