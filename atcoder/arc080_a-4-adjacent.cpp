#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <bits/stdc++.h>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n;
    cin >> n;

    int m4  = 0;
    int odd = 0;
    for (int i = 0; i < n; ++i)
    {
        int ai;
        cin >> ai;
        if (ai % 2 == 1)
            ++odd;
        else if (ai % 4 == 0)
            ++m4;
    }

    if (m4 >= odd or (m4 == odd - 1 and odd + m4 == n))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}
