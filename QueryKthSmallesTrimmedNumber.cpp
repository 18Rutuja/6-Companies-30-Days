#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

#define pr pair<string, int>

class comp {
public:
    bool operator()(const pr& a, const pr& b) const {
        if (a.first.size() == b.first.size()) {
            if (a.first == b.first) {
                return a.second < b.second;
            }
            return a.first < b.first;
        }
        return a.first.size() < b.first.size();
    }
};

class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        vector<int> ans;
        for (auto query : queries) {
            int k = query[0];
            int final_len = query[1];
            priority_queue<pr, vector<pr>, comp> pq;
            for (int i = 0; i < nums.size(); i++) {
                string num = nums[i];
                if (num.size() >= final_len) {
                    string trimmed_num = num.substr(num.size() - final_len);
                    pq.push({ trimmed_num, i });
                }
            }
            while (pq.size() > k) {
                pq.pop();
            }
            string kSmallestNum = pq.top().first;
            int idx = pq.top().second;
            while (pq.size() > 0 && pq.top().first == kSmallestNum && pq.top().second < idx) {
                idx = pq.top().second;
                pq.pop();
            }
            ans.push_back(idx);
        }
        return ans;
    }
};

int main() {
    Solution solution;
    vector<string> nums = {"12345", "123456", "123", "12", "1234"};
    vector<vector<int>> queries = {{2, 3}, {1, 4}, {3, 2}};

    vector<int> result = solution.smallestTrimmedNumbers(nums, queries);

    cout << "Resultant indexes of smallest trimmed numbers: ";
    for (int idx : result) {
        cout << idx << " ";
    }
    cout << endl;

    return 0;
}
