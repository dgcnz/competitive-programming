---
layout: post
title: 101498J Spilt The String
url: https://codeforces.com/gym/101498/problem/J
tags: brute-force, math
time_complexity: None
memory_complexity: [O(n)]
---

Note that we only care about the position of the whitespaces, since we can't break words.
We can iterate all whitespaces (they will define the end of the first line with width $w$) and test if positions $2w, 3w, ...$ also contain whitespaces.
By harmonic series approximation, each test call runs in O(logn)

```cpp
{% raw %}
using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
bool test(int width, string &line)
{
    int n = (int)(line).size(), i = width - 1;
    for (int d = 1; i < n; i = width * d - 1, ++d)
    {
        if (line[i] != ' ')
            return false;
    }
    return i == n;
}
bool solve(string line)
{
    for (int i = 0, n = (int)(line).size(); i < n; ++i)
    {
        if (line[i] == ' ')
        {
            if (test(i + 1, line))
                return true;
        }
    }
    return false;
}
int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        string line;
        getline(cin, line);
        cout << (solve(line) ? "YES" : "NO") << endl;
    }
    return 0;
}

{% endraw %}
```
