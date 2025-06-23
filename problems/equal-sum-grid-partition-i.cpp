[3546] Equal Sum Grid Partition I  

https://leetcode.com/problems/equal-sum-grid-partition-i/description/

* algorithms
* Medium (42.10%)
* Source Code:       3546.equal-sum-grid-partition-i.cpp
* Total Accepted:    22.5K
* Total Submissions: 53.4K
* Testcase Example:  '[[1,4],[2,3]]'

You are given an m x n matrix grid of positive integers. Your task is to determine if it is possible to make either one horizontal or one vertical cut on the grid such that:


	Each of the two resulting sections formed by the cut is non-empty.
	The sum of the elements in both sections is equal.


Return true if such a partition exists; otherwise return false.

 
Example 1:


Input: grid = [[1,4],[2,3]]

Output: true

Explanation:



A horizontal cut between row 0 and row 1 results in two non-empty sections, each with a sum of 5. Thus, the answer is true.


Example 2:


Input: grid = [[1,3],[2,4]]

Output: false

Explanation:

No horizontal or vertical cut results in two non-empty sections with equal sums. Thus, the answer is false.


 
Constraints:


	1 <= m == grid.length <= 10^5
	1 <= n == grid[i].length <= 10^5
	2 <= m * n <= 10^5
	1 <= grid[i][j] <= 10^5


