class Solution
{
public:
    string convert(string s, int numRows)
    {
        if (numRows == 1)
        {
            return s;
        }

        int n = s.size();
        string result;
        int meow = 2 * (numRows - 1);

        for (int i = 0; i < numRows; i++)
        {
            int index = i;
            while (index < n)
            {
                result += s[index];
                if (i != 0 && i != numRows - 1)
                {
                    int a = meow - 2 * i;
                    int sec = index + a;
                    if (sec < n)
                    {
                        result += s[sec];
                    }
                }
                index += meow;
            }
        }
        return result;
    }
};