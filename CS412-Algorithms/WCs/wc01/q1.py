import numpy as np
import matplotlib.pyplot as plt

n = np.arange(0, 9, 1) 

f_n = 2*n**2 + 3*n + 1; g_n = n**2

plt.figure(figsize=(20, 10))

plt.plot(n, f_n, label='f(n) = 2n^2 + 3n + 1', color='black', linewidth = 2)

c_values = [6, 15/4, 29/9, 45/16, 66/25, 2, 1]  # example c values
for c in c_values:
    cg_n = c * g_n
    plt.plot(n, cg_n, linestyle = '--', linewidth = 1.5)
    plt.text(n[-1], cg_n[-1], f'c={c}', ha = 'right' , va = 'bottom')
    plt.plot(n, c*g_n, label=f'c={c} * g(n) = {c}n^2', linestyle='--')

plt.title('Plot of f(n) and c*g(n) for various values of c')
plt.xlabel('n'); plt.ylabel('Function values')
plt.legend(); plt.grid(True)
plt.show()
