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
    priority_queue<int, vi> q(all(a));

    vi cur(2, -1);
    while (true)
    {
        for (int i = 0; i < 2; ++i)
        {
            if (not q.empty() and q.top() > cur[i])
            {
                if (cur[i] != -1)
                    q.push(cur[i]);
                cur[i] = q.top() - 1;
                q.pop();
            }
            else if (cur[i] > 0)
                cur[i]--;
            else
                return i % 2 ? "T" : "HL";
        }
    }
    return "HL";
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
        vi a(n);
        read(all(a));
        cout << solve(a) << endl;
    }
    return 0;
}
