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

void hanoi(int n, int START, int MID, int TARGET)
{
    if (n == 0)
        return;
    // MOVE n - 1 disks from START to MID
    hanoi(n - 1, START, TARGET, MID);
    // MOVE largest disk from START to TARGET
    cout << START << " " << TARGET << endl;
    // MOVE n - 1disks from MID to TARGET
    hanoi(n - 1, MID, START, TARGET);
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n;
    cin >> n;

    cout << (int)pow(2, n) - 1 << endl;
    hanoi(n, 1, 2, 3);
    return 0;
}
