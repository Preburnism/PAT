""" 因为之前我们假设学习已经完成，所以学习到的参数被保存下来。假设保存在sample_weight.pkl
文件中，在推理阶段，我们直接加载这些已经学习到的参数 """
import pickle
from dataset.mnist import load_mnist
import numpy as np


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


# load_mnist函数以“(训练图像 ,训练标签 )，(测试图像，测试标签 )”的形式返回读入的MNIST数据。
def get_data():
    (i_train, l_train), (i_test, l_test) = load_mnist(normalize=True,
                                                      flatten=True,
                                                      one_hot_label=False)
    return i_test, l_test


# 读入保存在pickle文件sample_weight.pkl中的学习到的权重参数
def init_network():
    with open("D:/Projects/Git/Python/ch03_sample_weight.pkl", 'rb') as f:
        network = pickle.load(f)  # 以字典变量的形式保存了权重和偏置参数

    return network


def predict(network, x):
    W1, W2, W3 = network['W1'], network['W2'], network['W3']
    b1, b2, b3 = network['b1'], network['b2'], network['b3']

    a1 = np.dot(x, W1) + b1
    z1 = sigmoid(a1)
    a2 = np.dot(z1, W2) + b2
    z2 = sigmoid(a2)
    a3 = np.dot(z2, W3) + b3
    y = softmax(a3)

    return y


img, label = get_data()
network = init_network()

batch_size = 100  # 批数量
accuracy_cnt = 0

# 批处理
for i in range(0, len(img), batch_size):  # range(start, end, step)
    img_batch = img[i:i + batch_size]
    y_batch = predict(network, img_batch)
    p = np.argmax(y_batch, axis=1)  # 沿着第1维方向（以第1维为轴）找到值最大的元素的索引
    accuracy_cnt += np.sum(p == label[i:i + batch_size])
"""
# 逐个predict
for i in range(len(img)):
    y = predict(network, img[i])
    p = np.argmax(y)  # 获取概率最高的元素的索引
    if p == label[i]:
        accuracy_cnt += 1
"""

print("Accuracy: " + str(float(accuracy_cnt) / len(img)))
