---
layout: post
title: 405A Gravity Flip
url: None
tags: None

time_complexity: None
memory_complexity: None
---

None

```cpp
using namespace std;
using vi = vector<int>;
int main(void)
{
    int n;
    vi v;
    cin >> n;
    v.resize(n);
    for (auto &x : v)
        cin >> x;
    sort(v.begin(), v.end());
    for (auto x : v)
        cout << x << " ";
    return 0;
}

```
