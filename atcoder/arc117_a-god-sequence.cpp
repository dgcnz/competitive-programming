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

vi solve(int a, int b)
{
    vi         ans;
    vector<ii> order = {{a, +1}, {b, -1}};
    if (a < b)
        swap(order[0], order[1]);

    int sum = 0;
    for (int i = 1; i <= order[0].first; ++i)
        ans.push_back(i * order[0].second), sum += i * order[0].second;
    for (int i = 1; i < order[1].first; ++i)
        ans.push_back(i * order[1].second), sum += i * order[1].second;
    ans.push_back(-sum);
    return ans;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int a, b;
    cin >> a >> b;
    auto ans = solve(a, b);
    write(all(ans), " "), cout << endl;
    return 0;
}
