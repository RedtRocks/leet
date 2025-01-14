class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        unordered_map<int, int> meow;
        int result;
        for (int i : nums)
        {
            meow[i]++;
            if (meow[i] > nums.size() / 2)
            {
                result = i;
            }
        }

        return result;
    }
};