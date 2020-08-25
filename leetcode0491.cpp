#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<int> temp; 
    vector<vector<int>> ans;

    void dfs(int cur, int last, vector<int>& nums) {
        if (cur == nums.size()) {
            if (temp.size() >= 2) {
                ans.push_back(temp);
            }
            return;
        }
        if (nums[cur] >= last) {
            temp.push_back(nums[cur]);
            dfs(cur + 1, nums[cur], nums);
            temp.pop_back();
        }
        if (nums[cur] != last) {
            dfs(cur + 1, last, nums);
        }
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        dfs(0, -1000, nums);
        return ans;
    }
};


int main(){
   
    vector<int> nums = {4,6,7,7};
    Solution t;
    t.findSubsequences(nums);
    system("pause");
    return 0;

}