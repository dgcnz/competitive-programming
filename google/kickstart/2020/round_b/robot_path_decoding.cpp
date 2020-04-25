#include <iostream>
#include <map>
#include <string>
#include <utility>

using namespace std;
using ll  = long long;
using pll = pair<ll, ll>;

const ll NMAX = 1e9;

/*
 * Tokens:
 *      - DIGIT     : [1...9]
 *      - LPAR      : '('
 *      - RPAR      : ')'
 *      - DIRECTION : [N, W, S, E]
 *
 *
 * Grammar:
 *      <program> -> DIGIT LPAR <program> RPAR
 *      <program> -> DIRECTION <program>
 *
 */

enum tkntype
{
    DIGIT,
    LPAR,
    RPAR,
    DIRECTION,
    END
};

struct token
{
    tkntype type;  // type
    char    value; // attribute-value
};

int    n, pos;
string s;

map<char, pll> mv = {{'N', make_pair(0, -1)},
                     {'S', make_pair(0, 1)},
                     {'E', make_pair(1, 0)},
                     {'W', make_pair(-1, 0)}};

bool is_digit(char c) { return c > '0' and c <= '9'; }

bool is_char(char c) { return c >= 'A' and c <= 'Z'; }

ll mod(ll a, ll b) { return ((a % b) + b) % b; }

// (a + b) % m === (a % m + b % m) % m
pll add(pll a, pll b)
{
    return make_pair(mod(mod(a.first, NMAX) + mod(b.first, NMAX), NMAX),
                     mod(mod(a.second, NMAX) + mod(b.second, NMAX), NMAX));
}

// (a * b) % m === (a % m * b % m) % m
pll multiply(int a, pll b)
{
    return make_pair(mod(a * mod(b.first, NMAX), NMAX),
                     mod(a * mod(b.second, NMAX), NMAX));
}

token get_next_tkn(void)
{
    if (pos >= n)
        return {END, 0};

    token tkn;
    char  c = s[pos];

    if (is_digit(c))
        tkn = {DIGIT, c};
    else if (is_char(c))
        tkn = {DIRECTION, c};
    else if (c == '(')
        tkn = {LPAR, c};
    else if (c == ')')
        tkn = {RPAR, c};

    ++pos;
    return tkn;
}

pll program(void)
{
    pll   partial_ans;
    token tkn = get_next_tkn();
    token tkn2;

    if (tkn.type == DIGIT)
    {
        tkn2        = get_next_tkn(); // read LPAR
        partial_ans = multiply(tkn.value - '0', program());
        tkn2        = get_next_tkn(); // read RPAR
        return add(partial_ans, program());
    }
    else if (tkn.type == DIRECTION)
        return add(mv[tkn.value], program());
    else if (tkn.type == RPAR)
    {
        --pos;
        return make_pair(0, 0);
    }
    else
        return make_pair(0, 0);
}

pll solve(void)
{
    pos       = 0;
    pll moves = program();

    return make_pair(moves.first + 1, moves.second + 1);
}

int main(void)
{
    int t;
    cin >> t;

    for (int tc = 1; tc <= t; ++tc)
    {
        cin >> s;
        n        = s.size();
        auto pos = solve();
        cout << "Case #" << tc << ": " << pos.first << " " << pos.second
             << endl;
    }
}
