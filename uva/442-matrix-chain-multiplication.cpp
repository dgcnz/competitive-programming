#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#endif
#include <bits/stdc++.h>
#define all(c) c.begin(), c.end()
#define isz(c) (int)c.size()

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
    char  attr;
};

struct Parser
{
    string input;
    int    ix, n;

    Parser(string input) : input(input), ix(0) { n = isz(input); }

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

    inline ll    cost(ii a, ii b) { return a.first * a.second * b.second; }
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
            if (lmat.first.second == rmat.first.first) // hate you c++11
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
        int  rows, cols;
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
