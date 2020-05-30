#include <algorithm>
#include <functional>

using namespace std;
using predicate = function<bool(int)>;

// last true in [true, true,... true, false, ... false]
int binary_search(int lo, int hi, predicate p)
{
    while (lo < hi)
    {
        int mid = lo + (hi - lo + 1) / 2;
        if (p(mid) == false)
            hi = mid - 1;
        else
            lo = mid;
    }
    if (p(lo) == false)
        return -1; // p(x) is false for all x
    return lo;
}
