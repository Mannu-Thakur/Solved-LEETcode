[930] Binary Subarrays With Sum  

https://leetcode.com/problems/binary-subarrays-with-sum/description/

* algorithms
* Medium (66.13%)
* Source Code:       930.binary-subarrays-with-sum.cpp
* Total Accepted:    376.9K
* Total Submissions: 570K
* Testcase Example:  '[1,0,1,0,1]\n2'

Given a binary array nums and an integer goal, return the number of non-empty subarrays with a sum goal.

A subarray is a contiguous part of the array.

 
Example 1:


Input: nums = [1,0,1,0,1], goal = 2
Output: 4
Explanation: The 4 subarrays are bolded and underlined below:
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]


Example 2:


Input: nums = [0,0,0,0,0], goal = 0
Output: 15


 
Constraints:


	1 <= nums.length <= 3 * 10^4
	nums[i] is either 0 or 1.
	0 <= goal <= nums.length


