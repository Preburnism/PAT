# import sys, os
# sys.path.append(os.pardir)  # 为了导入父目录中的文件而进行的设定
from dataset.mnist import load_mnist
import numpy as np
from PIL import Image


def img_show(img):
    pil_img = Image.fromarray(np.uint8(img))
    pil_img.show()


# load_mnist函数以“(训练图像 ,训练标签 )，(测试图像，测试标签 )”的形式返回读入的MNIST数据。
# normalize设置是否将输入图像正规化为0.0～1.0的值
# (x_train, t_train), (x_test, t_test)
(img_train, label_train), (img_test, label_test) = load_mnist(flatten=True,
                                                              normalize=False)

# 输出各数据形状
print(img_train.shape)  # (60000, 784)
print(label_train.shape)  # (60000,)
print(img_train.shape)  # (60000, 784)
print(label_test.shape)  # (10000,)

img = img_train[0]
label = label_train[0]

print(label)  # 5

print(img)
print(img.shape)  # (784,)
img = img.reshape(28, 28)  # 把图像的形状变成原来的尺寸
print(img)
print(img.shape)  # (28, 28)

img_show(img)
