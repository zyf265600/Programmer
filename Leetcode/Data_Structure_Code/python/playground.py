# # class Animal:
# #     test = "ok"
# #
# #     @classmethod
# #     def create(cls):
# #         # cls 是调用这个方法的类
# #         return cls()
# #
# #     @staticmethod
# #     def grunt():
# #         # 没有 cls 也没有 self，就是放在类里的普通函数
# #         return Animal.test
# #
# #
# # class Dog(Animal):
# #     pass
# #
# # print(type(Animal.create()).__name__)  # Animal
# # print(type(Dog.create()).__name__)     # Dog
# # print(Animal.grunt())  # *grunt*
# # print(Dog.grunt())     # *grunt*
# #
# # print(-7 % -4)
# #
# arr = list(range(10))
# for i in range(10):
#     print(arr[i], " ")
#
# for n in range(len(arr)-1, -1, -3):
#     print(n)
#
# a = 1
# b = 2
# c = 1.5
# if a < c < b:
#     print("pass")
#
# res = a if c < b else c
# print(res == a)

# a = 5
# b = 10
# print(a+b)
#
# c = 99 if b > 5 else 0
# print(c)

# import math
#
# arr = range(97,100)
# arr_s = range(3)
# for n in arr:
#     print(n)
#
# for i, n in enumerate(arr):
#     print(i,',',n)
#
# for a, b in zip(arr, arr_s):
#     print(a, b)
#
# print(math.floor(math.sqrt(arr[2])))

# print(float("inf"))

arr = [x for x in range(5) if x != 2]
for n in arr:
    print(n)





