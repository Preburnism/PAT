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
def softmax(x):
    if x.ndim == 2:
        x = x.T
        x = x - np.max(x, axis=0)
        y = np.exp(x) / np.sum(np.exp(x), axis=0)
        return y.T

    x = x - np.max(x)  # 溢出对策
    return np.exp(x) / np.sum(np.exp(x))


# 缺陷：易造成溢出问题
def softmax_defect(a):
    exp_a = np.exp(a)
    sum_exp_a = np.exp(exp_a)
    y = exp_a / sum_exp_a

    return y


# 均方误差
# y(k)是表示神经网络的输出，t(k)表示监督数据，k表示数据的维数
def mean_square_error(y, t):
    return 0.5 * np.sum((y - t)**2)


# 交叉熵误差
# y(k)是神经网络的输出，t(k)是正确解标签
# 并且，t(k)中只有正确解标签的索引为1，其他均为0（one-hot表示）。
def cross_entropy_error1(y, t):
    delta = 1e-7  # 10^-7
    return -np.sum(t * np.log(y + delta))  # y+Δ防止出现ln(0),即-inf


# mini-batch版交叉熵误差的实现, one-hot=True
def cross_entropy_error(y, t):
    if y.ndim == 1:
        t = t.reshape(1, t.size)
        y = y.reshape(1, y.size)

    batch_size = y.shape[0]
    return -np.sum(t * np.log(y + 1e-7)) / batch_size


# mini-batch版交叉熵误差的实现, one-hot=False, 即监督数据是标签形式
def cross_entropy_error_label(y, t):
    if y.ndim == 1:
        t = t.reshape(1, t.size)
        y = y.reshape(1, y.size)

    batch_size = y.shape[0]
    return -np.sum(np.log(y[np.arange(batch_size), t] + 1e-7)) / batch_size


# 中心差分，利用微小的差分求导数的过程称为数值微分（numerical differentiation）
def numerical_diff(f, x):
    h = 1e-4  # 0.0001
    return (f(x + h) - f(x - h)) / (2 * h)
