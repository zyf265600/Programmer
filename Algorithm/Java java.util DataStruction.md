# Java `java.util` 包常用数据结构

## List 接口
- ArrayList
  
  ```java
  ArrayList<Type> list = new ArrayList<>();

- LinkedList

  ```java
  LinkedList<Type> list = new LinkedList<>();
  ```

## Set 接口

- HashSet

  ```java
  HashSet<Type> set = new HashSet<>();
  ```

- TreeSet

  ```java
  TreeSet<Type> set = new TreeSet<>();
  ```

- LinkedHashSet

  ```java
  LinkedHashSet<Type> linkedHashSet = new LinkedHashSet<>();
  ```

- EnumSet

  ```java
  EnumSet<EnumType> enumSet = EnumSet.noneOf(EnumType.class);
  ```

## Map 接口

- HashMap

  ```java
  HashMap<KeyType, ValueType> map = new HashMap<>();
  ```

- TreeMap

  ```java
  TreeMap<KeyType, ValueType> map = new TreeMap<>();
  ```

- LinkedHashMap

  ```java
  LinkedHashMap<KeyType, ValueType> linkedHashMap = new LinkedHashMap<>();
  ```

- Hashtable

  ```java
  Hashtable<KeyType, ValueType> hashtable = new Hashtable<>();
  ```

- EnumMap

  ```java
  EnumMap<EnumType, ValueType> enumMap = new EnumMap<>(EnumType.class);
  ```

## Queue 接口

- Queue (使用 LinkedList 实现)

  ```java
  Queue<Type> queue = new LinkedList<>();
  ```

- PriorityQueue

  ```java
  PriorityQueue<Type> priorityQueue = new PriorityQueue<>();
  ```

## Deque 接口

- Deque (双端队列)

  ```java
  Deque<Type> deque = new LinkedList<>();
  ```

## 其他

- Stack

  ```java
  Stack<Type> stack = new Stack<>();
  ```

- Vector

  ```java
  Vector<Type> vector = new Vector<>();
  ```