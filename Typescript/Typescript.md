### 变量和类型 (Variables and Types)

1. **声明变量（Variable Declaration）**

```typescript
let name: string = "John";
let age: number = 30;
let isStudent: boolean = false;
```

2. **数组（Arrays）**

```typescript
let numbers: number[] = [1, 2, 3];
// 或
let numbers: Array<number> = [1, 2, 3];
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