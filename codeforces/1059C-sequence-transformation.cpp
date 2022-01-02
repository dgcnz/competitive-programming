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

vector<int> solve(int n)
{
    if (n == 1)
        return {1};
    else if (n == 2)
        return {1, 2};
    else if (n == 3)
        return {1, 1, 3};

    vector<int> ans(n - n / 2, 1);
    vector<int> res = solve(n / 2);
    transform(all(res), begin(res), [](int x) { return 2 * x; });
    ans.insert(ans.end(), all(res));
    return ans;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n;
    cin >> n;
    auto ans = solve(n);
    write(all(ans), " "), cout << endl;
    return 0;
}
