#include <algorithm>
#include <bitset>
#include <iostream>

const int NMAX = 20;

using namespace std;
using answer = bitset<NMAX>;

int tsum, n, a[NMAX];

int    csum;
answer best;

void backtrack(int pos, answer current, int psum)
{
    if (psum > tsum)
        return;
    if (csum < psum)
    {
        csum = psum;
        best = current;
    }
    if (pos < n)
    {
        backtrack(pos + 1, current, psum);
        backtrack(pos + 1, current.set(pos, true), psum + a[pos]);
    }
}

int main(void)
{
    while (cin >> tsum >> n)
    {
        csum = int();
        best = answer();

        for (int i = 0; i < n; ++i)
            cin >> a[i];

        backtrack(0, answer(), 0);

        for (int i = 0; i < n; ++i)
            if (best[i])
                cout << a[i] << " ";

        cout << "sum:" << csum << endl;
    }

    return 0;
}
