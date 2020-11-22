---
layout: post
mathjax: true
title: Abc173_B Judge Status Summary
problem_url: None
tags: None
memory_complexity: None
time_complexity: None
---

None


{% if page.time_complexity != "None" %}
- Time complexity: ${{ page.time_complexity }}$
{% endif %}
{% if page.memory_complexity != "None" %}
- Memory complexity: ${{ page.memory_complexity }}$
{% endif %}
{% if page.tags != "None" %}
- Tags: {{ page.tags }}
{% endif %}

{% if page.problem_url != "None" %}
- [URL]({{ page.problem_url }})
{% endif %}

```cpp
{% raw %}
using namespace std;
int main(void)
{
    int n;
    string stat;
    map<string, int> counter;
    cin >> n;
    while (n--)
    {
        cin >> stat;
        counter[stat]++;
    }
    cout << "AC x " << counter["AC"] << endl;
    cout << "WA x " << counter["WA"] << endl;
    cout << "TLE x " << counter["TLE"] << endl;
    cout << "RE x " << counter["RE"] << endl;
    return 0;
}

{% endraw %}
```