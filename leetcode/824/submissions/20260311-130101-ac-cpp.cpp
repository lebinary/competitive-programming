/*
 * 824. Goat Latin
 * Difficulty: Easy
 * Status: Accepted
 * Runtime: 0 ms (beats 100.0%)
 * Memory: 9.1 MB (beats 71.3%)
 * Submitted: 2026-03-11 13:01:01 UTC
 * URL: https://leetcode.com/submissions/detail/1944999986/
 */

class Solution {
public:
    string toGoatLatin(string sentence) {
        vector<string> words;

        stringstream ss(sentence);
        string token;
        char delim = ' ';
        while(getline(ss, token, delim)) {
            words.push_back(token);
        }

        string aStr = "a";
        for(string& w : words) {
            if(!isVowel(w[0])) {
                char firstChar = w[0];
                w = w.substr(1, w.size() - 1);
                w += firstChar;
            }

            w += "ma";
            w += aStr;
            aStr += "a";
        }

        string res = "";
        for(int i = 0; i < words.size(); ++i) {
            string& w = words[i];
            res += w;
            if(i < words.size() - 1) res += " ";
        }

        return res;
    }

    bool isVowel(char c) {
        return c == 'a' 
            || c == 'e' 
            || c == 'i' 
            || c == 'o' 
            || c == 'u'
            || c == 'A' 
            || c == 'E' 
            || c == 'I' 
            || c == 'O' 
            || c == 'U'; 
    }
};

/**
Approach 1:
- Split sentence by " " => vector<string> words
- For each word : words:
    - if start with consonant:
        cut front, append to the back
    - add "ma"
    - add "aa."
- Merge vector<string> words back to sentence, return
**/
