---
layout: post
mathjax: true
title: 1624 Chessboard And Queens
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
int const NMAX = 8;
bool reserved[NMAX][NMAX];
int queen_at_row[NMAX];
bool valid(int row, int col)
{
    if (reserved[row][col])
        return false;
    for (int r = 0, c = queen_at_row[0]; r < row; ++r, c = queen_at_row[r])
        if (c == col or abs(r - row) == abs(c - col))
            return false;
    return true;
}
ll backtrack(int row)
{
    if (row == NMAX)
        return 1;
    ll ans = 0;
    for (int col = 0; col < NMAX; ++col)
    {
        if (valid(row, col))
        {
            queen_at_row[row] = col;
            ans += backtrack(row + 1);
            queen_at_row[row] = 0;
        }
    }
    return ans;
}
int main(void)
{
    char ch;
    for (int r = 0; r < NMAX; ++r)
    {
        for (int c = 0; c < NMAX; ++c)
        {
            cin >> ch;
            reserved[r][c] = (ch == '*');
        }
    }
    cout << backtrack(0) << endl;
    return 0;
}

{% endraw %}
```
</details>

