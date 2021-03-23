#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <bits/stdc++.h>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

bool solve(vector<tuple<int, string, string>> names)
{
    auto cmp = [](auto x, auto y) { return get<0>(x) < get<0>(y); };
    sort(all(names), cmp);
    string prev = "";
    for (auto [ix, first, last] : names)
    {
        if (first > last)
            swap(first, last);

        if (first >= prev)
            prev = first;
        else if (last >= prev)
            prev = last;
        else
            return false;
    }
    return true;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n;
    cin >> n;
    vector<tuple<int, string, string>> names(n);
    for (auto &[ix, first, last] : names)
        cin >> first >> last;

    for (int i = 0; i < n; ++i)
    {
        int pi;
        cin >> pi, pi--;
        get<0>(names[pi]) = i;
    }
    cout << (solve(names) ? "YES" : "NO") << endl;
    return 0;
}
