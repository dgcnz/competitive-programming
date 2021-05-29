#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <bits/stdc++.h>
#include <cplib/graphs/graph>
#include <cplib/graphs/toposort>
#include <cplib/utils/io>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using namespace cplib;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

pair<ll, vi> solve(vector<ll> a, vi b)
{
    int         n = a.size();
    Graph<void> g(n);
    for (int i = 0; i < n; ++i)
        if (b[i] != -2)
            g.add_edge(i, b[i]);

    vi        neworder, order = toposort(g);
    stack<ll> neg;
    ll        ans = 0;
    for (int i = 0; i < n; ++i)
    {
        int j = order[i];
        if (a[j] < 0)
            neg.push(j);
        else
        {
            if (b[j] != -2)
                a[b[j]] += a[j];
            ans += a[j];
            neworder.push_back(j);
        }
    }
    while (neg.size())
    {
        ans += a[neg.top()];
        neworder.push_back(neg.top());
        neg.pop();
    }
    return {ans, neworder};
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n;
    cin >> n;
    vector<ll>  a(n);
    vector<int> b(n);
    read(all(a));
    read(all(b));
    decrement(all(b));

    auto [ans, order] = solve(a, b);
    cout << ans << endl;
    increment(all(order));
    write(all(order), " "), cout << endl;

    return 0;
}
