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

int solve(vector<string> grid)
{
    int         n = grid.size();
    vector<int> current_configuration;

    // Usually, lambda's types are inferred using auto, however if you prefer,
    // you make its signature/type explicit.
    // Example:
    // function<bool(int, int)> is_valid =[&](int row, int col)

    // This [&] means: "Capture" all variables as references. It would be the
    // same as a function:
    //
    // bool is_valid(int row, int col, int &n, vector<int>
    //                  &current_configuration, vector<string> &grid)
    //
    // This is useful, since it reduces the code written.
    // However, it's better practice to specifically capture only the variables
    // needed, like so:
    //
    // auto is_valid = [&grid, &current_configuration, n](int row, int col)
    //
    // In this instance, it's not that important.

    auto is_valid = [&](int row, int col)
    {
        for (int i = 0; i < (int)current_configuration.size(); ++i)
        {
            int j = current_configuration[i];
            if (col == j) // column check
                return false;
            if (abs(row - i) == abs(col - j)) // diagonal check
                return false;
        }
        return true;
    };

    // recursive lambdas must have an explicit signature
    function<int(int)> backtrack = [&](int row)
    {
        if (row == n)
            return 1;
        int cnt_valid = 0;
        for (int col = 0; col < n; ++col)
        {
            if (grid[row][col] == '.' and is_valid(row, col))
            {
                current_configuration.push_back(col);
                cnt_valid += backtrack(row + 1);
                current_configuration.pop_back();
            }
        }
        return cnt_valid;
    };
    return backtrack(0);
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);

    int const      N = 8;
    vector<string> grid(N);
    read(all(grid));

    cout << solve(grid) << endl;

    return 0;
}
