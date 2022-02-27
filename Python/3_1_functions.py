import matplotlib.pylab as plt
import numpy as np


# 阶跃函数
def step_function(x):
    """ y = x > 0
    return y.astype(np.int) """
    return np.array(x > 0, dtype=np.int32)


# ReLU（Rectified Linear Unit）函数, 线性整流函数
def relu(x):
    return np.maximum(0, x)


# 恒等函数，常用于回归问题
def identity_function(x):
    return x


# S型函数，常用于二元分类问题
def sigmoid(x):
    return 1 / (1 + np.exp(-x))


# 归一化指数函数，常用于多元分类问题
# 改进：在进行softmax的指数函数的运算时，加上（或者减去）某个常数并不会改变运算的结果
# softmax函数的输出值的总和是1，可以把softmax函数的输出解释为“概率”，np.sum(y)=1
def softmax(a):
    c = np.maximum(a)
    exp_a = np.exp(a - c)  # 溢出对策
    sum_exp_a = np.sum(exp_a)
    y = exp_a / sum_exp_a

    return y


# 缺陷：易造成溢出问题
def softmax_defect(a):
    exp_a = np.exp(a)
    sum_exp_a = np.exp(exp_a)
    y = exp_a / sum_exp_a

    return y


x = np.arange(-5.0, 5.0, 0.1)
y = step_function(x)
plt.plot(x, y)

y1 = sigmoid(x)
plt.plot(x, y1)
plt.ylim(-0.1, 1.1)  # y轴范围
plt.show()
