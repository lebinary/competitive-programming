# 242. Valid Anagram
# Difficulty: Easy
# Status: Accepted
# Runtime: 144 ms (beats 5.8%)
# Memory: 211.7 MB (beats 100.0%)
# Submitted: 2023-05-04 03:43:51 UTC
# URL: https://leetcode.com/submissions/detail/944140313/

# @param {String} s
# @param {String} t
# @return {Boolean}
def is_anagram(s, t)
    map = Hash.new(0)

    s.each_char do |c|
        map[c] += 1
    end

    t.each_char do |c|
        if map.key?(c)
            map[c] -= 1
        else
            return false
        end
    end

    map.each_value do |val|
        if val != 0
            return false
        end
    end

    return true
end
