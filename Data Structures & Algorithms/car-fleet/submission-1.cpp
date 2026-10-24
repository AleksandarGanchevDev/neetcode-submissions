#include <iostream>

using namespace std;

class Solution
{
public:
    int carFleet(int target, vector<int> &position, vector<int> &speed)
    {
        vector<pair<int, int>> cars;
        int fleetCnt = 0;
        double top = -1;
        for (int i = 0; i < position.size(); i++)
            cars.push_back({position[i], speed[i]});

        sort(cars.begin(), cars.end(), [](auto &a, auto &b)
             { return a.first > b.first; });

        for (int i = 0; i < cars.size(); i++)
        {
            double time = (double)(target - cars[i].first) / cars[i].second;
            if (top < time)
            {
                fleetCnt++;
                top = time;
            }
        }

        return fleetCnt;
    }
};
