<h2><a href="https://www.geeksforgeeks.org/problems/make-binary-tree/1">Linked List to Binary Tree</a></h2><h3>Difficulty Level : Difficulty: Medium</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size: 14pt;">Given a Linked List Representation of Complete Binary Tree. Your task is to construct the Binary tree from the given LinkedList and return the root of the tree.<br>The result will be judged by printing the level order traversal of the Binary tree. </span></p>
<p><span style="font-size: 14pt;"><strong>Note:&nbsp;</strong>The complete binary tree is represented as a linked list in a way where if the root node is stored at position i, its left, and right children are stored at position&nbsp;<strong>2*i+1</strong>, and&nbsp;<strong>2*i+2</strong> respectively. H is the height of the tree and this space is used implicitly for the recursion stack.</span></p>
<p><span style="font-size: 14pt;"><strong>Examples:</strong></span></p>
<pre><span style="font-size: 14pt;"><strong>Input: </strong>linkedList: 1 -&gt; 2 -&gt; 3 -&gt; 4 -&gt; 5
<img src="https://media.geeksforgeeks.org/img-practice/prod/addEditProblem/700289/Web/Other/blobid0_1725432465.png" width="365" height="73"> <br><strong>Output: </strong>root[] = [1, 2, 3, 4, 5]<strong>
Explanation: </strong>The tree would look like <br><img src="https://media.geeksforgeeks.org/img-practice/prod/addEditProblem/700289/Web/Other/blobid5_1725432604.png" width="395" height="207"> <br>Now, the level order traversal of the above tree is 1 2 3 4 5.
</span></pre>
<pre><span style="font-size: 14pt;"><strong>Input: </strong>linkedList: 5 -&gt; 4 -&gt; 3 -&gt; 2 -&gt; 1<br><img src="https://media.geeksforgeeks.org/img-practice/prod/addEditProblem/700289/Web/Other/blobid1_1725432484.png" width="350" height="70"><br><strong>Output: </strong>root[] = [5, 4, 3, 2, 1]<strong>
Explanation: </strong>The tree would look like
<img src="https://media.geeksforgeeks.org/img-practice/prod/addEditProblem/700289/Web/Other/blobid4_1725432586.png" width="397" height="208"> <br>Now, the level order traversal of the above tree is 5 4 3 2 1.</span></pre>
<pre><span style="font-size: 14pt;"><strong>Input: </strong>linkedList: 10 -&gt; 20<br><strong>Output: </strong>root[] = [10, 20]<strong>
Explanation: </strong>The Binary Tree formed is:</span><br><span style="font-size: 14pt;">     10
    /
   20
The level order traversal of this tree is <code>[10, 20]</code>.</span></pre>
<p><span style="font-size: 14pt;"><strong>Constraints:</strong><br>1 &lt;= numbers of nodes &lt;= 10<sup>6</sup><br>1 &lt;= node-&gt;data &lt;= 10<sup>4</sup></span></p></div><p><span style=font-size:18px><strong>Company Tags : </strong><br><code>Amazon</code>&nbsp;<br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Queue</code>&nbsp;<code>Tree</code>&nbsp;<code>Data Structures</code>&nbsp;<code>Linked List</code>&nbsp;