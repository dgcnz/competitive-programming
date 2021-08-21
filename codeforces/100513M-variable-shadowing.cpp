#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

struct token
{
    char val;
    ii   pos;
    token() {}
    token(char val, ii pos) : val(val), pos(pos) {}

    friend ostream &operator<<(ostream &os, const token &tkn)
    {
        return (os << tkn.val << " " << tkn.pos.first << " " << tkn.pos.second);
    }
};

int                     depth = 0;
vector<token>           tokens;
map<ii, token>          warnings;
stack<pair<token, int>> vars[26];

int E(int i)
{
    if (i >= (int)tokens.size() or tokens[i].val == '}')
        return i;
    if (tokens[i].val == '{')
    {
        depth++;
        i = E(i + 1);
        for (int k = 0; k < 26; ++k)
            if (vars[k].size() and vars[k].top().second == depth)
                vars[k].pop();
        depth--;
        ++i;
    }
    else
    {
        while (i < (int)tokens.size() and isalpha(tokens[i].val))
        {
            int ch = tokens[i].val - 'a';
            if (vars[ch].size())
                warnings[tokens[i].pos] = vars[ch].top().first;
            vars[ch].push({tokens[i], depth});
            ++i;
        }
    }
    return E(i);
}

int main(void)
{
    int n;
    cin >> n;
    char s[111];
    cin.get();
    for (int i = 0; i < n; ++i)
    {
        cin.getline(s, 111);
        int m = strlen(s);
        for (int j = 0; j < m; ++j)
            if (isdigit(s[j]) or isalpha(s[j]) or s[j] == '{' or s[j] == '}')
                tokens.emplace_back(token(s[j], ii{i, j}));
    }

    if (tokens.empty())
        return 0;

    E(0);
    for (auto it = warnings.begin(); it != warnings.end(); ++it)
    {
        auto p1  = it->first;
        auto tkn = it->second;
        cout << p1.first + 1 << ":" << p1.second + 1
             << ": warning: shadowed declaration of " << tkn.val
             << ", the shadowed position is " << tkn.pos.first + 1 << ":"
             << tkn.pos.second + 1 << endl;
    }

    return 0;
}
