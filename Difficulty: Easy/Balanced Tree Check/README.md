<h2><a href="https://www.geeksforgeeks.org/problems/check-for-balanced-tree/1?page=4&sortBy=submissions">Balanced Tree Check</a></h2><h3>Difficulty Level : Difficulty: Easy</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size: 14pt;">Given a <strong>binary tree</strong>, determine if it is <strong>height-balanced</strong>. A binary tree is considered height-balanced if the absolute difference in heights of the left and right subtrees is at most 1 for every node in the tree.</span></p>
<p><span style="font-size: 14pt;"><strong>Examples:</strong></span></p>
<pre><span style="font-size: 14pt;"><strong>Input: </strong>root[] = [1, 2, N, N, 3]
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 1
 &nbsp;&nbsp;&nbsp;/
&nbsp;&nbsp; 2
 &nbsp; &nbsp;\
 &nbsp; &nbsp; 3&nbsp;
<strong>Output: </strong>false
<strong>Explanation:</strong> The height difference between the left and right subtrees at node <code>1</code> is <code>2</code>, which exceeds <code>1</code>. Hence, the tree is not balanced.</span></pre>
<pre><span style="font-size: 14pt;"><strong>Input: </strong>root[] = [10, 20, 30, 40, 60]
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;10
 &nbsp;&nbsp;&nbsp;&nbsp;/&nbsp;&nbsp; \
 &nbsp;&nbsp;&nbsp;20&nbsp;&nbsp; 30 
&nbsp;&nbsp;/&nbsp;&nbsp; \
 40&nbsp;&nbsp; 60
<strong>Output:</strong> true
<strong>Explanation:</strong> The height difference between the left and right subtrees at all nodes is at most <code>1</code>. Hence, the tree is balanced.</span></pre>
<pre><span style="font-size: 14pt;"><strong>Input: </strong>root[] = [1, 2, 3, 4, N, N, N, 5]
       1
      / \
     2   3
    / 
   4
  /
 5
<strong>Output:</strong> false
<strong>Explanation:</strong> The height difference between the left and right subtrees at node <code>2</code> is <code>2</code>, which exceeds <code>1</code>. Hence, the tree is not balanced.</span></pre>
<p><span style="font-size: 14pt;"><strong>Constraints:</strong><br>1 &lt;=number of nodes &lt;= 10<sup>5</sup><br>1 &lt;= node-&gt;data &lt;= 100</span></p></div><p><span style=font-size:18px><strong>Company Tags : </strong><br><code>Amazon</code>&nbsp;<code>Microsoft</code>&nbsp;<code>Walmart</code>&nbsp;<br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Tree</code>&nbsp;<code>Data Structures</code>&nbsp;