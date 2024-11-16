<h2><a href="https://www.geeksforgeeks.org/problems/printing-longest-increasing-subsequence/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=printing-longest-increasing-subsequence">Print Longest Increasing Subsequence</a></h2><h3>Difficulty Level : Difficulty: Medium</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size: 18px;">Given an integer <strong>n</strong> and an array of integers <strong>arr</strong>, return the <strong>Longest Increasing Subsequence</strong> which is <em>Index-wise</em> lexicographically smallest.<br><strong>Note -&nbsp;</strong>A subsequence&nbsp;<span style="font-family: monospace;">S1</span>&nbsp;is&nbsp;<strong>Index-wise</strong>&nbsp;<strong>lexicographically smaller</strong>&nbsp;than a subsequence&nbsp;<span style="font-family: monospace;">S2</span>&nbsp;if in the first position where S1 and S2 differ, sub<span style="font-family: 'andale mono', monospace;">seque</span>nce&nbsp;<code>S1</code>&nbsp;has an element that appears&nbsp;<strong>earlier </strong>in the array&nbsp; arr than the corresponding element in&nbsp;<code>S2</code>.<br>LIS&nbsp; of a given sequence is defined as that longest possible subsequence all of whose elements are in increasing order. For example, the length of LIS for {10, 22, 9, 33, 21, 50, 41, 60, 80} is 6 and the LIS is {10, 22, 33, 50, 60, 80}.&nbsp;</span></p>
<p><strong><span style="font-size: 18px;">Example 1:</span></strong></p>
<pre><span style="font-size: 18px;"><strong>Input:</strong>
n = 16
arr = [0,8,4,12,2,10,6,14,1,9,5,13,3,11,7,15]
<strong>Output:</strong>
0 4 6 9 13 15 
<strong>Explanation:</strong>
longest Increasing subsequence is 0 4 6 9 13 15  and the length of the longest increasing subsequence is 6.</span></pre>
<p><strong><span style="font-size: 18px;">Example 2:</span></strong></p>
<pre><strong><span style="font-size: 18px;">Input:</span></strong>
<span style="font-size: 18px;">n = 1
arr = [1]
<strong>Output:</strong>
1</span></pre>
<p><span style="font-size: 18px;"><strong>Your Task:</strong><br>You don't need to read input or print anything. Your task is to complete the function <strong>longestIncreasingSubsequence()&nbsp;</strong>which takes integer n and array arr&nbsp;and returns the longest increasing subsequence.</span></p>
<p><span style="font-size: 18px;"><strong>Expected Time Complexity:</strong> O(n<sup>2</sup>)<br><strong>Expected Space Complexity:</strong> O(n)</span></p>
<p><strong><span style="font-size: 18px;">Constraint:</span></strong><br><span style="font-size: 18px;">1 &lt;= n &lt; = 10<sup>3</sup><br>0 &lt;= arr[i] &lt;= 10<sup>9</sup></span></p>
<p>&nbsp;</p></div><br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Dynamic Programming</code>&nbsp;<code>Hash</code>&nbsp;<code>Algorithms</code>&nbsp;