
// Link : https://leetcode.com/problems/minimum-deletions-to-make-character-frequencies-unique/description/?envType=daily-question&envId=2023-09-12
class Solution
{
public:
    int minDeletions(string s)
    {
        unordered_map<char, int> mp;
        unordered_set<int> used_frequencies;

        for (int i = 0; i < s.size(); i++)
        {
            mp[s[i]]++;
        }

        int deletion = 0;
        for (auto it : mp)
        {
            int freq = it.second;
            while (used_frequencies.find(freq) != used_frequencies.end() && freq > 0)
            {
                freq--;
                deletion++;
            }

            used_frequencies.insert(freq);
        }

        return deletion;
    }
};