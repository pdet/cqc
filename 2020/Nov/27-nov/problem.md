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

# Benchmarks
## da-go team
* Benchmark benchmark/b_1.txt: 0.120147
Benchmark benchmark/b_2.txt: 0.117722
Benchmark benchmark/b_3.txt: 0.12361
Benchmark benchmark/b_4.txt: 0.152927
Benchmark benchmark/b_5.txt: 0.151146

Benchmark benchmark/b_1-.txt: 0.079723
Benchmark benchmark/b_2-.txt: 0.077103
Benchmark benchmark/b_3-.txt: 0.082449
Benchmark benchmark/b_4-.txt: 0.097172
Benchmark benchmark/b_5-.txt: 0.095994

## Predatory Butterflies
Benchmark benchmark/b_1.txt: 0.258648
Benchmark benchmark/b_2.txt: 0.259392
Benchmark benchmark/b_3.txt: 0.267434
Benchmark benchmark/b_4.txt: 0.707673
Benchmark benchmark/b_5.txt: 0.881251

Benchmark benchmark/b_1-.txt: 0.025723
Benchmark benchmark/b_2-.txt: 0.026224
Benchmark benchmark/b_3-.txt: 0.026865
Benchmark benchmark/b_4-.txt: 0.069159
Benchmark benchmark/b_5-.txt: 0.0908

## Streaking Sweat Club
Benchmark benchmark/b_1.txt: 20.6885
Benchmark benchmark/b_2.txt: 17.1501
Benchmark benchmark/b_3.txt: 21.3278
Benchmark benchmark/b_4.txt: 55.1833
Benchmark benchmark/b_5.txt: 57.4637

Benchmark benchmark/b_1-.txt: 2.24184
Benchmark benchmark/b_2-.txt: 1.84575
Benchmark benchmark/b_3-.txt: 2.28259
Benchmark benchmark/b_4-.txt: 6.56285
Benchmark benchmark/b_5-.txt: 7.07863

## PT
Benchmark benchmark/b_1.txt: 0.01063
Benchmark benchmark/b_2.txt: 0.008764
Benchmark benchmark/b_3.txt: 0.010484
Benchmark benchmark/b_4.txt: 0.00928
Benchmark benchmark/b_5.txt: 0.00697

Benchmark benchmark/b_1-.txt: 0.011274
Benchmark benchmark/b_2-.txt: 0.009808
Benchmark benchmark/b_3-.txt: 0.011234
Benchmark benchmark/b_4-.txt: 0.011145
Benchmark benchmark/b_5-.txt: 0.00943