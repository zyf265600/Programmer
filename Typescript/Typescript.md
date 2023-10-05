### 变量和类型 (Variables and Types) 

1. **声明变量（Variable Declaration）**

```typescript
let name: string = "John";
let age: number = 30;
let isStudent: boolean = false;
```

2. **数组（Arrays）**

**类型注解方式**：在变量名后添加冒号和类型，使用 `[]` 表示这是一个数组。

```
let names: string[] = ['Alice', 'Bob', 'Charlie'];
```

**泛型（Generic）方式**：使用 `Array<类型>` 来定义。

```
let names: Array<string> = ['Alice', 'Bob', 'Charlie'];
```

**推断（Inference）方式**：TypeScript 也会自动推断数组类型。

```
let names = ['Alice', 'Bob', 'Charlie'];  // 类型推断为 string[]
```

**混合类型（Union Type）数组**：使用 `|` 来定义多种类型。

```
let arr: (string | number)[] = ['Alice', 42];
```

**多维数组**：在类型后面添加多个 `[]`。

```
let matrix: number[][] = [[1, 2, 3], [4, 5, 6]];
```

**数组对象（Array Object）**：使用 `new Array()` 语法。

```
let names = new Array('Alice', 'Bob', 'Charlie');
```

**接口（Interfaces）**：如果你需要，还可以通过接口来定义一个特定结构的数组。

```
interface NameArray {
  [index: number]: string;
}

let names: NameArray = ['Alice', 'Bob'];
```

3. **枚举（Enums）**

```typescript
enum Direction {
  Up,
  Down,
  Left,
  Right
}
```

4. **Any 类型**

```typescript
let notSure: any = 4;
notSure = "maybe a string";
```

5. **Void 类型**

```typescript
function warnUser(): void {
  console.log("This is a warning message");
}
```



### 函数 (Functions)

1. **函数声明（Function Declaration）**

```typescript
function add(x: number, y: number): number {
  return x + y;
}
```

2. **可选参数和默认参数（Optional and Default Parameters）**

```typescript
function buildName(firstName: string, lastName?: string) {
  // ...
}
// 或
function buildName(firstName: string, lastName: string = "Smith") {
  // ...
}
```



### 类 (Classes)

1. **基础类（Basic Class）**

```typescript
class Person {
    name: string;
    constructor(name: string) {
    this.name = name;
  }
}
```

2. **继承（Inheritance）**

```typescript
class Student extends Person {
  grade: number;
}
```

3. **访问修饰符（Access Modifiers）**

```typescript
class Person {
  private name: string;
  public age: number;
  protected isStudent: boolean;
}
```



### 接口 (Interfaces)

1. **基础接口（Basic Interface）**

```typescript
interface LabelledValue {
  label: string;
}
```

2. **可选属性（Optional Properties）**

```typescript
interface SquareConfig {
  color?: string;
  width?: number;
}
```