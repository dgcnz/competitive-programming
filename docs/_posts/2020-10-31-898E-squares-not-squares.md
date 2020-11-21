---
layout: post
title: 898E Squares Not Squares
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
    vector<ii> diff;
    for (int i = 0; i < n; ++i)
    {
        ll ai, sq;
        cin >> ai;
        sq = round(sqrt(ai));
        diff.emplace_back(abs(ai - sq * sq), ai);
    }
    sort(diff.begin(), diff.end());
    ll ans = 0;
    for (int i = 0; i < n / 2; ++i)
        ans += diff[i].first;
    for (int i = n / 2; i < n; ++i)
        ans += (diff[i].first != 0 ? 0 : 1 + !diff[i].second);
    cout << ans << endl;
    return 0;
}

{% endraw %}
```
