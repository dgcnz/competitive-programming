#include <climits>
#include <iomanip>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

// n liters of gasoline per km

enum event_type
{
    FUEL,
    LEAK,
    GAS,
    MECHANIC,
    GOAL
};

struct event
{
    event_type type;
    int        fc; // new fuel consumption
};

map<int, vector<event>> events_at;
int                     n;

bool simulate(double tank_vol)
{
    int           dist = 0, delta = 0, fc_rate = 0, leak_rate = 0;
    double        gas_left = tank_vol;
    vector<event> events;
    for (auto kv : events_at)
    {
        delta  = kv.first - dist;
        dist   = kv.first;
        events = kv.second;

        gas_left -= ((fc_rate * delta / 100.0) + leak_rate * delta);
        if (gas_left < 0)
            return false;

        for (auto e : events)
        {
            if (e.type == FUEL)
                fc_rate = e.fc;
            else if (e.type == LEAK)
                ++leak_rate;
            else if (e.type == GAS)
                gas_left = tank_vol;
            else if (e.type == MECHANIC)
                leak_rate = 0;
        }
    }
    return true;
}

// no no ... no yes yes .. yes ...
// Find first yes
//
// binary search on tank volume

double bsearch(double l, double r)
{
    while ((r - l) > 0.000000001)
    {
        double mid = (l + r) / 2.0;
        if (simulate(mid))
            r = mid;
        else
            l = mid;
    }

    return l;
}

event_type ecast(string raw_type)
{
    if (raw_type == "Fuel")
        return FUEL;
    if (raw_type == "Leak")
        return LEAK;
    if (raw_type == "Gas")
        return GAS;
    if (raw_type == "Mechanic")
        return MECHANIC;
    else
        return GOAL;
}

int main(void)
{
    int    d;
    string cmd, trash;

    while (true)
    {
        cin >> d >> cmd >> trash >> n;

        if (cmd == "Fuel" and n == 0)
            break;

        events_at[d].push_back({ecast(cmd), n});

        // set fuel
        while (true)
        {
            cin >> d >> cmd;
            if (cmd == "Fuel" or cmd == "Gas")
                cin >> trash;
            if (cmd == "Fuel")
                cin >> n;

            events_at[d].push_back({ecast(cmd), n});
            if (cmd == "Goal")
                break;
        }
        cout << setprecision(3) << fixed << bsearch(0, INT_MAX) << endl;
        events_at.clear();
        // solve
    }
    return 0;
}
