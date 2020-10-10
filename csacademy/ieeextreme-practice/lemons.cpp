#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#endif
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n, m, s;
    cin >> n >> m >> s;
    cout << (n - 1) * m + s * (int)ceil(log2(n)) << endl;

    return 0;
}
