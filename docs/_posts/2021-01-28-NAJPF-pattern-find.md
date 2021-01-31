---
layout: post
mathjax: true
title: NAJPF - Pattern Find
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
vi prefix_function(string s)
{
    int n = (int)s.size();
    vi pi(n, 0);
    for (int i = 1; i < n; i++)
    {
        int j = pi[i - 1];
        while (j > 0 and s[i] != s[j])
            j = pi[j - 1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}
int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        string str, pat;
        cin >> str >> pat;
        int pat_sz = (int)pat.size();
        auto pi = prefix_function(pat + "#" + str);
        vi ans;
        for (int i = pat_sz + 1, len = (int)pi.size(); i < len; ++i)
            if (pi[i] == pat_sz)
                ans.push_back(i + 1 - 2 * pat_sz);
        if ((int)ans.size() == 0)
            cout << "Not Found" << endl;
        else
            cout << (int)ans.size() << endl, write(ans.begin(), ans.end(), " "), cout << endl;
    }
    return 0;
}

{% endraw %}
```
</details>

