[974] Subarray Sums Divisible by K  

https://leetcode.com/problems/subarray-sums-divisible-by-k/description/

* algorithms
* Medium (55.63%)
* Source Code:       974.subarray-sums-divisible-by-k.cpp
* Total Accepted:    409.4K
* Total Submissions: 736K
* Testcase Example:  '[4,5,0,-2,-3,1]\n5'

Given an integer array nums and an integer k, return the number of non-empty subarrays that have a sum divisible by k.

A subarray is a contiguous part of an array.

 
Example 1:


Input: nums = [4,5,0,-2,-3,1], k = 5
Output: 7
Explanation: There are 7 subarrays with a sum divisible by k = 5:
[4, 5, 0, -2, -3, 1], [5], [5, 0], [5, 0, -2, -3], [0], [0, -2, -3], [-2, -3]


Example 2:


Input: nums = [5], k = 9
Output: 0


 
Constraints:


	1 <= nums.length <= 3 * 10^4
	-10^4 <= nums[i] <= 10^4
	2 <= k <= 10^4


