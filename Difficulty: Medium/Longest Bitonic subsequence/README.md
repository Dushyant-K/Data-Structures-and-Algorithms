<h2><a href="https://www.geeksforgeeks.org/problems/longest-bitonic-subsequence0824/1">Longest Bitonic subsequence</a></h2><h3>Difficulty Level : Difficulty: Medium</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size: 18px;">Given an array of positive integers. Find&nbsp;the maximum length of Bitonic subsequence.&nbsp;<br>A subsequence of array is called Bitonic if it is first strictly increasing, then strictly decreasing. R</span><span style="font-size: 18px;">eturn the maximum length of bitonic subsequence.</span><br>&nbsp;<br><span style="font-size: 14pt;"><strong>Note</strong> : A strictly increasing or a strictly decreasing sequence should not be considered as a bitonic sequence</span></p>
<p><span style="font-size: 18px;"><strong>Examples :</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input: </strong>n = 5, nums[] = [1, 2, 5, 3, 2]
<strong>Output: </strong>5
<strong>Explanation: </strong>The sequence {1, 2, 5} is increasing and the sequence {3, 2} is decreasing so merging both we will get length 5.
</span></pre>
<pre><span style="font-size: 18px;"><strong>Input: </strong>n = 8, nums[] = [1, 11, 2, 10, 4, 5, 2, 1]
<strong>Output: </strong>6
<strong>Explanation: </strong>The bitonic sequence {1, 2, 10, 4, 2, 1} has length 6.<br><br></span><span style="font-size: 18px;"><strong>Input: </strong>n = 5, nums[] = [10, 20, 30]
<strong>Output: </strong>0
<strong>Explanation: </strong>The decreasing or increasing part cannot be empty</span><span style="font-size: 18px;"><br></span><span style="font-size: 18px;"><br></span><span style="font-size: 18px;"><strong>Input: </strong>n = 5, nums[] = [10, 10, 10]
<strong>Output: </strong>0
<strong>Explanation: </strong>The subsequences must be strictly increasing or decreasing</span>
</pre>
<p><span style="font-size: 18px;"><strong>Expected Time Complexity:&nbsp;</strong>O(n<sup>2</sup>)<br><strong>Expected Auxiliary Space : </strong>O(n)</span><br>&nbsp;</p>
<p><span style="font-size: 18px;"><strong>Constraints:</strong><br>1 ≤&nbsp;length of array ≤ 10<sup>3</sup><br>1 ≤ arr[i] ≤ 10<sup>4</sup></span></p></div><p><span style=font-size:18px><strong>Company Tags : </strong><br><code>Microsoft</code>&nbsp;<code>Cisco</code>&nbsp;<br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Dynamic Programming</code>&nbsp;<code>Algorithms</code>&nbsp;