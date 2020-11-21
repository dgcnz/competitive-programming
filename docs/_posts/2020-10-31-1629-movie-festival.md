---
layout: post
mathjax: true
title: 1629 Movie Festival
url: None
tags: None
time_complexity: None
memory_complexity: None
---

None

```cpp
{% raw %}
using namespace std;
using ii = pair<int, int>;
using vii = vector<ii>;
int main(void)
{
    int n, last = 0, ans = 0;
    cin >> n;
    vii movies(n);
    for (auto &[s, e] : movies)
        cin >> s >> e;
    sort(movies.begin(), movies.end(), [](ii x, ii y) {
        return x.second < y.second;
    });
    for (auto [s, e] : movies)
    {
        if (last <= s)
        {
            last = e;
            ans += 1;
        }
    }
    cout << ans << endl;
    return 0;
}

{% endraw %}
```
