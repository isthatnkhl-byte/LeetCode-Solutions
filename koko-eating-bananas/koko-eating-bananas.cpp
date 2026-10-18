#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int kokoEatingBananas(vector<int>& piles, int h) {
        // If there are more piles than hours, it is impossible to finish
        if (h < piles.size()) return -1;
        
        // The search space ranges from 1 to the largest pile size
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        int ans = high;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            long long total_time = 0;
            
            // Calculate the total hours needed at speed 'mid'
            for (int bananas : piles) {
                // Integer ceiling division: ceil(bananas / mid)
                total_time += (bananas + mid - 1LL) / mid;
            }
            
            // If Koko can finish within h hours, try to find a smaller speed
            if (total_time <= h) {
                ans = mid;
                high = mid - 1;
            } else {
                // If it takes too long, Koko needs to eat faster
                low = mid + 1;
            }
        }
        
        return ans;
    }
};
