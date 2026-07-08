#include <iostream>
#include <vector>

using namespace std;

class Solution
{

public:
    vector<int> findAnagrams(string s, string p)
    {

        vector<int> result;

        int stringlen = s.size();
        int patternlen = p.size();

        // If the pattern length is greater than the string length, no anagram is possible.
        if (patternlen > stringlen)
        {
            return result;
        }

        // characters in the alphabet = 26. We are assuming all inputs are only smaller case letters.
        vector<int> freq1(26, 0);
        vector<int> freq2(26, 0);

        // Build first windows. These are two hashmaps.
        for (int i = 0; i < patternlen; i++)
        {
            freq1[s[i] - 'a']++;
            freq2[p[i] - 'a']++;
        }

        // check first window. Oooh, you can compare hashmaps 1 to 1? Ooh these are vectors.
        if (freq1 == freq2)
        {
            result.push_back(0); // push the 0th index
        }

        // slide the window
        for (int i = patternlen; i < stringlen; i++)
        {
            // add incoming character
            freq1[s[i] - 'a']++;
            // remove outgoing character. Resets it to 0.
            freq1[s[i - patternlen] - 'a']--;

            // compare frequencies
            if (freq1 == freq2)
            {
                result.push_back(i - patternlen + 1);
            }
        }

        return result;
    }
};

int main()
{
    // string s = "abab";
    // string p = "ab";

    string s = "cbaebabacd";
    string p = "abc";

    Solution sol;

    vector<int> ans1 = sol.findAnagrams(s, p);

    cout << "Test Case: ";

    for (int x : ans1)
        cout << x << " ";

    cout << endl;

    return 0;
}
