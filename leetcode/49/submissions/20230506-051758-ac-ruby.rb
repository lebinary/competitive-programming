# 49. Group Anagrams
# Difficulty: Medium
# Status: Accepted
# Runtime: 206 ms (beats 5.2%)
# Memory: 218.2 MB (beats 33.6%)
# Submitted: 2023-05-06 05:17:58 UTC
# URL: https://leetcode.com/submissions/detail/945305103/

# @param {String[]} strs
# @return {String[][]}
def group_anagrams(strs)
    res = Hash.new

    strs.each do |s|
        count = Hash.new(0)

        s.each_char do |c|
            count[c.ord - 'a'.ord] += 1
        end

        if res.has_key?(count)
            res[count] << s
        else
            res[count] = [s]
        end
    end
    res.values
end
