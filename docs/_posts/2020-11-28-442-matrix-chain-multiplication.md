---
layout: post
mathjax: true
title: 442 - Matrix Chain Multiplication
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
array<ii, 26> dims;
enum ttype
{
    LPAR,
    RPAR,
    MAT,
    END
};
struct Token
{
    ttype type;
    char attr;
};
struct Parser
{
    string input;
    int ix, n;
    Parser(string input) : input(input), ix(0) { n = (int)input.size(); }
    Token get_token(void) const
    {
        if (ix == n)
            return {END, 0};
        else
        {
            char c = input[ix];
            if (isalpha(c))
                return {MAT, c};
            else if (c == '(')
                return {LPAR, c};
            else if (c == ')')
                return {RPAR, c};
            else
                throw -1;
        }
    }
    void eat(ttype t)
    {
        if (t != get_token().type)
            throw -1;
        ++ix;
    }
    inline ll cost(ii a, ii b) { return a.first * a.second * b.second; }
    pair<ii, ll> expr(void)
    {
        Token tkn = get_token();
        if (tkn.type == MAT)
        {
            eat(MAT);
            return {dims[tkn.attr - 'A'], 0};
        }
        else if (tkn.type == LPAR)
        {
            eat(LPAR);
            pair<ii, ll> lmat = expr();
            pair<ii, ll> rmat = expr();
            eat(RPAR);
            if (lmat.first.second == rmat.first.first)
                return {{lmat.first.first, rmat.first.second},
                        lmat.second + rmat.second +
                            cost(lmat.first, rmat.first)};
            else
                throw -1;
        }
        else
            throw -1;
    }
};
int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n;
    cin >> n;
    while (n--)
    {
        char name;
        int rows, cols;
        cin >> name >> rows >> cols;
        dims[name - 'A'] = {rows, cols};
    }
    string line;
    while (cin >> line)
    {
        try
        {
            Parser p(line);
            cout << p.expr().second << endl;
        }
        catch (int e)
        {
            cout << "error" << endl;
        }
    }
    return 0;
}

{% endraw %}
```
</details>

