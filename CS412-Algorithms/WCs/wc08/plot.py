import time, matplotlib.pyplot as plt
from cutrod import *

def measure_time(func, p, n):
    start = time.time()
    func(p, n)
    end = time.time()
    return end - start

def plot_times(n_values, times, labels):
    for i in range(len(times)):
        plt.plot(n_values, times[i], label=labels[i])
    plt.xlabel('n'); plt.ylabel('time (s)'); plt.legend(); plt.show()

def main():
    n_values = list(range(1, 501))
    p = [i for i in range(1, 501)]
#    functions = [cut_rod, cut_rod_memoize, cut_rod_bottom_up]
#    labels = ['Recursive', 'Memoized', 'Bottom Up']
    functions = [cut_rod_memoize, cut_rod_bottom_up]
    labels = ['Memoized', 'Bottom Up']
    times = []

    for func in functions:
        func_times = []
        for n in n_values:
            t = measure_time(func, p, n)
            print(f'{func.__name__}({n=}) took {t:.6f} seconds')
            func_times.append(t)
        times.append(func_times)
    
    plot_times(n_values, times, labels)

if __name__ == '__main__':
    main()
