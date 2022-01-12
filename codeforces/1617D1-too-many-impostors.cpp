#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <bits/stdc++.h>
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

bool query(int a, int b, int c)
{
    cout << "? " << a + 1 << " " << b + 1 << " " << c + 1 << endl;
    cout.flush();
    bool ans;
    cin >> ans;
    return ans;
}

vi solve(int n)
{
    vector<bool> iscrew(n);
    bool         last = query(0, 1, 2);
    int          a, b;
    for (int i = 1; i < n - 2; ++i)
    {
        bool cur = query(i, i + 1, i + 2);
        if (cur != last)
        {
            a = i - 1, b = i + 2;
            iscrew[a] = last;
            iscrew[b] = cur;
            break;
        }
        last = cur;
    }

    for (int c = 0; c < n; ++c)
    {
        if (c != a and c != b)
        {
            iscrew[c] = query(a, b, c);
        }
    }

    vector<int> ans;
    for (int i = 0; i < n; ++i)
        if (not iscrew[i])
            ans.push_back(i);
    return ans;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        auto ans = solve(n);
        increment(all(ans));
        cout << "! " << ans.size() << " ";
        write(all(ans), " "), cout << endl;
    }

    return 0;
}
