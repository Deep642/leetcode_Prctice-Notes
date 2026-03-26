#include <bits/stdc++.h>
using namespace std;
int main() {
    vector<int> p = {3, 6, 7, 11};
    int h = 8;
    Solution s;
    
    cout << s.minEatingSpeed(p, h) << endl;
    return 0;
}
class Solution {
public:
    int minEatingSpeed(vector<int>& p, int h) {
        // finding the highest value of the Array 'p';
        int maxx = INT_MIN;
        for (int i = 0; i < p.size(); i++) {
            maxx = max(p[i], maxx);
        }
        // the k (bananas/hour) should be between[1,maxx]; FInding that value
        // using BS;
        int s = 1, e = maxx, ans = 0;
        while (s <= e) {
            long long int m = s + (e - s) / 2;
            long long int count = 0;
            for (int i = 0; i < p.size(); i++) {
                // if element of array is cleanly divisable then no need to add
                // +1;
                if (p[i] % m)
                    count += (1 + p[i] / m);
                else
                    count += p[i] / m;
            }
            // if the count is high , then we should move to the right side of
            // mid.
            if (count > h) {
                s = m + 1;
                ans = m + 1;
            }
            // if the count is low /equal(because even if it is equal to h, then also
            // we should find that if any smaller value of 'k' can also give the
            // value of h or not) , then we should move to the left side of
            // mid.
            else {
                e = m - 1;
                ans = m;
            }
            count = 0;
        }
        return ans;
    }
};