## E1: for a given 'n', generate a random permutation of the sequence <1, 2, 3, ..., n> and find 'X' as the number of times that the running best is updated when computing the minimum in the sequence

import random
import matplotlib.pyplot as plt

def running_best_update(n):
    sequence = list(range(1, n+1))
    random.shuffle(sequence)
    running_best = float('inf')
    updates = 0
    for num in sequence:
        if num < running_best:
            running_best = num
            updates += 1
    return updates

s = 100
e = 100001
step = 500

num_experiments = 100

n_values = []
avg_updates = []

for n in range(1, 100001, 1000):
    updates_sum = 0
    print(f"n: {n}")
    for _ in range(num_experiments):
        updates_sum += running_best_update(n)
    avg_updates.append(updates_sum / num_experiments)
    n_values.append(n)

plt.plot(n_values, avg_updates, marker='o', linestyle='-')
plt.xlabel('n')
plt.ylabel('Average updates for running best (X)')
plt.title('Experiment 1: Running Best Updates vs. n')
plt.grid(True)
plt.show()