---
layout: post
mathjax: true
title: 1461A - String Generation
problem_url: https://codeforces.com/contest/1461/problem/A
tags: easy, constructive, greedy
memory_complexity: O(1)
time_complexity: O(n)
---

Stacking "abc" together, will have the following property: No character will
have neighbors that are equal to each other or to itself.

All palindromes need at least its center to be this way, so constructing one
is impossible.


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
template <typename InputIterator,
          typename T = typename iterator_traits<InputIterator>::value_type>
void write(InputIterator first, InputIterator last, const char *delim = "\n")
{
    copy(first, last, ostream_iterator<T>(cout, delim));
}
int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        string ch = "abc";
        for (int i = 0; i < n; ++i)
            cout << ch[i % 3];
        cout << endl;
    }
    return 0;
}

{% endraw %}
```
</details>

