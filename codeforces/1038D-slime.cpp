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

ll solve(vector<ll> a)
{
    int n = a.size();
    if (n == 1)
        return a[0];
    vector<ll> pos, neg;
    for (auto ai : a)
    {
        if (ai >= 0)
            pos.push_back(ai);
        else
            neg.push_back(ai);
    }

    auto answer = [](vector<ll> pos)
    {
        sort(all(pos), greater<ll>());
        if (pos.size() == 1)
            return pos.back();
        if (pos.size() == 2)
            return pos.front() - pos.back();

        ll x = pos.back();
        pos.pop_back();
        x -= pos.back();
        pos.pop_back();
        return accumulate(all(pos), 0LL) - x;
    };

    if (pos.size() and neg.size())
        return accumulate(all(pos), 0LL) - accumulate(all(neg), 0LL);
    else if (pos.size()) // all pos
        return answer(pos);
    else // all neg
    {
        transform(all(neg), begin(neg), [](auto x) { return -x; });
        return answer(neg);
    }
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n;
    cin >> n;
    vector<ll> a(n);
    read(all(a));

    cout << solve(a) << endl;
    return 0;
}
