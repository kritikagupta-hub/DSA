class Solution {
private:
    // helper: returns true if person a knows person b
    bool knows(vector<vector<int>>& mat, int a, int b) {
        return mat[a][b] == 1;
    }

public:
    int celebrity(vector<vector<int>>& mat) {
        int n = mat.size();
        stack<int> s;

        // Step 1: push all people into stack
        for (int i = 0; i < n; ++i) s.push(i);

        // Step 2: eliminate non-celebrities
        while (s.size() > 1) {
            int a = s.top(); s.pop();
            int b = s.top(); s.pop();

            if (knows(mat, a, b)) {
                // a knows b -> a not celebrity
                s.push(b);
            } else {
                // a doesn't know b -> b not celebrity
                s.push(a);
            }
        }

        if (s.empty()) return -1;
        int candidate = s.top();

        // Step 3: Row check (all zeros except self)
        for (int j = 0; j < n; ++j) {
            if (j != candidate && mat[candidate][j] != 0) {
                return -1;
            }
        }

        // Step 4: Column check (all ones except self)
        for (int i = 0; i < n; ++i) {
            if (i != candidate && mat[i][candidate] != 1) {
                return -1;
            }
        }

        // Step 5: Passed both checks
        return candidate;
    }
};

