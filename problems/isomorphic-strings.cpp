[205] Isomorphic Strings  

https://leetcode.com/problems/isomorphic-strings/description/

* algorithms
* Easy (46.88%)
* Source Code:       205.isomorphic-strings.cpp
* Total Accepted:    1.8M
* Total Submissions: 3.8M
* Testcase Example:  '"egg"\n"add"'

Given two strings s and t, determine if they are isomorphic.

Two strings s and t are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.

 
Example 1:


Input: s = "egg", t = "add"

Output: true

Explanation:

The strings s and t can be made identical by:


	Mapping 'e' to 'a'.
	Mapping 'g' to 'd'.



Example 2:


Input: s = "foo", t = "bar"

Output: false

Explanation:

The strings s and t can not be made identical as 'o' needs to be mapped to both 'a' and 'r'.


Example 3:


Input: s = "paper", t = "title"

Output: true


 
Constraints:


	1 <= s.length <= 5 * 10^4
	t.length == s.length
	s and t consist of any valid ascii character.


