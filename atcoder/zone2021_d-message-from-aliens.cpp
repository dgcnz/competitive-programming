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
    string s;
    cin >> s;

    deque<char> t;
    bool        back = true;
    for (auto c : s)
    {
        if (c == 'R')
            back = !back;
        else
        {
            if (back)
            {
                if (t.size() and t.back() == c)
                    t.pop_back();
                else
                    t.push_back(c);
            }
            else
            {
                if (t.size() and t.front() == c)
                    t.pop_front();
                else
                    t.push_front(c);
            }
        }
    }

    if (!back)
        reverse(all(t));
    for (auto c : t)
        cout << c;
    cout << endl;
    return 0;
}
