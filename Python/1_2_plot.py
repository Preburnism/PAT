import matplotlib.pyplot as plt
import numpy as np

x = np.arange(-10, 10, 0.01)
h = 1 / (1 + np.exp(-x))
plt.plot(x, h)

# x轴
y = 0 * x
plt.plot(x, y, color="ORANGE")
# y轴
n = np.arange(-1, 1.2, 0.01)
m = 0 * n
plt.plot(m, n, color="ORANGE")

# show
plt.legend()
plt.show()
