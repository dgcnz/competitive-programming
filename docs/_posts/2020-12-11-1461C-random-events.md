---
layout: post
mathjax: true
title: 1461C - Random Events
problem_url: https://codeforces.com/contest/1461/problem/C
tags: observation, probability
memory_complexity: O(n)
time_complexity: O(n)
---

Key observation: we only care about the last position that is unsorted.

The reasoning behind this is that the numbers that go after that are already
sorted and the numbers that come before will always have more or equal
probability of getting sorted.

So, for such number $a_{last}$, the probability of staying unsorted is:

$$ (1 - p_{i_0}) (1 - p_{i_0}) ... (1 - p_{i_k}) $$

for all $i_j$'s such that $last \leq r_{i_j}$.


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
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
template <typename InputIterator,
          typename T = typename iterator_traits<InputIterator>::value_type>
void read_n(InputIterator it, int n)
{
    copy_n(istream_iterator<T>(cin), n, it);
}
int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vi a(n);
        read_n(begin(a), n);
        int last = n;
        while (last >= 1 and a[last - 1] == last)
            --last;
        double P_unsorted = (last == 0 ? 0.0 : 1.0);
        while (m--)
        {
            int r;
            double p;
            cin >> r >> p;
            if (r >= last)
                P_unsorted *= (double(1) - p);
        }
        cout << setprecision(12) << fixed << double(1) - P_unsorted << endl;
    }
    return 0;
}

{% endraw %}
```
</details>

