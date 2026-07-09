#include <iostream>
#include <vector>

using namespace std;

class Solution
{

public:
    vector<int> findAnagrams(string s, string p) // s= cbaebabacd, p=abc
    {

        vector<int> result; // result = {}

        int stringlen = s.length();  // stringlen = 10
        int patternlen = p.length(); // patternlen=3

        /* If the pattern length is greater than the string length, no anagram is possible. */
        if (patternlen > stringlen) // if 3 > 10?
        {
            return result;
        }

        /*  characters in the alphabet = 26. We are assuming all inputs are only smaller case letters.*/
        vector<int> freq1(26, 0);
        // freq1={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
        vector<int> freq2(26, 0);
        // freq2={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}

        /*  Build hashmaps.*/
        for (int i = 0; i < patternlen; i++)
        {
            freq1[s[i] - 'a']++;
            // freq1={0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0} ; freq1={0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}; \
            // freq1={1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0} ;
            freq2[p[i] - 'a']++;
            // freq2={1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0} ; freq2={1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0} \
            // freq2={1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
        }

        /* check first window. Oooh, you can compare hashmaps 1 to 1? Ooh these are vectors. */
        if (freq1 == freq2) // freq1==freq2?YES
        {

            result.push_back(0); /* push the 0th index */
            // result = {0,}
        }

        /* slide the window across s
            s= cbaebabacd, p=abc
            freq2={1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
        */
        int left = 0, right = patternlen;
        while (right < stringlen) // (i=3, i < 10, i++); (i=4, i < 10, i++); (i=5, i < 10, i++); (i=6, i < 10, i++); (i=7, i < 10, i++); (i=8, i < 10, i++); (i=9, i < 10, i++)
        {
            /* add incoming character */
            freq1[s[right] - 'a']++; // s[3]-a i.e. e++; s[4]-a i.e. b++; s[5]-a i.e. a++; s[6]-a i.e. b++; s[7]-a i.e. a++; s[8]-a i.e. c++; s[9]-a i.e. d++
            // freq1={1,1,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}; freq1={1,2,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}; \
            // freq1={2,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}; freq1={1,2,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}; \
            // freq1={2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}; freq1={2,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}; \
            // freq1={1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}

            /* remove outgoing character. Reduces it's count. */
            freq1[s[left] - 'a']--; // s[3-3]-a i.e. c--; s[4-3]-a i.e. b--; s[5-3]-a i.e. a--; s[6-3]-a i.e. e--;  s[7-3]-a i.e. b--; s[8-3]-a i.e. a--; s[9-a]-a i.e. b--
            // freq1={1,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}; freq1={1,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}; \
            // freq1={1,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}; freq1={1,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}; \
            // freq1={2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}; freq1={1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}  \
            // freq1={1,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}

            left++;

            /* compare frequencies */
            if (freq1 == freq2) // freq1==freq2? NO; freq1==freq2? NO; freq1==freq2? NO; freq1==freq2? NO; freq1==freq2? NO; freq1==freq2? YES; freq1==freq2? NO;
            {
                /* if we update left++ above and we don't have to do left+1 here*/
                result.push_back((left)); // ; ; ; ; ; result.pushback(8-3+1), result={0,6} ; ;
                // result.push_back((right - patternlen) + 1); // ; ; ; ; ; result.pushback(8-3+1), result={0,6} ; ;
            }

            
            right++;
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
