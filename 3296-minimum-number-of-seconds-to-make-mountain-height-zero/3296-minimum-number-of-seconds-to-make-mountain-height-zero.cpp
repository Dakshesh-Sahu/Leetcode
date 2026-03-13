class Solution {
public:
    long long maxHeight(long long t, long long w) {
        long long l = 0, r = 1e6;
        while (l < r) {
            long long m = (l + r + 1) / 2;
            long long cost = w * m * (m + 1) / 2;
            if (cost <= t) l = m;
            else r = m - 1;
        }
        return l;
    }

    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        long long l = 0, r = 1e18;
        while (l < r) {
            long long mid = (l + r) / 2;
            long long h = 0;
            for (int w : workerTimes) {
                h += maxHeight(mid, w);
                if (h >= mountainHeight) break;
            }
            if (h >= mountainHeight) r = mid;
            else l = mid + 1;
        }
        return l;
    }
};
