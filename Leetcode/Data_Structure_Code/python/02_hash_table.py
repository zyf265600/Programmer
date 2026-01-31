if __name__ == "__main__":
    d1 = {'name': 'Alice', 'age': 25}  # 花括号
    d2 = dict(name='Alice', age=25)  # dict构造函数
    d3 = dict([('name', 'Alice'), ('age', 25)])  # 键值对列表
    d4 = {x: x ** 2 for x in range(5)}  # 字典推导式

    print(d1['name'])
    print(d1.get('name'))

    d1['test'] = 123
    print(d1.get('test'))
