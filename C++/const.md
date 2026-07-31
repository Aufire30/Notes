# 常量指针

`const int*`或`int const*`都是一个意思

- 此时**不能修改**指针所指向实际地址的**内容**
- 但是**可以**让指针**重新指向其他地址**

> 内容是常量

# 指针常量

`int* const`

- 此时**可以修改**指针所指向的实际地址的**内容**
- 但是**不可以**为指针**重新分配**指向的**地址**

> 指针是常量

# 双重const

`const int* const`

此时内容和地址都不可以修改



# const方法

```cpp
class Entity
{
private:
    int m_X,m_Y;
public:
    int GetX() const
    {
        return m_X;
    }
}
```

const用在方法名后面，意味着这个方法不会修改任何类里面的元素（**只有在类里面才能这么用**）





**但是也有办法进行修改**

通过`mutable(可修改的)`这个关键字，将某些**成员变量标记**成可修改的，就可以在const方法中对其进行修改

```cpp
class Entity
{
private:
    int m_X,m_Y;
    mutable int var;
public:
    int GetX() const
    {
        var = 2;
        return m_X;
    }
}
```

