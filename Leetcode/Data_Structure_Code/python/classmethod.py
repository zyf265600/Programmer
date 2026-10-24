class Animal:
    test = "ok"

    @classmethod
    def create(cls):
        # cls 是调用这个方法的类
        return cls()

    @staticmethod
    def grunt():
        # 没有 cls 也没有 self，就是放在类里的普通函数
        return Animal.test


class Dog(Animal):
    pass

print(type(Animal.create()).__name__)  # Animal
print(type(Dog.create()).__name__)     # Dog
print(Animal.grunt())  # *grunt*
print(Dog.grunt())     # *grunt*

