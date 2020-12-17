---
layout: post
mathjax: true
title: abc185_a - Abc Preparation
problem_url: https://atcoder.jp/contests/abc185/tasks/abc185_a
tags: easy
memory_complexity: O(1)
time_complexity: O(1)
---

The answer is the minimum of $a_1$, $a_2$, $a_3$ and $a_4$.


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
template <typename InputIterator,
          typename T = typename iterator_traits<InputIterator>::value_type>
void read_n(InputIterator it, int n)
{
    copy_n(istream_iterator<T>(cin), n, it);
}
int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    array<int, 4> a;
    read_n(begin(a), 4);
    cout << *min_element(begin(a), end(a)) << endl;
    return 0;
}

{% endraw %}
```
</details>

