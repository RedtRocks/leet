class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        unordered_map<int, int> meow;
        unordered_set<int> s;
        vector<int> result;

        for (int i : nums)
        {
            meow[i]++;
            if (meow[i] > nums.size() / 3 && !s.contains(i))
            {
                result.push_back(i);
                s.insert(i);
            }
        }

        return result;
    }
};