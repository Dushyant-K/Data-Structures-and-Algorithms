<h2><a href="https://www.geeksforgeeks.org/problems/diameter-of-binary-tree/1?page=4&sortBy=submissions">Diameter of a Binary Tree</a></h2><h3>Difficulty Level : Difficulty: Medium</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size: 14pt;">Given a binary tree, the <strong>diameter</strong> (also known as the width) is defined as the number of <strong>edges</strong> on the longest path between two leaf nodes in the tree. This path may or may not pass through the root. Your task is to find the diameter of the tree.</span></p>
<p><span style="font-size: 14pt;"><strong>Examples:</strong></span></p>
<pre><span style="font-size: 14pt;"><strong>Input: </strong>root[] = [1, 2, 3]
&nbsp;&nbsp;&nbsp;&nbsp;   1
 &nbsp;&nbsp;&nbsp; /&nbsp;&nbsp;\
 &nbsp;&nbsp; 2 &nbsp;&nbsp; 3
<strong>Output: </strong>2<br><strong>Explanation: </strong>The longest path has 2 edges (node 2 -&gt; node 1 -&gt; node 3).</span></pre>
<pre><span style="font-size: 14pt;"><strong>Input: </strong>root[] = [10, 20, 30, 40, 60]
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;10
 &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; /&nbsp;&nbsp; \
 &nbsp;&nbsp;&nbsp;&nbsp; 20&nbsp;&nbsp;&nbsp; 30
 &nbsp;&nbsp; /&nbsp;&nbsp; \ 
&nbsp;&nbsp; 40&nbsp;&nbsp; 60
<strong>Output: </strong>3<br><strong style="font-family: -apple-system, BlinkMacSystemFont, 'Segoe UI', Roboto, Oxygen, Ubuntu, Cantarell, 'Open Sans', 'Helvetica Neue', sans-serif;">Explanation:</strong><span style="font-family: -apple-system, BlinkMacSystemFont, 'Segoe UI', Roboto, Oxygen, Ubuntu, Cantarell, 'Open Sans', 'Helvetica Neue', sans-serif;">The longest path has 3 edges (node 40 -&gt; node 20<span style="font-size: 14pt;"> -&gt; </span></span>node 10 -&gt; node 30).</span></pre>
<pre><span style="font-size: 14pt;"><strong>Input: </strong><span class="hljs-string">root[]</span> <span class="hljs-string">=</span> [<span class="hljs-number">5</span>, <span class="hljs-number">8</span>, <span class="hljs-number">6</span>, <span class="hljs-number">3</span>, <span class="hljs-number">7</span>, <span class="hljs-literal">N</span>, <span class="hljs-number">9</span>]
           <span class="hljs-number">5</span>
         <span class="hljs-string">/</span>   <span class="hljs-string">\</span>
       <span class="hljs-number">8</span>      <span class="hljs-number">6</span>
      <span class="hljs-string">/</span> <span class="hljs-string">\</span>      <span class="hljs-string">\</span>
     <span class="hljs-number">3</span>   <span class="hljs-number">7</span>      <span class="hljs-number">9</span>
<strong>Output: </strong>4</span><br><span style="font-size: 14pt;"><strong style="font-family: -apple-system, BlinkMacSystemFont, 'Segoe UI', Roboto, Oxygen, Ubuntu, Cantarell, 'Open Sans', 'Helvetica Neue', sans-serif;">Explanation: </strong>The longest path has 4 edges (node 3 -&gt; node 8 -&gt; node 5 -&gt; node 6 -&gt; node 9).</span></pre>
<p><span style="font-size: 14pt;"><strong>Constraints:</strong><br>1 ≤ number of nodes ≤ 10<sup>5</sup><br>0 ≤ node-&gt;data ≤ 10<sup>5</sup></span></p></div><p><span style=font-size:18px><strong>Company Tags : </strong><br><code>Amazon</code>&nbsp;<code>Microsoft</code>&nbsp;<code>OYO Rooms</code>&nbsp;<br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Tree</code>&nbsp;<code>Data Structures</code>&nbsp;