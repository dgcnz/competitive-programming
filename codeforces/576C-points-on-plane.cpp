#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <bits/stdc++.h>
#include <cplib/utils/io>
#include <cplib/utils/misc>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using namespace cplib;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

int const SQ = 1000;

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);

    int n;
    cin >> n;
    vector<ii> points(n);
    for (auto &[x, y] : points)
        cin >> x >> y, x /= SQ;

    auto cmp = [&](auto a, auto b)
    {
        if (a.first == b.first)
            return a.first % 2 == 0 ? a.second < b.second : a.second > b.second;
        return a.first < b.first;
    };
    auto sigma = argsort(all(points), cmp);

    increment(all(sigma));
    write(all(sigma), " "), cout << endl;

    return 0;
}
