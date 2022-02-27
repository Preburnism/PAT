import numpy as np
import matplotlib.pylab as plt
from common.functions import numerical_diff


# 原函数 y = 0.01x^2 + 0.1x
def function_1(x):
    return 0.01 * x * x + 0.1 * x


# 切线方程
def tangent_line(f, x):
    dy = numerical_diff(f, x)  # 利用差分求导
    b = f(x) - dy * x  # 切线与y轴交点
    return lambda t: dy * t + b  # 返回切线方程，lambda定义匿名函数


x = np.arange(0.0, 20.0, 0.1)
y1 = function_1(x)

tf = tangent_line(function_1, 5)  # tf(x)=dy*x+b,求x=5时切线方程
y2 = tf(x)
plt.plot(x, y1)
plt.plot(x, y2)
plt.xlabel('x')
plt.ylabel('f(x)')
plt.grid()
plt.show()
