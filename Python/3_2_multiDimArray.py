import numpy as np


def step_function(x):
    """ y = x > 0
    return y.astype(np.int) """
    return np.array(x > 0, dtype=np.int32)


def sigmoid(x):
    return 1 / (1 + np.exp(-x))


# ReLU（Rectified Linear Unit）函数, 线性整流函数
def relu(x):
    return np.maximum(0, x)


# 恒等函数
def identity_function(x):
    return x


# 初始化权重和偏置
def init_network():
    network = {}  # 字典保存权重和偏置
    network['W1'] = np.array([[0.1, 0.3, 0.5], [0.2, 0.4, 0.6]])  # 2x3
    network['b1'] = np.array([0.1, 0.2, 0.3])
    network['W2'] = np.array([[0.1, 0.4], [0.2, 0.5], [0.3, 0.6]])  # 3x2
    network['b2'] = np.array([0.1, 0.2])
    network['W3'] = np.array([[0.1, 0.3], [0.2, 0.4]])  # 2x2
    network['b3'] = np.array([0.1, 0.2])

    return network


# 封装了将输入信号转换为输出信号的处理过程
def forward(network, x):
    W1, W2, W3 = network['W1'], network['W2'], network['W3']
    b1, b2, b3 = network['b1'], network['b2'], network['b3']

    a1 = np.dot(x, W1) + b1
    z1 = sigmoid(a1)  # z1.shape=(3,)

    a2 = np.dot(z1, W2) + b2
    z2 = sigmoid(a2)  # z2.shape=(2,)

    a3 = np.dot(z2, W3) + b3
    y = identity_function(a3)  # y.shap=(2,)

    return y


network = init_network()
x = np.array([1.0, 0.5])
y = forward(network, x)
print(y)
