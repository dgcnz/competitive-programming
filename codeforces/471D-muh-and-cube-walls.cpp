#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <bits/stdc++.h>
#include <cplib/utils/io>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using namespace cplib;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

vector<int> prefix_function(vector<int> s)
{
    int         n = (int)s.size();
    vector<int> pi(n);

    auto eq = [&](int i, int j)
    { return i == 0 or j == 0 or (s[i] - s[i - 1] == s[j] - s[j - 1]); };

    for (int i = 1; i < n; i++)
    {
        int j = pi[i - 1];
        while (j > 0 and not eq(i, j))
            j = pi[j - 1];
        if (eq(i, j))
            j++;
        pi[i] = j;
    }
    return pi;
}

int solve(vi a, vi b)
{
    int INF = 1e9 + 100;

    int n = a.size(), w = b.size();
    if (n < w)
        return 0;
    if (w == 1)
        return n;

    vi c = b;
    c.push_back(-INF);
    c.insert(c.end(), all(a));

    auto pi  = prefix_function(c);
    int  ans = count(all(pi), w);
    return ans;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n, w;
    cin >> n >> w;

    vi a(n), b(w);
    read(all(a));
    read(all(b));
    cout << solve(a, b) << endl;
    return 0;
}
