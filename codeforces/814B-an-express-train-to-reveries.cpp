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

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n;
    cin >> n;
    vi a(n), b(n);

    read(all(a)), read(all(b));
    decrement(all(a)), decrement(all(b));
    auto ans = [](vi a, vi b)
    {
        int n = a.size();
        vi  ix, vis(n, 0);

        for (int i = 0; i < n; ++i)
        {
            if (a[i] == b[i] and not vis[a[i]])
                vis[a[i]] = true;
            else
                ix.push_back(i);
        }
        if (ix.size() == 1)
        {
            for (int i = 0; i < n; ++i)
                if (not vis[i])
                    a[ix.back()] = i;
        }
        else if (ix.size() == 2)
        {
            if (not vis[a[ix.front()]] and not vis[b[ix.back()]])
            {
                a[ix.back()] = b[ix.back()];
            }
            else
                a[ix.front()] = b[ix.front()];
        }
        else
            throw runtime_error("quack");
        return a;
    }(a, b);
    increment(all(ans));
    write(all(ans), " "), cout << endl;

    return 0;
}
