## E2: for a given n, generate random integers between 1 and n inclusive and find X as the count of unique random numbers generated before the random number is the same as a previously generated random number.

import random
import matplotlib.pyplot as plt

def urn(n):
    unique_nums = set()
    count = 0
    while True:
        rand_num = random.randint(1, n)
        if rand_num in unique_nums:
            break
        unique_nums.add(rand_num)
        count += 1
    return count

s = 100
e = 100001
step = 1000

num_experiments = 100

n_values = []
avg_counts = []

for n in range(s, e, step):
    counts_sum = 0
    print(f"n: {n}")
    for _ in range(num_experiments):
        counts_sum += urn(n)
    avg_counts.append(counts_sum / num_experiments)
    n_values.append(n)

plt.plot(n_values, avg_counts, marker='o', linestyle='-')
plt.xlabel('n')
plt.ylabel('Average count of unique numbers generated before a repeat')
plt.title('Experiment 2: Unique Numbers Generated vs. n')
plt.grid(True)
plt.show()