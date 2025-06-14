# 📌 Longest Subarray with Sum K

**Difficulty:** Medium  
**Accuracy:** 24.64%  
**Submissions:** 666K+  
**Points:** 4  

---

## 🧩 Problem Statement

Given an array `arr[]` containing integers and an integer `k`, your task is to find the **length of the longest subarray** where the **sum of its elements is equal to `k`**.

If there is **no subarray** with sum equal to `k`, return `0`.

---

## ✅ Examples

### Example 1:
```

Input: arr\[] = \[10, 5, 2, 7, 1, -10], k = 15
Output: 6

Explanation:
Subarrays with sum = 15 are:

* \[5, 2, 7, 1]
* \[10, 5]
* \[10, 5, 2, 7, 1, -10]

The longest has length = 6

```

---

### Example 2:
```

Input: arr\[] = \[-5, 8, -14, 2, 4, 12], k = -5
Output: 5

Explanation:
Only subarray with sum = -5 is:
\[-5, 8, -14, 2, 4]

```

---

### Example 3:
```

Input: arr\[] = \[10, -10, 20, 30], k = 5
Output: 0

Explanation:
No subarray with sum = 5 is present.

```

---

## 📊 Constraints

- `1 ≤ arr.size() ≤ 10^5`
- `-10^4 ≤ arr[i] ≤ 10^4`
- `-10^9 ≤ k ≤ 10^9`

---

## 🚀 Expected Time Complexity

- **Time:** `O(N)`
- **Space:** `O(N)`

---

## 💼 Company Tags

- Amazon

---

## 💡 Approach (Recommended)

Use the **Prefix Sum + Hash Map** method to handle:
- Positive and negative numbers
- Efficient lookup of previous prefix sums

Refer to the solution section for implementation.
```
