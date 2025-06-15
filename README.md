# Leetcode-309.-Best-Time-to-Buy-and-Sell-Stock-with-Cooldown
# 💸 Best Time to Buy and Sell Stock with Cooldown 📉📈

## 📝 Problem Statement

You're given an array `prices` where `prices[i]` is the price of a given stock on the `i-th` day.

You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times) **with the following constraints**:

* After you sell your stock, **you cannot buy stock on the next day** (i.e., cooldown for one day).
* You may not engage in multiple transactions at the same time (i.e., you must sell the stock before you buy again).

🔍 Return the maximum profit you can achieve.

---

## 🧪 Example

**Input:** `[1,2,3,0,2]`
**Output:** `3`

**Explanation:**

* Buy on day 0 (price = 1)
* Sell on day 2 (price = 3), **profit = 2**
* Cooldown on day 3
* Buy on day 4 (price = 2)
* **Total profit = 3**

---

## 🚀 Approaches

### 🔁 1. Pure Recursive Approach (Brute Force)

🧠 **Idea**:

* Recursively try every decision at each day:

  * If you have stock, try selling or holding.
  * If you don’t have stock, try buying or skipping.
* Apply cooldown rule by skipping a day after selling.

📉 **Drawbacks**:

* Extremely inefficient due to overlapping subproblems.

⏱️ **Time Complexity:** `O(2^n)` (Exponential)
💾 **Space Complexity:** `O(n)` (Recursion stack)

---

### 🧠 2. Top-Down Approach (Memoization / DP + Recursion)

📦 **Idea**:

* Use a 2D `dp[i][have]` table to store subproblem results.
* Avoid redundant recalculations by caching:

  * `i` = current day
  * `have` = whether stock is held

🔄 **Transitions**:

* If holding: Sell today or hold.
* If not holding: Buy today or skip.
* After selling, move to `i+2` (cooldown).

⚡ **Advantages**:

* Significantly improves performance.

⏱️ **Time Complexity:** `O(n*2)` = `O(n)`
💾 **Space Complexity:** `O(n)` recursion + `O(n*2)` DP table

---

### 📊 3. Bottom-Up Approach (Tabulation) — 💡 (Optional improvement)

🧠 **Idea**:

* Build DP table iteratively from the last day backwards.
* Store profits for both states: `have` (1 or 0).
* At each step, choose the best option considering cooldown.

⚡ **Advantages**:

* Avoids recursion.
* Easy to optimize further with space compression.

⏱️ **Time Complexity:** `O(n)`
💾 **Space Complexity:** `O(n*2)` or can be optimized to `O(1)`

---

## 📊 Approach Comparison

| Approach               | Time Complexity | Space Complexity | Performance 🏎️ | Suitability 📚            |
| ---------------------- | --------------- | ---------------- | --------------- | ------------------------- |
| Pure Recursion         | `O(2^n)`        | `O(n)`           | ❌ Slow          | Good for concept clarity  |
| Top-Down (Memo)        | `O(n)`          | `O(n)`           | ✅ Efficient     | Best for interviews 👨‍💻 |
| Bottom-Up (Tabulation) | `O(n)`          | `O(n)` or `O(1)` | ✅✅ Fastest      | Best for production 🚀    |

---

## 👨‍💻 Author Info

* **Name**: Ridham Garg
* **Roll Number**: 102203014
* **University**: Thapar University, Patiala
* **Experience**: README handcrafted by a 50-year experienced README master 🧓🖊️

---

## 🎉 Final Words

✨ Understanding how state and transitions work in this dynamic programming problem is the key. Whether you're starting with brute force to understand the problem or optimizing for top-notch performance, this problem teaches essential skills in DP with state modeling and constraints like cooldowns.

📚 Master this pattern, and you'll conquer many more dynamic programming challenges!

Happy Coding! 💻🔥💹
