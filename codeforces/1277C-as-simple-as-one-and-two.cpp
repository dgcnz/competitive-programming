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

vi solve(string s)
{
    int n = s.size();
    vi  ans;

    vector<string> patterns = {"twone", "one", "two"};
    vector<bool>   del(n, false);

    for (auto pat : patterns)
    {
        int        m = pat.size();
        deque<int> window;
        for (int i = 0; i < n; ++i)
        {
            if (!del[i])
                window.push_back(i);

            if ((int)window.size() == m)
            {
                bool flag = true;
                for (int j = 0; j < m; ++j)
                    if (s[window[j]] != pat[j])
                        flag = false;

                if (flag)
                {
                    del[window[m / 2]] = true;
                    ans.push_back(window[m / 2] + 1);
                }
                window.pop_front();
            }
        }
    }

    return ans;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        auto ans = solve(s);
        cout << ans.size() << endl;
        write(all(ans), " "), cout << endl;
    }
    return 0;
}
