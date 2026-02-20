class Solution {

public:

    int overlapInt(vector<vector<int>>& arr) {

        vector<pair<int, int>> events;

        

        for(auto& interval : arr) {

            events.push_back({interval[0], 1});

            events.push_back({interval[1] + 1, -1});

        }

        

        sort(events.begin(), events.end());

        

        int max_overlap = 0;

        int current = 0;

        

        for(auto& event : events) {

            current += event.second;

            max_overlap = max(max_overlap, current);

        }

        

        return max_overlap;

    }

};
