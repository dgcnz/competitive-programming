#include <bits/stdc++.h>

using namespace std;
using vs = vector<string>;

const int CMAX = 26;

struct node
{
    node *   children[CMAX];
    set<int> matches;
    set<int> terminated;

    node() { memset(children, 0, sizeof(children)); }
};

int   n;
vs    v;
node *trie;

void insert(int ix, const string &s)
{
    int   cix;
    node *x = trie;
    x->matches.insert(ix);

    for (auto const c : s)
    {
        cix = c - 'a';
        if (x->children[cix] == nullptr)
            x->children[cix] = new node();

        x = x->children[cix];
        x->matches.insert(ix);
    }
    x->terminated.insert(ix);
}

node *remove(int ix, const string &s, int s_ix, node *x)
{
    if (x == nullptr)
        return nullptr;

    x->matches.erase(ix);
    if (s_ix < (int)s.size())
    {
        int cix          = s[s_ix] - 'a';
        x->children[cix] = remove(ix, s, s_ix + 1, x->children[cix]);
    }

    if (s_ix == (int)s.size())
        x->terminated.erase(ix);

    if (x->matches.empty())
    {
        delete (x);
        x = nullptr;
    }
    return x;
}

void update(int ix, const string &s)
{
    string t = v[ix];
    // delete t
    trie = remove(ix, t, 0, trie);
    if (trie == nullptr)
        trie = new node();
    // insert s
    insert(ix, s);
    // update v
    v[ix] = s;
}

bool in_range(const set<int> &si, int l, int r)
{
    auto it = si.lower_bound(l);
    if (it != si.end() and *it <= r)
        return true;
    else
        return false;
}

bool q2(int l, int r, const string &s)
{
    int   cix;
    node *x = trie;

    for (auto const c : s)
    {
        cix = c - 'a';
        if (not x->terminated.empty() and in_range(x->terminated, l, r))
            return true;
        else if (x->children[cix] == nullptr)
            return false;
        x = x->children[cix];
    }
    if (not x->terminated.empty() and in_range(x->terminated, l, r))
        return true;
    return false;
}
bool q3(int l, int r, const string &s)
{
    int   cix;
    node *x = trie;

    for (auto const c : s)
    {
        cix = c - 'a';
        if (x->children[cix] == nullptr)
            return false;

        x = x->children[cix];
    }

    return in_range(x->matches, l, r);
}

int main(void)
{
    string s;
    int    q, type, i, l, r;
    cin >> n;
    v.resize(n);

    trie = new node();
    for (int i = 0; i < n; ++i)
    {
        cin >> v[i];
        insert(i, v[i]);
    }

    cin >> q;
    while (q--)
    {
        cin >> type;
        if (type == 1)
        {
            cin >> i >> s;
            update(i - 1, s);
        }
        else if (type == 2)
        {
            cin >> l >> r >> s;
            cout << (q2(l - 1, r - 1, s) ? "Y" : "N") << endl;
        }
        else if (type == 3)
        {
            cin >> l >> r >> s;
            cout << (q3(l - 1, r - 1, s) ? "Y" : "N") << endl;
        }
    }

    return 0;
}
