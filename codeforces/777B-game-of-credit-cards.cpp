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

ii solve(string a, string b)
{
    multiset<int> ma1, ma2;
    for (auto c : a)
        ma1.insert(c - '0'), ma2.insert(c - '0');

    int minf = 0, maxf = 0;
    for (auto c : b)
    {
        auto itmin = ma1.upper_bound(c - '0');
        if (itmin != ma1.begin())
            ma1.erase(prev(itmin));
        else
            ma1.erase(prev(ma1.end())), minf++;

        auto itmax = ma2.lower_bound(c - '0');
        if (itmax != ma2.begin())
            ma2.erase(prev(itmax)), maxf++;
        else
            ma2.erase(prev(ma2.end()));
    }
    return {minf, maxf};
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    auto [minf, maxf] = solve(a, b);
    cout << minf << endl << maxf << endl;
    return 0;
}
