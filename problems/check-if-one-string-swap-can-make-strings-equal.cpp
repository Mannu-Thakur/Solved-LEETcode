[1790] Check if One String Swap Can Make Strings Equal  

https://leetcode.com/problems/check-if-one-string-swap-can-make-strings-equal/description/

* algorithms
* Easy (49.46%)
* Source Code:       1790.check-if-one-string-swap-can-make-strings-equal.cpp
* Total Accepted:    295.6K
* Total Submissions: 597.7K
* Testcase Example:  '"bank"\n"kanb"'

You are given two strings s1 and s2 of equal length. A string swap is an operation where you choose two indices in a string (not necessarily different) and swap the characters at these indices.

Return true if it is possible to make both strings equal by performing at most one string swap on exactly one of the strings. Otherwise, return false.

 
Example 1:


Input: s1 = "bank", s2 = "kanb"
Output: true
Explanation: For example, swap the first character with the last character of s2 to make "bank".


Example 2:


Input: s1 = "attack", s2 = "defend"
Output: false
Explanation: It is impossible to make them equal with one string swap.


Example 3:


Input: s1 = "kelb", s2 = "kelb"
Output: true
Explanation: The two strings are already equal, so no string swap operation is required.


 
Constraints:


	1 <= s1.length, s2.length <= 100
	s1.length == s2.length
	s1 and s2 consist of only lowercase English letters.


