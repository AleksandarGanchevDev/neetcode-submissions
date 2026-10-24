#include <iostream>

using namespace std;

class Solution
{
public:
    bool isSol(int rate, vector<int> &piles, int h)
    {
        long long time = 0;
        for (int i = 0; i < piles.size(); i++)
            piles[i] % rate == 0 ? time += piles[i] / rate : time += (piles[i] / rate) + 1;

        return time <= h ? true : false;
    }

    int minEatingSpeed(vector<int> &piles, int h)
    {
        int maxN = 0;
        for (int n : piles)
            maxN = max(maxN, n);

        int l = 1, r = maxN;
        int bestRate = maxN;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (isSol(mid, piles, h))
            {
                bestRate = mid;
                r = mid - 1;
            }
            else
                l = mid + 1;
        }

        return bestRate;
    }
};
