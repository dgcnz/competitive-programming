---
layout: post
mathjax: true
title: 1282C Petya And Exam
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

```cpp
{% raw %}
using namespace std;
using ll = long long;
using ii = pair<ll, ll>;
using vi = vector<ll>;
ll n, T, a, b;
vector<ii> time_cost;
ll get_extra(ll window, ll easy_left, ll hard_left)
{
    auto temp_extra = min(window / a, easy_left), extra = temp_extra;
    window -= a * temp_extra;
    temp_extra = min(window / b, hard_left), extra += temp_extra;
    window -= b * temp_extra;
    return extra;
}
int solve(void)
{
    ll ans(0), acc_cost(0), taken_prev = 0;
    ll easy_left =
        count_if(time_cost.begin(), time_cost.end(), [](ii tc) { return tc.second == a; });
    ll hard_left =
        count_if(time_cost.begin(), time_cost.end(), [](ii tc) { return tc.second == b; });
    sort(time_cost.begin(), time_cost.end());
    time_cost.emplace_back(T + 1, a);
    for (auto [t, c] : time_cost)
    {
        ll new_acc_cost = acc_cost + c, cur = 0;
        taken_prev = n - (easy_left + hard_left);
        if (acc_cost < t)
            cur = max(cur,
                      taken_prev + get_extra(max((t - 1) - acc_cost, 0LL),
                                             easy_left,
                                             hard_left));
        if (c == a)
            easy_left--;
        else
            hard_left--;
        acc_cost = new_acc_cost;
        ans = max(ans, cur);
    }
    return ans;
}
int main(void)
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        cin >> n >> T >> a >> b;
        time_cost.resize(n);
        for (auto &[t, c] : time_cost)
            cin >> c, c = (c ? b : a);
        for (auto &[t, c] : time_cost)
            cin >> t;
        cout << solve() << endl;
    }
    return 0;
}

{% endraw %}
```