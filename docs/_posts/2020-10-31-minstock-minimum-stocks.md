---
layout: post
mathjax: true
title: minstock - Minimum Stocks
problem_url: None
tags: None
memory_complexity: None
time_complexity: None
---



{% if page.time_complexity != "None" %}
Time complexity: ${{ page.time_complexity }}$
{% endif %}

{% if page.memory_complexity != "None" %}
Memory complexity: ${{ page.memory_complexity }}$
{% endif %}

<details>
<summary>
<p style="display:inline">Click to show code.</p>
</summary>
```cpp
{% raw %}
using namespace std;
int main(void)
{
    int op, n, price;
    string stock, s;
    set<pair<int, string>> stocks;
    map<string, int> stockprice;
    cin >> n;
    for (int day = 1; day <= n; ++day)
    {
        cin >> op;
        if (op == 1)
        {
            cin >> stock >> price;
            stockprice[stock] = price;
            stocks.insert({price, stock});
        }
        else if (op == 2)
        {
            cin >> stock >> price;
            stocks.erase({stockprice[stock], stock});
            stocks.insert({price, stock});
            stockprice[stock] = price;
        }
        else if (op == 3)
        {
            cin >> s;
            auto [price, stock] = *stocks.begin();
            cout << stock << " " << day << endl;
            stocks.erase(stocks.begin());
        }
    }
    return 0;
}

{% endraw %}
```
</details>

