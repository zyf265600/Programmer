**Truthy** 值是在布尔上下文中被转换为 `true` 的值，而 **Falsy** 值是在布尔上下文中被转换为 `false` 的值。

`true` 和 `false` 是布尔类型的值，它们是 JavaScript 中的实际布尔值。



**Truthy**

“Truthy” 值是在布尔上下文中被转换为 `true` 的值。在 JavaScript 中，以下值被视为 truthy：

- 非空字符串，例如 `'hello'`
- 非零数字，例如 `1` 或 `-1`
- 对象，例如 `{}` 或 `[]`
- 其他所有非 `falsy` 的值

**Falsy**

“Falsy” 值是在布尔上下文中被转换为 `false` 的值。在 JavaScript 中，以下值被视为 falsy：

- `false`
- `0`
- `-0`
- `0n`（BigInt 零值）
- `""`（空字符串）
- `null`
- `undefined`
- `NaN`