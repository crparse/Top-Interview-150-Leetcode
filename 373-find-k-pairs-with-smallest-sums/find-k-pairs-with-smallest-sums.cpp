#include <vector>
#include <queue>
#include <utility> // for pair
using namespace std;

typedef long long ll ;
const ll INF=1e18;
const ll mod1=1e9+7;
const ll mod2=998244353;

class Solution{
public:
    vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k){
        vector<vector<int>> ans;
        if (nums1.empty() || nums2.empty() || k <= 0)
            return ans;

        auto comp = [&nums1, &nums2](pair<int, pair<int, int>> &a, pair<int, pair<int, int>> &b) {
            return nums1[a.second.first] + nums2[a.second.second] > nums1[b.second.first] + nums2[b.second.second];
        };

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, decltype(comp)> pq(comp);

        for (int i = 0; i < nums1.size() && i < k; i++){
            pq.push({nums1[i] + nums2[0], {i, 0}});
        }

        while (k-- > 0 && !pq.empty()){
            auto top = pq.top();
            pq.pop();
            int i = top.second.first;
            int j = top.second.second;
            ans.push_back({nums1[i], nums2[j]});
            if (j + 1 < nums2.size())
                pq.push({nums1[i] + nums2[j + 1], {i, j + 1}});
        }
        return ans;
    }
};
