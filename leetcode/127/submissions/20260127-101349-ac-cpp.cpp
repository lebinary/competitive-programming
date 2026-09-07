/*
 * 127. Word Ladder
 * Difficulty: Hard
 * Status: Accepted
 * Runtime: 51 ms (beats 75.1%)
 * Memory: 21 MB (beats 76.0%)
 * Submitted: 2026-01-27 10:13:49 UTC
 * URL: https://leetcode.com/submissions/detail/1898448762/
 */

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>>q;
        unordered_set<string> st(wordList.begin(),wordList.end());
        q.push({beginWord,1});
        st.erase(beginWord);

        while(!q.empty()){
            string word=q.front().first;
            int step=q.front().second;
            q.pop();
            if(word==endWord) return step;

            for(int i=0;i<word.size();i++){
                char orginal=word[i];
                for(char ch='a';ch<='z';ch++){
                    word[i]=ch;
                    if(st.find(word)!=st.end()){
                        q.push({word,step+1});
                        st.erase(word);
                    }
                }
                word[i]=orginal;
            }
        }
        return 0;
    }
};
