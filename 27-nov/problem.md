# Description
CWI's Bank has a simple policy for warning clients about possible fraudulent account activity. If the amount spent by a client on a particular day is greater than or equal to **2x** the client's median spending for a trailing number of days, they send the client a notification about potential fraud. The bank doesn't send the client any notifications until they have at least that trailing number of prior days' transaction data.

Given the number of trailing days **d** and a client's total daily expenditures for a period of **n** days, find and print the number of times the client will receive a notification over all **n** days.

# Example
**d=3**
**expenditures = [10,20,30,40,50]**
At day **4** we have trailing expenditures of **expenditures = [10,20,30]**. The median is **20** and the day's expenditure is **40**. Because **40 >= 2x20**, there will be a notice. The next day, our trailing expenditures are **expenditures = [20,30,40]** and the expenditures are **50**. This is less than **2x30** so no notice will be sent. Over the period, there was one notice sent.

# Input Constraints
* **1 <= n < 2x10^5**
* **1<=d<=n**
* **0 <= expenditure[i] <= 200**

# Output Format
Your function returns an integer denoting the total number of times the client receives a notification over a period of **n** days.
