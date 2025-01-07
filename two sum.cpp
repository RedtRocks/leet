// two sum
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> ret;
        int size = nums.size();
        int diff;
        unordered_map<int, int> m;
        for (int i = 0; i < size; i++)
        {
            diff = target - nums[i];
            if (m.contains(diff) && m[diff] != i)
            {
                ret.push_back(i);
                ret.push_back(m[diff]);
                return ret;
            }
            m[nums[i]] = i;
        }
        return ret;
    }
};