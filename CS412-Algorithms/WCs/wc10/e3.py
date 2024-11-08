## E3: for a given n, generate random integers between 1 and n inclusive adn find X as the count of random numbers generated until every number from 1 to n has been generated at least once

import random
import matplotlib.pyplot as plt

def nuac(n):
    nums_to_cover = set(range(1, n+1))
    nums_generated = set()
    count = 0
    while nums_to_cover:
        rand_num = random.randint(1, n)
        if rand_num in nums_to_cover:
            nums_to_cover.remove(rand_num)
        nums_generated.add(rand_num)
        count += 1
    return count

s = 100
e = 100001
step = 1000

num_experiments = 10

n_values = []
avg_counts = []

for n in range(s, e, step):
    counts_sum = 0
    print(f"n: {n}")
    for _ in range(num_experiments):
        counts_sum += nuac(n)
    avg_counts.append(counts_sum / num_experiments)
    n_values.append(n)

plt.plot(n_values, avg_counts, marker='o', linestyle='-')
plt.xlabel('n')
plt.ylabel('Average count of random numbers generated until all numbers from 1 to n have been generated at least once')
plt.title('Experiment 3: Random Numbers Generated vs. n')
plt.grid(True)
plt.show()
