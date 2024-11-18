<h2><a href="https://www.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=matrix-chain-multiplication">Matrix Chain Multiplication</a></h2><h3>Difficulty Level : Difficulty: Hard</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size: 18px;">Given a sequence of matrices, find the most efficient way to multiply these matrices together. The efficient way is the one that involves the least number of multiplications. </span><span style="font-size: 18px;">The dimensions of the matrices are given in an array <strong>arr[]</strong> of&nbsp;size <strong>n</strong> (such that <strong>n</strong> = number of matrices + 1) where the <strong>i<sup>th</sup></strong> matrix has the dimensions&nbsp;<strong>(arr[i-1]&nbsp;x arr[i])</strong>.</span></p>
<p><strong><span style="font-size: 18px;">Examples:</span></strong></p>
<pre><span style="font-size: 18px;"><strong>Input: </strong>arr[] = [2, 1, 3, 4]
<strong>Output:</strong> 20
<strong>Explanation:</strong> There are 3 matrices of dimensions 2×1, 1×3, and 3×4, Let the input 3 matrices be M1, M2, and M3. There are two ways to multiply ((M1 x M2) x M3) and (M1 x (M2 x M3)), Please note that the result of M1 x M2 is a 2 x 3 matrix and result of (M2 x M3) is a 1 x 4 matrix.
((M1 x M2) x M3)  requires (2 x 1 x 3)  + (0) +  (2 x 3 x 4) = 30 
(M1 x (M2 x M3))  requires (0)  + (1 x 3 x 4) +  (2 x 1 x 4) = 20 
The minimum of these two is 20.</span></pre>
<pre><span style="font-size: 18px;"><strong>Input:</strong> arr[] = [1, 2, 3, 4, 3]
<strong>Output:</strong> 30
<strong>Explanation:</strong> There are 4 matrices of dimensions 1×2, 2×3, 3×4, 4×3. Let the input 4 matrices be M1, M2, M3 and M4. The minimum number of multiplications are obtained by ((M1M2)M3)M4. The minimum number is 1*2*3 + 1*3*4 + 1*4*3 = 30.</span></pre>
<pre><span style="font-size: 18px;"><strong>Input:</strong> arr[] = [3, 4]
<strong>Output:</strong> 0<br><strong>Explanation:</strong> As there is only one matrix so, there is no cost of multiplication.</span></pre>
<p><span style="font-size: 18px;"><strong>Constraints:</strong>&nbsp;<br>2 ≤ n ≤ 100<br>1 ≤ arr[i] ≤ 500</span></p></div><p><span style=font-size:18px><strong>Company Tags : </strong><br><code>Flipkart</code>&nbsp;<code>Microsoft</code>&nbsp;<code>FactSet</code>&nbsp;<br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Dynamic Programming</code>&nbsp;<code>Matrix</code>&nbsp;<code>Data Structures</code>&nbsp;<code>Algorithms</code>&nbsp;