<h2><a href="https://leetcode.com/problems/next-permutation">Next Permutation</a></h2> <img src='https://img.shields.io/badge/Difficulty-Medium-orange' alt='Difficulty: Medium' /><hr><p>A <strong>permutation</strong> of an array of integers is an arrangement of its members into a sequence or linear order.</p>

<ul>
	<li>For example, for <code>arr = [1,2,3]</code>, the following are all the permutations of <code>arr</code>: <code>[1,2,3], [1,3,2], [2, 1, 3], [2, 3, 1], [3,1,2], [3,2,1]</code>.</li>
</ul>

<p>The <strong>next permutation</strong> of an array of integers is the next lexicographically greater permutation of its integer. More formally, if all the permutations of the array are sorted in one container according to their lexicographical order, then the <strong>next permutation</strong> of that array is the permutation that follows it in the sorted container. If such arrangement is not possible, the array must be rearranged as the lowest possible order (i.e., sorted in ascending order).</p>

<ul>
	<li>For example, the next permutation of <code>arr = [1,2,3]</code> is <code>[1,3,2]</code>.</li>
	<li>Similarly, the next permutation of <code>arr = [2,3,1]</code> is <code>[3,1,2]</code>.</li>
	<li>While the next permutation of <code>arr = [3,2,1]</code> is <code>[1,2,3]</code> because <code>[3,2,1]</code> does not have a lexicographical larger rearrangement.</li>
</ul>

<p>Given an array of integers <code>nums</code>, <em>find the next permutation of</em> <code>nums</code>.</p>

<p>The replacement must be <strong><a href="http://en.wikipedia.org/wiki/In-place_algorithm" target="_blank">in place</a></strong> and use only constant extra memory.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,2,3]
<strong>Output:</strong> [1,3,2]
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [3,2,1]
<strong>Output:</strong> [1,2,3]
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,1,5]
<strong>Output:</strong> [1,5,1]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 100</code></li>
	<li><code>0 &lt;= nums[i] &lt;= 100</code></li>
</ul>


<h2>✅ 3 Approaches | Well Explained | Bruteforce, Better, Optimized ✅
5 </h2>h2>
323
Sep 23, 2023
C++
<h3>Approach 1: Brute Force 🧐 </h3>
<h3>Intuition 🤔</h3>
We want to find the next lexicographically greater permutation of an array of integers, nums.

Approach 🛠️
The brute force solution has three steps:

<p>Find all possible permutations of given array nums.
Linearly search for the given permutation.
Return the very next permutation of the given found permutation.
<h3>Time Complexity ⏳</h3>
Generating All Permutations: Generating all permutations of an array with N elements has a time complexity of O(N!). This is because there are N! (N factorial) possible permutations of an array of size N.</p>

Finding a Particular Arrangement Linearly: After generating all permutations, you would need to linearly search for a particular arrangement. This search would also take O(N!) time in the worst case because you might need to go through all permutations to find the desired one.

Returning the Next Permutation of the Found Permutation: Once you've found the desired permutation, finding the next permutation of it would also take O(N) time because you need to follow the steps for finding the next permutation on that specific permutation.

Thus, the time complexity of this approach would be O(N!) due to the generation of all permutations. It's an inefficient approach, especially for large values of N, and is likely to give a TLE.

<h3>Space Complexity 🚀</h3>
The space complexity for generating all permutations of an array with N elements is O(N!) because you're storing N! different permutations.

<h3>Approach 2: Better Solution (only for cpp users) - Using next_permutation() fun🧐 </h3>
Approach 🛠️
We can use the next_permutation() function. The next_permutation function is a part of the C++ Standard Library's <algorithm> header. It's used to generate the next lexicographically greater permutation of a vector.

<h3>Time Complexity ⏳</h3>
The time complexity of the next_permutation() function is O(N), where N is the size of the input vector (nums in this case).
The function traverses the vector from right to left to find the first pair of two consecutive elements such that the left element is less than the right element. This operation takes O(N) time in the worst case.
The subsequent operations, such as finding the smallest greater element and reversing the subarray, also take O(N) time in total.
So, the overall time complexity is O(N).

<h3>Space Complexity 🚀</h3>
The next_permutation function operates in-place and does not use any additional memory that scales with the input size. Therefore, the space complexity of the nextPermutation function is O(1), which means it uses constant extra memory.

<h3>Code 💻</h3>
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        next_permutation(nums.begin(),nums.end());
    }
};
<h3>Approach 3: Optimized Solution 🧐</h3>
Approach 🛠️
Like in a dictionary the very next word to a given word is almost the same except for a very few alphabets, e.g. in a dictionary Fire would come after fira. Notice how the first three alphabets are the same?
Observing this lexicographical order in an English dictionary, we apply a similar approach in the array as well.
Given array nums we find a break point. What is a breakpoint exactly and why are we finding it?
Notice that the next permutation of [1,2,5,4,3,0] -> [1,3,5,4,2,0] -> [1,3,0,2,4,5]. Observe how two numbers have been swapped( 2 and 3) first, and then the rest of the array is reversed.
This is because 2 is a breakpoint. A breakpoint here refers to a point that is lesser than the next element in the array.
We traverse nums starting from i=n-2th index. We compare each nums[i] with nums[i+1]. If at any index i, nums[i]<nums[i+1], we set i as out breakindex variable.
Now after we've found the breakindex, we traverse the right half of the nums array after breakindex, so from i=n-1 till i=breakpint+1, and look for the least greater after the breakpoint.
In the array example taken above, index 1 was the breakindex and we traverse from element 5 to 0 and find that 3 is the least element greater than 1 in that portion of the array.
Now, we swap the breakindex element with this leastgreat index element.
Now we reverse the array from breakindex+1 to n-1.
-Edge case: It may happen that the array in the input is the last possible maximum permutation possible for the elements like: [5,4,3,3,2,0], so the next permutation will be the reverse of it which is the first smallest possible permutation of the elements. So in case we do not find a breakpoint like in this case, we simply reverse the given nums array.
<h3>Time Complexity ⏳</h3>
The time complexity of this approach is linear. We traverse the array twice: first to find the breakpoint and then to find the least greater element. Each traversal takes O(N) time.tore indices and values.

<h3>Space Complexity 🚀</h3>
The space complexity is constant O(1) because the algorithm operates in-place without using any additional data structures that scale with the input size.

<h3>Code 💻</h3>
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        //find the breakpoint
        int breakpoint=-1;
        int n=nums.size();
        for(int i=n-2;i>=0;i--){
          if(nums[i]<nums[i+1]){
            breakpoint=i;
            break;
          }  
        } 
        if(breakpoint==-1){reverse(nums.begin(),nums.end());return;}
        
        //find least greater of element at the breakpoint
        int leastgreater=-1; 
        int leastGvalue=101;
        for(int i=n-1;i>breakpoint;i--){
            if(nums[i]>nums[breakpoint]){
                if(nums[i]<leastGvalue){
                    leastgreater=i;
                    leastGvalue=nums[i];
                }
            }
        }

        //now swap breakpoint with leastgreater
        swap(nums[breakpoint],nums[leastgreater]);
        
        //reverse everything after the breakpoint
        reverse(nums.begin()+breakpoint+1,nums.end());
return;
}
};
