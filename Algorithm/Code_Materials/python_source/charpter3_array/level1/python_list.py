# coding=utf-8
import numpy as np

if __name__ == '__main__':
    list = []
    print("init list = ", list)

    # 2. 增(append在末尾增加)
    list.append(0)  # 增加一个数字
    list.append(np.zeros(3))  # 增加一个数组
    list.append(["a", "b"])  # 增加一个列表
    print("after append list = ", list)

    # 3. 改
    list[0] = 1
    print("after modify list = ", list)

    # 4. 插入元素（insert(下标，元素),在指定位置位置增加，原下标及以后下标的元素都会向后移一位）
    list.insert(0, ["c"])
    print("after insert list = ", list)

    # 5. 移除
    list.remove(["c"])  # 删除指定值
    print("remove [""]list = ", list)
    list.pop(1)  # 删除指定索引后的值
    print("remove element after 1 ,list = ", list)
    list.pop()  # 删除最后一个值
    print("after remove laster list = ", list)
