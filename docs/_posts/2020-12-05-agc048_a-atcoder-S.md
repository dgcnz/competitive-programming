---
layout: post
mathjax: true
title: agc048_a - Atcoder S
problem_url: https://atcoder.jp/contests/agc048/tasks/agc048_a
tags: ad-hoc
memory_complexity: O(n)
time_complexity: O(n)
---

Let's handle some cases first:
 - If $s > a$, the answer is $0$. From now on we assume the opposite.
 - If and only if the whole string is composed from 'a's, there's on answer.

We'll assume otherwise from now on.

Observe that no matter the string, the maximum answer is the distance of the
first non-'a' from the start. However, if such character is greater than 't'
then we don't have to move it to the start, only to the second position.


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
int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;
    const string a = "atcoder";
    while (t--)
    {
        string s;
        cin >> s;
        if (a < s)
            cout << 0 << endl;
        else
        {
            if (auto it = find_if(begin(s), end(s), [](char c) { return c != 'a'; });
                it != s.end())
            {
                auto dist = distance(begin(s), it);
                cout << dist - (*it > 't') << endl;
            }
            else
                cout << -1 << endl;
        }
    }
    return 0;
}

{% endraw %}
```
</details>

