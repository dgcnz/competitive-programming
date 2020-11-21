---
layout: post
title: Abc167_A Registration
url: None
tags: None

time_complexity: None
memory_complexity: None
---

None

```cpp
using namespace std;
int main(void)
{
    string s, t;
    cin >> s >> t;
    bool ok = s == t.substr(0, t.size() - 1);
    cout << (ok ? "Yes" : "No") << endl;
    return 0;
}

```
