[977] Squares of a Sorted Array  

https://leetcode.com/problems/squares-of-a-sorted-array/description/

* algorithms
* Easy (73.22%)
* Source Code:       977.squares-of-a-sorted-array.cpp
* Total Accepted:    2.2M
* Total Submissions: 3.1M
* Testcase Example:  '[-4,-1,0,3,10]'

Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.

 
Example 1:


Input: nums = [-4,-1,0,3,10]
Output: [0,1,9,16,100]
Explanation: After squaring, the array becomes [16,1,0,9,100].
After sorting, it becomes [0,1,9,16,100].


Example 2:


Input: nums = [-7,-3,2,3,11]
Output: [4,9,9,49,121]


 
Constraints:


	1 <= nums.length <= 10^4
	-10^4 <= nums[i] <= 10^4
	nums is sorted in non-decreasing order.


 
Follow up: Squaring each element and sorting the new array is very trivial, could you find an O(n) solution using a different approach?
