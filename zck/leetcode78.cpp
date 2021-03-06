/*
给定一组不含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。

说明：解集不能包含重复的子集。

示例:

输入: nums = [1,2,3]
输出:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void backtrack(vector<int> nums, int start, vector<int> &track, int k, vector<vector<int>> &res){
    if(track.size() == k){
        res.push_back(track);
        return;
    }
    for(int i = start; i < nums.size(); i++){
        track.push_back(nums[i]);
        backtrack(nums, i + 1, track, k, res);
        track.pop_back();
    }
}

vector<vector<int>> subsets(vector<int>& nums){
    vector<vector<int>> res;
    vector<int> track;
    for(int k = 0; k <= nums.size(); k++)
        backtrack(nums, 0, track, k, res);

    return res;
}

int main(){
    vector<int> nums = {1,2,3};
    vector<vector<int>> res = subsets(nums);
    for(auto nums : res){
        for(auto num : nums){
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}