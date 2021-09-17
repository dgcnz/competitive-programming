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

string solve(vi a)
{

    map<int, int> cnt;
    for (auto x : a)
        cnt[x]++;

    int legs = -1;
    for (auto [k, v] : cnt)
    {
        if (v >= 4)
        {
            legs = k;
            break;
        }
    }

    if (cnt.size() > 3 or legs == -1)
        return "Alien";

    cnt[legs] -= 4;
    if (cnt[legs] == 0)
        cnt.erase(legs);

    return cnt.size() == 1 ? "Elephant" : "Bear";
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);

    vi sticks(6);
    read(all(sticks));
    cout << solve(sticks) << endl;

    return 0;
}
