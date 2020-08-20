#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;
using ii = pair<int, int>;

int const NMAX = 2e5 + 11;
int const INF  = 1e9 + 100;

vector<int> a, b;
vector<multiset<ii, greater<ii>>>
    bs(NMAX); // structure storing an ordered sequence of
              // people by their rating for all houses

multiset<pair<int, int>> ds;

void update(int i, int new_b)
{
    int  cur_b = b[i];
    auto it    = bs[cur_b].find({a[i], i});

    if (it == bs[cur_b].begin()) // i is the representative of cur_b
    {
        ds.erase({it->first, cur_b}); // erase from set of representatives
        if (bs[cur_b].size() == 1)    // if cur_b becomes empty
            ds.insert({INF, cur_b});  // insert dummy
        else // > 1,  second representative of cur_b becomes new representative
            ds.insert({next(bs[cur_b].begin())->first, cur_b});
    }
    bs[cur_b].erase(it); // remove i from cur_b

    if (bs[new_b].empty() or
        a[i] > bs[new_b].begin()->first) // i is the new representative of new_b
    {
        ds.erase({bs[new_b].empty() ? INF : bs[new_b].begin()->first,
                  new_b});        // erase old representative
        ds.insert({a[i], new_b}); // insert i
    }
    bs[new_b].insert({a[i], i}); // insert i in new_b
    b[i] = new_b;                // update couse
}

int query(void) { return ds.begin()->first; }

int main(void)
{
    int n, q, i, d;

    cin >> n >> q;
    a.resize(n), b.resize(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> a[i] >> b[i], b[i]--;
        bs[b[i]].insert({a[i], i});
    }
    for (int i = 0; i < NMAX; ++i)
    {
        if (not bs[i].empty())
            ds.insert({bs[i].begin()->first, i});
        else
            ds.insert({INF, i});
    }

    while (q--)
    {
        cin >> i >> d, i--, d--;
        update(i, d);
        cout << query() << endl;
    }

    return 0;
}
