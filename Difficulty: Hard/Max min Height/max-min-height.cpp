class Solution {
  public:
    int maxMinHeight(vector<int> &arr, int k, int w) {
        // code here
        int l = *min_element(arr.begin(), arr.end());
int h = *max_element(arr.begin(), arr.end()) + k;

int ans = l;
int n = arr.size();

auto fun = [&](int m) {
    int k2 = k;
    vector<long long> diff(n + w + 5, 0);

    long long add = 0;

    for (int i = 0; i < n; i++) {
        add += diff[i];   // prefix sum of diff

        long long cur = arr[i] + add;

        if (cur < m) {
            long long d = m - cur;

            if (k2 < d) return false;

            k2 -= d;
            add += d;          // apply now
            diff[i + w] -= d; // remove after window
        }
    }
    return true;
};

while (l <= h) {
    int mid = (l + h) >> 1;

    if (fun(mid)) {
        ans = mid;
        l = mid + 1;
    } else {
        h = mid - 1;
    }
}

return ans;
          
    }
};