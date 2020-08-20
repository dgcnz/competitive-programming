#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;

int const NMAX = 100 + 11;

int    n, vis_status[NMAX];
string s[NMAX];
vi     g[NMAX], order;

bool toposort(int u)
{
    if (vis_status[u] == 1)
        return false;
    if (vis_status[u] == 2)
        return true;

    vis_status[u] = 1;
    for (int v : g[u])
        if (not toposort(v))
            return false;
    vis_status[u] = 2;
    order.push_back(u);
    return true;
}

bool compare(int i, int j)
{
    int ix = 0, ni = s[i].size(), nj = s[j].size();
    while (ix < ni and ix < nj and s[i][ix] == s[j][ix])
        ++ix;
    if (ix != ni and ix == nj)
        return false;
    else if (ix != ni and ix != nj)
        g[s[i][ix] - 'a'].push_back(s[j][ix] - 'a');
    return true;
}

bool sorteable(void)
{
    for (int i = 0; i < n - 1; ++i)
        for (int j = i + 1; j < n; ++j)
            if (not compare(i, j))
                return false;

    for (int u = 0; u < 26; ++u)
        if (not vis_status[u] and not toposort(u))
            return false;
    return true;
}

int main(void)
{
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> s[i];

    if (sorteable())
        for_each(order.rbegin(),
                 order.rend(),
                 [](int cix) { cout << (char)(cix + 'a'); }),
            cout << endl;
    else
        cout << "Impossible" << endl;

    return 0;
}
