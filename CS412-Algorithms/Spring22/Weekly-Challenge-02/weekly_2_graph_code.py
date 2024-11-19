# Task 1
import matplotlib.pyplot as plt
import numpy as np

x = np.linspace(0, 200, num=100)

fig = plt.figure(figsize=(5, 5))

# f(n)
y = x*np.log2(x)
plt.plot(x, y, 'b', label="f(n) = nlog(n)")
# g(n)
y1 = 2**x
plt.plot(x, y1, 'r--', label="g(n) = 2^n")
# h(n)
y2 = np.log2(x)
plt.plot(x, y2, 'g-.', label="h(n) = log(n)")
# i(n)
y3 = 2*x*np.log2(x)
plt.plot(x, y3, 'p:', label="i(n) = 2nlog(n)")
# i(n)
y4 = 1/2*x*np.log2(x)
plt.plot(x, y4, 'p:', label="i(n) = 1/2nlog(n)")

plt.grid(True, linestyle =':')
plt.xlim([0, 200])
plt.ylim([0, 200])

plt.title('Analysis of Time Complexity')

plt.xlabel('n')
plt.ylabel('Time')

plt.legend()
plt.show()