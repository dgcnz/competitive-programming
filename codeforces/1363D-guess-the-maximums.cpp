#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <bits/stdc++.h>
#include <cplib/math/misc>
#include <cplib/utils/io>
#include <cplib/utils/misc>
#define all(c) begin(c), end(c)
#define rall(c) rbegin(c), rend(c)
#define isz(c) (int)(c).size()

using namespace std;
using namespace cplib;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

bool answer(vector<int> password)
{
    cout << "! ";
    increment(all(password));
    write(all(password), " "), cout << endl;
    cout.flush();
    string verdict;
    cin >> verdict;
    return verdict == "Correct";
}

int query(vector<int> const &q)
{
    assert(q.size() > 0);
    cout << "? " << q.size() << " ";
    for (auto i : q)
        cout << i + 1 << " ";
    cout << endl;
    cout.flush();
    int mx;
    cin >> mx;
    return mx - 1;
}

vector<int> solve(int n, vector<vector<int>> const &s)
{
    auto get_range = [&](int l, int r)
    {
        vector<int> x;
        for (int i = l; i < r; ++i)
            copy(all(s[i]), back_inserter(x));
        return x;
    };

    auto get_complement = [&](int ix)
    {
        vector<int> x, vis(n, false);
        for (auto i : s[ix])
            vis[i] = true;
        for (int i = 0; i < n; ++i)
            if (not vis[i])
                x.push_back(i);
        return x;
    };

    int         k = s.size();
    vector<int> x;
    for (int i = 0; i < n; ++i)
        x.push_back(i);
    auto        mx = query(x);
    vector<int> password(k, mx);

    function<int(int, int)> find_max = [&](int l, int r)
    {
        assert(r - l > 0);
        if (r - l == 1)
            return l;
        else
        {
            int m = (r + l) / 2;
            if (query(get_range(l, m)) == mx)
                return find_max(l, m);
            else
                return find_max(m, r);
        }
    };
    int ix       = find_max(0, k);
    password[ix] = query(get_complement(ix));
    return password;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;

        vector<vi> s(k);
        for (int i = 0; i < k; ++i)
        {
            int c;
            cin >> c;
            s[i].resize(c);
            read(all(s[i]));
            decrement(all(s[i]));
        }

        auto password = solve(n, s);
        answer(password);
    }
    return 0;
}
