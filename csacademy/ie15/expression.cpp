#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <atcoder/modint>
#include <bits/stdc++.h>
#include <cplib/utils/io>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using namespace cplib;
using namespace atcoder;
using ll   = long long;
using ii   = pair<int, int>;
using vi   = vector<int>;
using mint = modint1000000007;

enum tkn_t
{
    LPAR,
    RPAR,
    NUM,
    PLUS,
    MINUS,
    MULTIPLY,
    EOL
};

struct Token
{
    string val;
    tkn_t  attr;
};

struct BadInput : public std::exception
{
    const char *what() const throw() { return "BadInput"; }
};

string s;
int    pos, n, open_par;
Token  current_tkn;

Token next_token()
{
    Token tkn;

    if (pos >= n)
        return current_tkn = {"", EOL};
    else if (isdigit(s[pos]))
    {
        tkn = {"", NUM};
        while (pos < n and isdigit(s[pos]))
            tkn.val.push_back(s[pos++]);
        pos--;
    }
    else if (s[pos] == ')')
        tkn = {")", RPAR};
    else if (s[pos] == '(')
        tkn = {"(", LPAR};
    else if (s[pos] == '+')
        tkn = {"+", PLUS};
    else if (s[pos] == '*')
        tkn = {"*", MULTIPLY};
    else if (s[pos] == '-')
        tkn = {"-", MINUS};
    else
        throw BadInput();

    pos++;
    return current_tkn = tkn;
};

mint E();

mint F()
{
    if (current_tkn.attr == NUM)
    {
        auto ans = mint(stoi(current_tkn.val));
        next_token();
        return ans;
    }
    else if (current_tkn.attr == LPAR)
    {
        open_par++;
        next_token();
        mint ans = E();
        if (current_tkn.attr == RPAR)
        {
            open_par--;
            next_token();
            return ans;
        }
        else
            throw BadInput();
    }
    else
        throw BadInput();
}

mint T()
{
    mint ans = F();
    while (current_tkn.attr == MULTIPLY)
    {
        next_token();
        ans *= F();
    }
    if (current_tkn.attr == EOL or current_tkn.attr == PLUS or
        current_tkn.attr == MINUS or
        (current_tkn.attr == RPAR and open_par > 0))
        return ans;
    else
        throw BadInput();
}

mint E()
{
    mint ans = T();
    while (current_tkn.attr == PLUS or current_tkn.attr == MINUS)
    {
        if (current_tkn.attr == PLUS)
        {
            next_token();
            ans += T();
        }
        else
        {
            next_token();
            ans -= T();
        }
    }
    if (current_tkn.attr == EOL or (current_tkn.attr == RPAR and open_par > 0))
        return ans;
    else
        throw BadInput();
};

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> s;
        pos = 0, open_par = 0;
        n = s.size();
        next_token();
        try
        {
            auto ans = E();
            cout << ans.val() << endl;
        }
        catch (BadInput &e)
        {
            cout << "invalid" << endl;
        }
    }
    return 0;
}
