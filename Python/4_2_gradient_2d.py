import numpy as np
import matplotlib.pylab as plt


def function_2(x):
    return x[0]**2 + x[1]**2
    # 或者np.sum(x**2)


# 由全部变量的偏导数汇总而成的向量称为梯度（gradient）
def numerical_gradient(f, x):
    h = 1e-4
    grad = np.zeros_like(x)  # 生成和x形状相同的数组

    for index in range(x.size):
        tmp_val = x[index]

        # 计算f(x+h)
        x[index] = tmp_val + h
        fxh1 = f(x)

        # 计算f(x-h)
        x[index] = tmp_val - h
        fxh2 = f(x)

        grad[index] = (fxh1 - fxh2) / (2 * h)
        x[index] = tmp_val

    return grad


x = np.array([[np.arange(-3, 3, 0.1)], [np.arange(-3, 3, 0.1)]])
plt.plot(x, function_2(x))
plt.show()
