import numpy as np
import matplotlib.pyplot as plt

n = np.arange(1, 1000001)  # Adjust as needed for 'large values' of n

log2_n = np.log2(n)  # Base 2
log7_n = np.log(n) / np.log(7)  # Change of base to 7
log10_n = np.log10(n)  # Base 10
log100_n = np.log(n) / np.log(100)  # Change of base to 100

# Set up the plot
plt.figure(figsize=(20, 10))

plt.plot(n, log2_n, label='Base 2', color='blue')
plt.plot(n, log7_n, label='Base 7', color='red')
plt.plot(n, log10_n, label='Base 10', color='green')
plt.plot(n, log100_n, label='Base 100', color='black')

# Add title and labels
plt.title('Logarithm functions with different bases')
plt.xlabel('n'); plt.ylabel('log(n)')
plt.legend(); 
plt.text(n[-1], log2_n[-1], r'$\log_2(n)$', fontsize=12, verticalalignment='bottom', horizontalalignment='right')
plt.text(n[-1], log7_n[-1], r'$\log_7(n)$', fontsize=12, verticalalignment='bottom', horizontalalignment='right')
plt.text(n[-1], log10_n[-1], r'$\log_{10}(n)$', fontsize=12, verticalalignment='bottom', horizontalalignment='right')
plt.text(n[-1], log100_n[-1], r'$\log_{100}(n)$', fontsize=12, verticalalignment='bottom', horizontalalignment='right')
plt.grid(True); plt.show()
