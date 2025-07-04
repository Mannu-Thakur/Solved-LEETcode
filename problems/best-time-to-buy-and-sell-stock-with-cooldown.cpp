[309] Best Time to Buy and Sell Stock with Cooldown  

https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/description/

* algorithms
* Medium (60.43%)
* Source Code:       309.best-time-to-buy-and-sell-stock-with-cooldown.cpp
* Total Accepted:    649.7K
* Total Submissions: 1.1M
* Testcase Example:  '[1,2,3,0,2]'

You are given an array prices where prices[i] is the price of a given stock on the i^th day.

Find the maximum profit you can achieve. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times) with the following restrictions:


	After you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day).


Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

 
Example 1:


Input: prices = [1,2,3,0,2]
Output: 3
Explanation: transactions = [buy, sell, cooldown, buy, sell]


Example 2:


Input: prices = [1]
Output: 0


 
Constraints:


	1 <= prices.length <= 5000
	0 <= prices[i] <= 1000


