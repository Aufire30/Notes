# vector

## 1.vector的介绍及使用

### 1.1 vector的介绍

> 1. vector是表示可变大小数组的序列容器。
> 2. 就像数组一样，vector也采用的连续存储空间来存储元素。也就是意味着可以采用下标对vector的元素
> 进行访问，和数组一样高效。但是又不像数组，它的大小是可以动态改变的，而且它的大小会被容器自
> 动处理。
> 3. 本质讲，vector使用动态分配数组来存储它的元素。当新元素插入时候，这个数组需要被重新分配大小
> 为了增加存储空间。其做法是，分配一个新的数组，然后将全部元素移到这个数组。就时间而言，这是
> 一个相对代价高的任务，因为每当一个新的元素加入到容器的时候，vector并不会每次都重新分配大
> 小。
> 4. vector分配空间策略：vector会分配一些额外的空间以适应可能的增长，因为存储空间比实际需要的存
> 储空间更大。不同的库采用不同的策略权衡空间的使用和重新分配。但是无论如何，重新分配都应该是
> 对数增长的间隔大小，以至于在末尾插入一个元素的时候是在常数时间的复杂度完成的。
> 5. 因此，vector占用了更多的存储空间，为了获得管理存储空间的能力，并且以一种有效的方式动态增
> 长。
> 6. 与其它动态序列容器相比（deques, lists and forward_lists）， vector在访问元素的时候更加高效，在
> 末尾添加和删除元素相对高效。对于其它不在末尾的删除和插入操作，效率更低。比起lists和
> forward_lists统一的迭代器和引用更好。

### 1.2 vector的使用

#### 1.2.1 vector的定义

![image-20260421170149029](C:\Users\Aufire\AppData\Roaming\Typora\typora-user-images\image-20260421170149029.png)

```C++
#include<iostream>
#include<vector>
using namespace std;

void test1()
{
	vector<int> v1;
	//插入数据
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);

	vector<int> v2(v1); //拷贝构造

	for (size_t i = 0; i < v1.size(); i++)
	{
		cout << v1[i] << " ";
	}
	cout << endl;

	for (size_t i = 0; i < v2.size(); i++)
	{
		cout << v2[i] << " ";
	}
	cout << endl;

	vector<int> v3;
	v3.push_back(10);
	v3.push_back(20);
	v3.push_back(30);
	v3.push_back(40);
	
	v1 = v3;
	for (size_t i = 0; i < v1.size(); i++)
	{
		cout << v1[i] << " ";
	}
	cout << endl;
}

void test2()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);

	//1.operator[] + size
	for (size_t i = 0; i < v1.size(); i++)
	{
		cout << v1[i] << " ";
	}
	cout << endl;

	//2.迭代器
	vector<int>::iterator it = v1.begin();
	while (it != v1.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;

	//3.范围for ->被编译器替换成迭代器方式遍历支持
	for (auto e : v1)
	{
		cout << e << " ";
	}
	cout << endl;

}
```



#### 1.2.2 vector iterator 的使用

![image-20260421170200466](C:\Users\Aufire\AppData\Roaming\Typora\typora-user-images\image-20260421170200466.png)

![image-20260421170207736](C:\Users\Aufire\AppData\Roaming\Typora\typora-user-images\image-20260421170207736.png)



```C++
//const迭代器
void print_vector(const vector<int>& vt)
{
	vector<int>::const_iterator it = vt.begin();
	while (it != vt.end())
	{
		//只读
		cout << *it << " ";
		it++;
	}
	cout << endl;
}

//三种类型的迭代器遍历
void test3()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	//普通正向迭代器 可读可写
	vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		*it *= 2;
		cout << *it << " ";
		it++;
	}
	cout << endl;
	print_vector(v);

	//反向迭代器
	vector<int>::reverse_iterator rit = v.rbegin();
	while (rit != v.rend())
	{
		cout << *rit << " ";
		rit++;
	}
	cout << endl;
}
```



## 2.vector深度剖析及模拟实现

### vector增容

> vector的增容没有固定标准，是一种选择。
>
> 但主流编译器是1.5倍或2倍
>
> - **MSVC（VS 编译器）**：**1.5 倍扩容**
> - **GCC / Clang（Linux、Mac、Android）**：**2 倍扩容**

- 1.5倍增容

  内存利用率高、空间浪费少，但是增容次数多，效率更低，因为每次增容都要付出代价

- 2倍增容

  增容速度快，效率高；但是空间浪费多

### string和vector\<char>的区别

> 1. string数组里面结尾有\0,vector没有
> 2. string支持比较大小、+=; vector则不支持，因为vector不仅仅只存char，还存其他如int类型，+=就没有意义
> 3. string还支持输入，vector如过是int则没有意义