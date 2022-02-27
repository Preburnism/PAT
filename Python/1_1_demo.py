import matplotlib.pyplot as plt
import numpy as np

# from matplotlib.image import imread

""" img = imread("E:/Pictures/壁纸/wallhaven-73vge9_1920x1080.png")
# 当前目录下可../xxx/xxx.jpg

plt.imshow(img)
plt.show() """

# initiate data
x = np.arange(-5, 5, 0.1)  # 0.1为单位生成-5-5之间数据
y1 = np.sin(x)
y2 = np.cos(x)

# plot
plt.plot(x, y1, label="sin")
plt.plot(x, y2, linestyle="--", label="cos")  # plot by "--"
plt.xlabel("X")
plt.ylabel("Y")
plt.title("sin(x) & cos(x)")
plt.legend()
plt.show()
'''
x = np.array([1, 3, 5, 7])
y = np.array([[2, 4, 6, 8], [1, 1, 1, 1], [2, 2, 2, 2]])
z = 2

print(x*y)

print("by row")

for row in y:
    print(row)

y = y.flatten()
print(y)
'''
