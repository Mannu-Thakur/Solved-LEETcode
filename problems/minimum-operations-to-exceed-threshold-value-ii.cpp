[3066] Minimum Operations to Exceed Threshold Value II  

https://leetcode.com/problems/minimum-operations-to-exceed-threshold-value-ii/description/

* algorithms
* Medium (45.75%)
* Source Code:       3066.minimum-operations-to-exceed-threshold-value-ii.cpp
* Total Accepted:    185.2K
* Total Submissions: 404.8K
* Testcase Example:  '[2,11,10,1,3]\n10'

You are given a 0-indexed integer array nums, and an integer k.

You are allowed to perform some operations on nums, where in a single operation, you can:


	Select the two smallest integers x and y from nums.
	Remove x and y from nums.
	Insert (min(x, y) * 2 + max(x, y)) at any position in the array.


Note that you can only apply the described operation if nums contains at least two elements.

Return the minimum number of operations needed so that all elements of the array are greater than or equal to k.

 
Example 1:


Input: nums = [2,11,10,1,3], k = 10

Output: 2

Explanation:


	In the first operation, we remove elements 1 and 2, then add 1 * 2 + 2 to nums. nums becomes equal to [4, 11, 10, 3].
	In the second operation, we remove elements 3 and 4, then add 3 * 2 + 4 to nums. nums becomes equal to [10, 11, 10].


At this stage, all the elements of nums are greater than or equal to 10 so we can stop. 

It can be shown that 2 is the minimum number of operations needed so that all elements of the array are greater than or equal to 10.


Example 2:


Input: nums = [1,1,2,4,9], k = 20

Output: 4

Explanation:


	After one operation, nums becomes equal to [2, 4, 9, 3]. 
	After two operations, nums becomes equal to [7, 4, 9]. 
	After three operations, nums becomes equal to [15, 9]. 
	After four operations, nums becomes equal to [33].


At this stage, all the elements of nums are greater than 20 so we can stop. 

It can be shown that 4 is the minimum number of operations needed so that all elements of the array are greater than or equal to 20.


 
Constraints:


	2 <= nums.length <= 2 * 10^5
	1 <= nums[i] <= 10^9
	1 <= k <= 10^9
	The input is generated such that an answer always exists. That is, after performing some number of operations, all elements of the array are greater than or equal to k.


