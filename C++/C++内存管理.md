# C/C++内存管理

## **1.C/C++内存分布**

> ```cpp
> int globalVar = 1;
> static int staticGlobalVar = 1;
> //以上两个main函数之前就初始化，在哪都能用，作用域是全局
> //但是两个全局变量的链接属性不一样，globalVar在所以文件中可见、staticGlobalVar只在当前文件中可见
> void Test()
> {
> 	static int staticVar = 1;//这个是运行到这里再初始化，它的作用域在Test函数中，只能在Test函数中使用
> 	int localVar = 1;
> 	int num1[10] = { 1, 2, 3, 4 };
> 	char char2[] = "abcd";
> 	char* pChar3 = "abcd";
> 	int* ptr1 = (int*)malloc(sizeof(int) * 4);
> 	int* ptr2 = (int*)calloc(4, sizeof(int));
> 	int* ptr3 = (int*)realloc(ptr2, sizeof(int) * 4);
> 	free(ptr1);
> 	free(ptr3);
> }
> 1. 选择题：
> 选项 : A.栈 B.堆 C.数据段 D.代码段
> globalVar在哪里？__C__ staticGlobalVar在哪里？__C__
> staticVar在哪里？__C__ localVar在哪里？__A__
> num1 在哪里？__A__
>     
> char2(数组名表示首元素的地址)在哪里？__A__ * char2(首元素)在哪里？__A_
> pChar3(指针，指向字符串)在哪里？__A__ * pChar3(字符串)在哪里？__D__
> ptr1在哪里？__A__ * ptr1在哪里？__B__
>     
> 2. 填空题：
> sizeof(num1) = __40__;//算的是整个数组的大小
> sizeof(char2) = __5__;(还有个斜杠零) strlen(char2) = __4__;(斜杠零前的元素个数)
> sizeof(pChar3) = __4/8__;(指针) strlen(pChar3) = __4__;(一样，遇到斜杠零结束)
> sizeof(ptr1) = __4/8__;(指针)
> ```
>
> 

![image-20250311202852795](C:\Users\Aufire\AppData\Roaming\Typora\typora-user-images\image-20250311202852795.png)

【说明】

1. **栈**又叫堆栈，非静态局部变量/函数参数/返回值等等，栈是向下增长的。
2. **内存映射段**是高效的I/O映射方式，用于装载一个共享的动态内存库。用户可使用系统接口创建共享共
    享内存，做进程间通信。（Linux课程如果没学到这块，现在只需要了解一下）
3. **堆**用于程序运行时动态内存分配，堆是可以上增长的。
4. **数据段**--存储全局数据和静态数据。
5. **代码段**--可执行的代码/只读常量。

## **2.C语言中动态内存管理方式**

### 2.1 malloc/calloc/realloc和free

```cpp
void Test()
{
	int* p1 = (int*)malloc(sizeof(int));
	free(p1);
	// 1.malloc/calloc/realloc的区别是什么？
	int* p2 = (int*)calloc(4, sizeof(int));
	int* p3 = (int*)realloc(p2, sizeof(int) * 10);
	// 这里需要free(p2)吗？//不需要，返回给p3了
	free(p3);
}
```

【面试题】

**malloc/calloc/realloc的区别？**

> **malloc：**申请空间
>
> **calloc：**申请空间+初始化成0，把每个字节初始化为0
>
> **realloc：**对原来已经有的空间进行扩容

## **3.C++中动态内存管理**

> C语言内存管理方式在C++中可以继续使用，但有些地方就无能为力而且使用起来比较麻烦，因此C++又提出
> 了自己的内存管理方式：**通过new和delete操作符进行动态内存管理**

### 3.1 new/delete操作内置类型和自定义类型 

![image-20250312160817396](C:\Users\Aufire\AppData\Roaming\Typora\typora-user-images\image-20250312160817396.png)

![image-20250311204512214](C:\Users\Aufire\AppData\Roaming\Typora\typora-user-images\image-20250311204512214.png)

![image-20250312173346394](C:\Users\Aufire\AppData\Roaming\Typora\typora-user-images\image-20250312173346394.png)

【**既然有了malloc和free，new和delete的意义何在？**】：

1.对于上面的**内置类型**，它们**效果一样**的。

2.对于**自定义类型**，**效果就不一样**了。

- **malloc**只申请空间，malloc了一个A对象
- **new**申请空间+**调用构造函数来初始化**

![image-20250311205428114](C:\Users\Aufire\AppData\Roaming\Typora\typora-user-images\image-20250311205428114.png)

- **free**释放空间
- **delete析构函数**+释放空间

![image-20250311205517693](C:\Users\Aufire\AppData\Roaming\Typora\typora-user-images\image-20250311205517693.png)





**注意：申请和释放单个元素的空间(变量)，使用new和delete操作符，申请和释放连续的空间(数组)，使用new[]和delete[]**

### C++中的链表

> C中的链表
>
> ![image-20250312170846148](C:\Users\Aufire\AppData\Roaming\Typora\typora-user-images\image-20250312170846148.png)

![image-20250312170735696](C:\Users\Aufire\AppData\Roaming\Typora\typora-user-images\image-20250312170735696.png)

**相当于默认构造函数，会自动调用默认构造函数**

**成员函数都是内置类型(指针也是)**

**但实际上却没有进行初始化**

> 这时，可以通过创建构造函数来解决

![image-20250312171352850](C:\Users\Aufire\AppData\Roaming\Typora\typora-user-images\image-20250312171352850.png)

 

## 4.operator new与operator delete函数

### 4.1 operator new与operator delete函数（重点）

> **new和delete**是用户进行动态内存申请和释放的**操作符**，**operator new 和operator delete**是系统提供的全局**函数**，
>
> **new在底层调用operator new**全局函数来申请空间，**delete在底层通过operator delete**全局函数来释放空间。
>
> ```cpp
> /*
> operator new：该函数实际通过malloc来申请空间，当malloc申请空间成功时直接返回；申请空间失败，
> 尝试执行空 间不足应对措施，如果改应对措施用户设置了，则继续申请，否则抛异常。
> */
> void* __CRTDECL operator new(size_t size) _THROW1(_STD bad_alloc)
> {
> 	// try to allocate size bytes
> 	void* p;
> 	while ((p = malloc(size)) == 0)
> 		if (_callnewh(size) == 0)
> 		{
> 			// report no memory
> 			// 如果申请内存失败了，这里会抛出bad_alloc 类型异常
> 			static const std::bad_alloc nomem;
> 			_RAISE(nomem);
> 		}
> 	return (p);
> }
> ```
>
> 

> **operator new 实际也是通过malloc来申请空间**，如果malloc申请空间**成功就直接返回**，否则执行用户提供的空间不足应对**措施**，如果用户**提供该措施就继续申请**，**否则就抛异常**。**operator delete 最终是通过free来释放空间的**、

- malloc
- operator new  -> malloc + 失败抛异常实现
- new                   ->operator new + 构造函数

【**总结**】:

**new比起malloc不一样的地方：1.调用构造函数初始化  2.失败了就抛异常**

**delete比起free不一样的地方：1.调用析构函数清理**

operator delete 和 free 没区别，因为释放空间失败直接终止进程，是因为要和operator new成一对才被创造出来的

### 4.2 operator new与operator delete的类专属重载（了解）

> 下面代码演示了，针对链表的节点ListNode通过**重载类专属 operator new/ operator delete**，实现链表节
> 点使用内存池申请和释放内存，提高效率。
>
> ```cpp
> struct ListNode
> {
> 	ListNode* _next; 
> 	ListNode* _prev;
> 	int _data;
> 	void* operator new(size_t n)//专属的operator new
> 	{
> 		void* p = nullptr;
> 		p = allocator<ListNode>().allocate(1);
> 		cout << "memory pool allocate" << endl;
> 		return p;
> 	}
> 	void operator delete(void* p)
> 	{
> 		allocator<ListNode>().deallocate((ListNode*)p, 1);
> 		cout << "memory pool deallocate" << endl;
> 	}
> };
> class List
> {
> public:
> 	List()
> 	{
> 		_head = new ListNode;//会调用专属的operator new
> 		_head->_next = _head;
> 		_head->_prev = _head;
> 	}
> 	~List()
> 	{
> 		ListNode* cur = _head->_next;
> 		while (cur != _head)
> 		{
> 			ListNode* next = cur->_next;
> 			delete cur;
> 			cur = next;
> 		}
> 		delete _head;
> 		_head = nullptr;
> 	}
> private:
> 	ListNode* _head;
> };
> int main()
> {
> 	List l;
> 	return 0;
> }
> ```
>
> 

## **5.new和delete的实现原理**

### 5.1 内置类型

> 如果申请的是内置类型的空间，new和malloc，delete和free基本类似，

**不同的地方**是：new/delete申请和释放的是单个元素的空间，new[]和delete[]申请的是连续空间，

​			   而且**new**在申请空间失败时会**抛异常**，**malloc**会返回**NULL**。

### 5.2 自定义类型

- **new的原理**

  1. 调用operator new函数申请空间

  2. 在申请的空间上执行构造函数，完成对象的构造

- **new T[N]的原理**

  1. 调用operator new[]函数，在operator new[]中实际调用operator new函数**完成N个对象空间的申请**

  2. 在申请的空间上**执行N次构造函数**

- **delete的原理**

  1. 在空间上执行析构函数，完成对象中资源的清理工作

  2. 调用operator delete函数释放对象的空间

- **delete[ ]的原理**

  1. 在释放的对象空间上**执行N次析构函数**，**完成N个对象中资源的清理**

  2. 调用operator delete[]释放空间，实际在operator delete[]中调用operator delete来释放空间

## **6.定位new表达式(replacement-new)**

> **在已分配的原始内存空间中调用构造函数初始化一个对象。**
>
> **使用格式：**new(空间的指针)类型(参数)
>
> **使用场景：**定位new表达式在实际中一般是**配合内存池使用**。因为内存池分配出的内存没有初始化，
>
> ​		所以如果是**自定义类型**的对象，需要使用new的定义表达式进行**显示**调构造函数进行初始化。

```cpp
class Test
{
public:
	Test()
		: _data(0)
	{
		cout << "Test():" << this << endl;
	}
	~Test()
	{
		cout << "~Test():" << this << endl;
	}
private:
	int _data;
};
void Test()
{
	// pt现在指向的只不过是与Test对象相同大小的一段空间，还不能算是一个对象，因为构造函数没有执行
	Test* pt = (Test*)malloc(sizeof(Test));
	new(pt) Test; // 注意：如果Test类的构造函数有参数时，此处需要传参
}
```



## **7.常见面试题**

### 7.1 malloc/free和new/delete的区别

malloc/free和new/delete的**共同点**是：都是**从堆上申请空间**，并且需要用户**手动释放**。

**不同的地方**：

1. malloc和free是**函数**，new和delete是**操作符**

2. malloc申请的空间**不会初始化**，new**可以初始化**

3. malloc申请空间时，**参数传字节数**，new只需在其后跟上**空间的类型**即可

4. malloc的**返回值为void***, 在使用时必须强转，new不需要，因为new后跟的是空间的类型，返回值是**类型的指针**

5. malloc申请空间失败时，**返回的是NULL(0)**，因此使用时必须判空，new不需要，但是new需要捕获异常，new失败了就抛异常

6. 申请自定义类型对象时，malloc/free**只会开辟空间**，不会调用构造函数与析构函数，

  而new在**申请空间后会”调用构造函数“完成对象的”初始化“**，delete在**释放空间前会”调用析构函数“完成空间中资源的清理**

### 7.2 内存泄漏

#### 7.2.1 什么是内存泄漏，内存泄漏的危害

**什么是内存泄漏：**内存泄漏指因为**疏忽或错误**造成程序**未能释放已经不再使用的内存**的情况。内存泄漏并不是指内存在物理上的消失，而是应用程序分配某段内存后，因为设计错误，失去了对该段内存的控制，因而造成了内存的浪费。



**内存泄漏的危害：**长期运行的程序出现内存泄漏，影响很大，如操作系统、后台服务等等，出现内存泄漏会导致

内存被占用的越来越多，响应越来越慢，最终卡死

```cpp
void MemoryLeaks()
{
	// 1.内存申请了忘记释放
	int* p1 = (int*)malloc(sizeof(int));
	int* p2 = new int;
	// 2.异常安全问题
	int* p3 = new int[10];
	Func(); // 这里Func函数抛异常导致 delete[] p3未执行，p3没被释放.
	delete[] p3;
}
```



#### 7.2.2 内存泄漏分类（了解）

> C/C++程序中一般我们关心两种方面的内存泄漏：

- **堆内存泄漏(Heap leak)**

堆内存指的是程序执行中依据须要分配通过malloc / calloc / realloc / new等从堆中分配的一块内存，用完后必须通过调用相应的 free或者delete 删掉。假设程序的设计错误导致这部分内存没有被释放，那么以后这部分空间将无法再被使用，就会产生Heap Leak。

- **系统资源泄漏**

指程序使用系统分配的资源，比方套接字、文件描述符、管道等没有使用对应的函数释放掉，导致系统资源的浪费，严重可导致系统效能减少，系统执行不稳定。

#### 7.2.3 如何检测内存泄漏（了解）

- 在linux下内存泄漏检测：linux下几款内存泄漏检测工具
- 在windows下使用第三方工具：VLD工具说明
- 其他工具：内存泄漏工具比较

#### 7.2.4如何避免内存泄漏

1. 工程前期良好的设计规范，养成良好的编码规范，申请的内存空间记着匹配的去释放。ps：这个理想状态。但是如果碰上异常时，就算注意释放了，还是可能会出问题。需要下一条智能指针来管理才有保证。
2. 采用RAII思想或者智能指针来管理资源。
3. 有些公司内部规范使用内部实现的私有内存管理库。这套库自带内存泄漏检测的功能选项。
4. 出问题了使用内存泄漏工具检测。ps：不过很多工具都不够靠谱，或者收费昂贵。
总结一下:
内存泄漏非常常见，解决方案分为两种：1、事前预防型。如智能指针等。2、事后查错型。如泄漏检测工具

### 7.3 如何一次在堆上申请4G的内存

```cpp
// 将程序编译成x64的进程，运行下面的程序试试？
#include <iostream>
using namespace std;
int main()
{
	void* p = new char[0xfffffffful];
	cout << "new:" << p << endl;
	return 0;
}
```

**32位下申请不成功，改成64位就能申请成功了**

