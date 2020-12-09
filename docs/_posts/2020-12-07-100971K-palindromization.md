---
layout: post
mathjax: true
title: 100971K - Palindromization
problem_url: https://codeforces.com/gym/100971/problem/K
tags: strings, implementation
memory_complexity: O(n)
time_complexity: O(n)
---

Assume that $s$ is not already a palindrome (if it is, then just remove the
middle character, as it will remain a palindrome).

If $s$ can be turned into a palindrome by the removal of a character at
position $k$, then it has the form:

$$s_1 s_2 ... s_{k - 1} s_k s_{k + 1} ... s_{k + 1} s_{k - 1} ... s_2 s_1 $$

We can observe that such string has a matching suffix and prefix up to
position $k$, but it is uncertain if $s_k$ or $s_{n - k}$ should be removed.

However, we know that if we remove one of those characters, then the
remaining characters must necessarily match.

So we just try both options and see if one matches, if not, it's impossible
because there would necessarily be at least 2 characters to remove in order
to make the string palindromic.


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
bool test(const string &s, int l, int r)
{
    while (l < r)
    {
        if (s[l] != s[r])
            return false;
        ++l, --r;
    }
    return true;
}
int solve(string s)
{
    int n = (int)(s).size();
    int l = 0, r = n - 1;
    while (l < r)
    {
        if (s[l] != s[r])
        {
            if (test(s, l + 1, r))
                return l;
            else if (test(s, l, r - 1))
                return r;
            else
                return -1;
        }
        else
            ++l, --r;
    }
    return n / 2;
}
int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    string s;
    cin >> s;
    if (auto ans = solve(s); ans != -1)
    {
        cout << "YES" << endl;
        cout << ans + 1 << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}

{% endraw %}
```
</details>

