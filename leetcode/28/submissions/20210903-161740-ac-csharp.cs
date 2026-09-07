/*
 * 28. Find the Index of the First Occurrence in a String
 * Difficulty: Easy
 * Status: Accepted
 * Runtime: 1341 ms (beats 5.1%)
 * Memory: 23.7 MB (beats 100.0%)
 * Submitted: 2021-09-03 16:17:40 UTC
 * URL: https://leetcode.com/submissions/detail/548938674/
 */

public class Solution {
    public int StrStr(string haystack, string needle) {
        if(needle.Length == 0){
            return 0;
        }
        
        if(needle.Length > haystack.Length){
            return -1;
        }
        
        else if(haystack.Length == needle.Length){
            for(int i = 0; i < needle.Length; i++){
                if(haystack[i] != needle[i]){
                    return -1;
                }
            }
            return 0;
        }
        
        else{
            int foundIndex = -1;
            //Loop over hatstack to find matches
            for(int i = 0; i < haystack.Length - needle.Length + 1; i++){
                //Find first character match
                if(haystack[i] == needle[0]){
                    //Check the rest of needle if match
                    foundIndex = i;
                    for(int j = 0; j < needle.Length; j++){
                        if(haystack[i+j] != needle[j]){
                            foundIndex = -1;
                            break;
                        }
                    }

                    //If match return result
                    if(foundIndex != -1){
                        return i;
                    }
                }
            }
            return foundIndex;
        }
    }
}
