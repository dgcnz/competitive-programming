---
layout: post
title: Abc146_A Cant Wait For Holiday
url: None
tags: None

time_complexity: None
memory_complexity: None
---

None

```cpp
using namespace std;
vector<string> days = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
int main(void)
{
    string s;
    cin >> s;
    int n = days.size();
    int pos = distance(days.begin(), find(days.begin(), days.end(), s));
    cout << n - pos << endl;
    return 0;
}

```
