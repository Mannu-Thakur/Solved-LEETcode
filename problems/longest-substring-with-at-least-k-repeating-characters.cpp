[395] Longest Substring with At Least K Repeating Characters  

https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters/description/

* algorithms
* Medium (45.46%)
* Source Code:       395.longest-substring-with-at-least-k-repeating-characters.cpp
* Total Accepted:    264K
* Total Submissions: 580.6K
* Testcase Example:  '"aaabb"\n3'

Given a string s and an integer k, return the length of the longest substring of s such that the frequency of each character in this substring is greater than or equal to k.

if no such substring exists, return 0.

 
Example 1:


Input: s = "aaabb", k = 3
Output: 3
Explanation: The longest substring is "aaa", as 'a' is repeated 3 times.


Example 2:


Input: s = "ababbc", k = 2
Output: 5
Explanation: The longest substring is "ababb", as 'a' is repeated 2 times and 'b' is repeated 3 times.


 
Constraints:


	1 <= s.length <= 10^4
	s consists of only lowercase English letters.
	1 <= k <= 10^5


