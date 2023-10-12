#include<vector>
#include<unordered_map>

using std::vector;
using std::unordered_map;

vector<int> twoSum_bruteForse(vector<int>& nums, int target) {
        for(int i = 0; i < nums.size(); ++i){
            int first_num = nums[i];
            for(int j = i + 1; j < nums.size(); ++j){
                int second_num = nums[j];
                if(first_num + second_num == target){
                    return vector<int>{i, j};
                }
            }
        }
        return vector<int>{};
    }

vector<int> twoSum_map(vector<int>& nums, int target){
    unordered_map<int, int> numIndexMap;
    for (int i = 0; i < nums.size(); ++i)
    {
        int complement = target - nums[i];
        if (numIndexMap.find(complement) != numIndexMap.end())
        {
            return {i, numIndexMap[complement]};
        }
        numIndexMap[complement] = i;    
    }
    return {};
}
