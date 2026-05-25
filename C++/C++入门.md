



# C++入门

> 面向对象的三大特征：封装、继承、多态

## 1.C++关键字(C++ 98)

**C++总计63个关键字，C语言32个关键字**
**ps：下面我们只是看一下C++有多少关键字，不对关键字进行具体的讲解。后面我们学到以后再细讲。**

| asm            | do               | if                   | return          | try             | continue     |
| -------------- | ---------------- | -------------------- | --------------- | --------------- | ------------ |
| **auto**       | **doubel**       | **inline**           | **short**       | **typedef**     | **for**      |
| **bool**       | **dynamic_cast** | **int**              | **signed**      | **typeid**      | **public**   |
| **break**      | **else**         | **long**             | **sizeof**      | **typename**    | **throw**    |
| **case**       | **enum**         | **mutable**          | **static**      | **union**       | **wchar_t**  |
| **catch**      | **explicit**     | **namespace**        | **static_cast** | **unsigned**    | **default**  |
| **char**       | **export**       | **new**              | **struct**      | **using(引用)** | **friend**   |
| **class**      | **extern**       | **operator**         | **switch**      | **virtual**     | **register** |
| **const**      | **false**        | **private**          | **template**    | **void**        | **ture**     |
| **const_cast** | **float**        | **protected**        | **this**        | **volatile**    | **while**    |
| **delete**     | **goto**         | **reinterpret_cast** |                 |                 |              |

## 2.命名空间

在C/C++中，变量、函数和后面要学到的类都是大量存在的，这些变量、函数和类的名称将都存在于**全局作**
**用域**中，可能会导致很多冲突。使用命名空间的目的是**对标识符的名称进行本地化**，以**避免命名冲突或名字**
**污染**，namespace关键字的出现就是针对这种问题的。

### 2.1命名空间的定义

定义命名空间，需要使用到**namespace**关键字，**后面跟命名空间的名字**，然后**接一对{ }**即可，{ }中即为**命名**
**空间的成员。**

```c++
//1. 普通的命名空间
namespace N1 // N1为命名空间的名称
{
// 命名空间中的内容，既可以定义变量，也可以定义函数
int a;
int Add(int left, int right)
{
return left + right;
}
}
//2. 命名空间可以嵌套
namespace N2
{
int a;
int b;
int Add(int left, int right)
{
return left + right;
}
namespace N3
{
int c;
int d;
int Sub(int left, int right)
{
return left - right;
}
}
}
//3. 同一个工程中允许存在多个相同名称的命名空间,编译器最后会合成同一个命名空间中。
namespace N1
{
int Mul(int left, int right)
{
return left * right;
}
}
```

注意：**一个命名空间就定义了一个新的作用域**，命名空间中的所有内容都**局限于**该命名空间中

### 2.2命名空间的使用

命名空间中的成员该如何使用呢？例如：

```c++
namespace N
{
int a = 10;
int b = 20;
int Add(int left, int right)
{
return left + right;
}
int Sub(int left, int right)
{
return left - right;
}
}
int main()
{
printf("%d\n", a); // 该语句编译出错，无法识别a
return 0;
}
```

命名空间的使用有三种方式:

- 加命名空间名称及作用域限定符

```c++
int main()
{
printf("%d\n", N::a);//该语句才是正确的打印
return 0;
}
```

- 使用using将命名空间中成员引入

```c++
using N::b;
int main()
{
printf("%d\n", N::a);
printf("%d\n", b);
return 0;
}
```

- 使用using namespace 命名空间名称引入

```c++
using namespce N;
int main()
{
printf("%d\n", N::a);
printf("%d\n", b);
Add(10, 20);
return 0;
}
```

## 3.C++输入&输出

```cpp
#include<iostream>
using namespace std;
int main()
{
cout<<"Hello world!!!"<<endl;
return 0;
}
```

说明：
1. 使用**cout标准输出(控制台)**和**cin标准输入(键盘)**时，必须**包含< iostream >头文件**以及**std标准命名空**
    **间。**
    注意：早期标准库将所有功能在全局域中实现，声明在.h后缀的头文件中，使用时只需包含对应头文件
    即可，后来将其实现在std命名空间下，为了和C头文件区分，也为了正确使用命名空间，规定**C++头文**
    **件不带.h**；旧编译器(vc 6.0)中还支持<iostream.h>格式，后续编译器已不支持，因此**推荐**使用
    **<iostream>+std**的方式。

  ![image-20250218211612419](C:\Users\Aufire\AppData\Roaming\Typora\typora-user-images\image-20250218211612419.png)

2. 使用C++输入输出更方便，不需增加数据格式控制，比如：整形--%d，字符--%c,因为c++里面会**自动识别类型**

  ```cpp
  #include <iostream>
  using namespace std;
  int main()
  {
  int a;
  double b;
  char c;
  cin>>a;                                                              
  cin>>b>>c;
  cout<<a<<endl;
  cout<<b<<" "<<c<<endl;
  return 0;
  }
  ```

### cout输入

  **cout**是**输出流对象**,字符串顺着输出流符号"**<<**"流到cout里面去，**cout相当于黑框控制台**

但输出要**引用**std库![image-20250219152503505](C:\Users\Aufire\AppData\Roaming\Typora\typora-user-images\image-20250219152503505.png)

或者**指定**std库![image-20250219152711377](C:\Users\Aufire\AppData\Roaming\Typora\typora-user-images\image-20250219152711377.png)

如果要**输出换行符**，我们仍可以在最后加上\n![image-20250219152910530](C:\Users\Aufire\AppData\Roaming\Typora\typora-user-images\image-20250219152910530.png)

但C++更喜欢用![image-20250219152943436](C:\Users\Aufire\AppData\Roaming\Typora\typora-user-images\image-20250219152943436.png)这样来换行,且仍需要引用std![image-20250219153136552](C:\Users\Aufire\AppData\Roaming\Typora\typora-user-images\image-20250219153136552.png)

在最前面**全局引用std**，后面可以不再指定std这么麻烦，但是有可能自己创建的**变量名**会和std库里面的**冲突**

不想麻烦但又不想冲突，可以**小范围展开**

![image-20250219154220359](C:\Users\Aufire\AppData\Roaming\Typora\typora-user-images\image-20250219154220359.png)

这样就只有两个不能创建，其他的都不会和std库里面进行冲突

### cin输出

cin相当于C语言的scanf函数

![image-20250219154937238](C:\Users\Aufire\AppData\Roaming\Typora\typora-user-images\image-20250219154937238.png)

**常用的库里面的一些对象或者类型可以展出来，工程项目中比较推荐这种用法**

日常练习不在乎冲突，可以全部展开

## 4.缺省参数

**缺省一般在声明的时候给，定义不用再定义缺省了**

### 4.1缺省参数概念

缺省参数是**声明或定义函数时**为函数的**参数指定一个默认值**。在调用该函数时，如果**没有指定实参**则采用该
默认值，否则使用指定的实参

```cpp
#include<iostream>
using namespace std;

void Fun(int a = 0)
{
	cout << a << endl;
}

int main()
{
	Fun(10);

	Fun();
}
```

![image-20250219160831549](C:\Users\Aufire\AppData\Roaming\Typora\typora-user-images\image-20250219160831549.png)

如果传参就用传过来的参数，如果没有，就用原先定好的参数，简单来说，**缺省参数**就相当于**备胎**

### 4.2缺省参数分类

- 全缺省参数

```cpp
//全缺省
void Fun(int a = 10, int b = 20, int c = 30)
{
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "c = " << c << endl;
}

int main()
{
	Fun();
	Fun(1);
	Fun(1,2);
	Fun(1,2,3);
}
```

![image-20250219161615911](C:\Users\Aufire\AppData\Roaming\Typora\typora-user-images\image-20250219161615911.png)

**全缺省有四种调用方式**

- 半缺省参数(缺省部分参数)

```cpp
//半缺省
void Fun(int a, int b = 20, int c = 30)
{
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "c = " << c << endl;
}

int main()
{
	Fun();//错误，没有缺省的位置必须得传
	Fun(1);
	Fun(1, 2);
	Fun(1, 2, 3);
}
```

![image-20250219162050568](C:\Users\Aufire\AppData\Roaming\Typora\typora-user-images\image-20250219162050568.png)

![image-20250219162017656](C:\Users\Aufire\AppData\Roaming\Typora\typora-user-images\image-20250219162017656.png)

**缺省必须得从右往左连续缺省**

![image-20250219163333433](C:\Users\Aufire\AppData\Roaming\Typora\typora-user-images\image-20250219163333433.png)

而

![image-20250219163440302](C:\Users\Aufire\AppData\Roaming\Typora\typora-user-images\image-20250219163440302.png)

![image-20250219163500557](C:\Users\Aufire\AppData\Roaming\Typora\typora-user-images\image-20250219163500557.png)

![image-20250219163517309](C:\Users\Aufire\AppData\Roaming\Typora\typora-user-images\image-20250219163517309.png)

这几种等都不行，必须从右往左，即**最右边一定得有缺省参数**

而且传参也不能这样传![image-20250219164005393](C:\Users\Aufire\AppData\Roaming\Typora\typora-user-images\image-20250219164005393.png)



**传参必须从左往右连续传参,不能空缺**



**逗号**的目的是为了**分割参数**，但是这里参数都没有，逗号就没有意义

## 5.函数重载

### 5.1函数重载概念

函数重载:是**函数的一种特殊情况**，C++允许在同一作用域中声明几个**功能类似**的**同名函数**，这些同名函数的
形参列表(**参数个数(0个也可以)** 或 **类型** 或 **顺序(参数的前后顺序，只跟类型的顺序有关，和两个同一类型的参数名的顺序无关)**)**必须不同(满足一个就可以)**，常用来处理实现**功能类似数据类型不同**的问题

```cpp
//函数重载
int Add(int left, int right)
{
	return left + right;
}
double Add(double left, double right)
{
	return left + right;
}
long Add(long left, long right)
{
	return left + right;
}
int main()
{
	Add(10, 20);
	Add(10.0, 20.0);
	Add(10L, 20L);//L表示long类型
	return 0;
}
```

**返回值没有要求**，但是**只是返回值不同**,**不构成函数**重载 

![image-20250219175810015](C:\Users\Aufire\AppData\Roaming\Typora\typora-user-images\image-20250219175810015.png)

**调用**的时候，**实参的类型要对应形参的类型**，他会**自动匹配**然后进行调用

### 5.2名字修饰(name Mangling)

> 重载：面试问题
>
> **1.什么是函数重载**
>
> 
>
> **2.C++是如何支持函数重载的?为什么C语言不支持**
>
> **C语言符号表里面的名称用的就是原函数里面的名称**，所以名称不能相同，会导致冲突
>
> **C++有特殊的函数名修饰规则**,只要参数不同，函数名就不同
>
> 一般形式为**_Z + 函数名的字母个数+函数名+参数的类型首字母(几个参数就几个字母)**

list.h        list.c        test.c

1、预处理     ->头文件展开/宏替换/条件编译/去掉注释
list.i        test.i
2、编译         ->检查语法，生成汇编代码
list.s       test.s
3、汇编         ->汇编代码转成二进制的机器码
list.o      test.o
4、链接         ->将两个目标文件链接到一起

### 5.3 extern"C"

> 有时候在C++工程中可能需要将某些函数**按照C的风格来编译**，**在函数前加extern "C"**，意思是告诉编译器，
> 将**该函数按照C语言规则来编译**。
>
> 比如：tcmalloc是google用C++实现的一个项目，他提供tcmallc()和tcfree
> 两个接口来使用，但如果是C项目就没办法使用，那么他就使用extern “C”来解决。

简单来说，extern"C"就是使函数能够**在C和C++中都通用**，都能通过**编译和链接**过程

```CPP
extern "C" int Add(int left, int right);
int main()
{
Add(1,2);
return 0;
}
```

## 6.引用

### 6.1引用的概念

> **引用**不是新定义一个变量，而是**给已存在变**量**取了一个别名**，编译器**不会**为引用变量**开辟内存空间**，它和它
> 引用的变量**共用同一块内存空间**。

```cpp
#include<iostream>
using namespace std;
int main()
{
	int a = 1;
	int& ra = a; //ra是a的引用，引用也就是别名，给a再取了一个名称为ra
	ra = 2;

	return 0;
}
```

**类型+ & +引用变量名（对象名） = 引用实体**

### 6.2引用的特性

1.**引用类型**必须和**引用实体类型**是**同种类型**的

2.引用必须**在定义时初始化**![image-20250220092803313](C:\Users\Aufire\AppData\Roaming\Typora\typora-user-images\image-20250220092803313.png)

3.一个变量可以**有多个引用**

```cpp
int a = 1;
int &c = a;
int b = 2;
c = b;//这里是将b赋值给c
```

### 6.3常引用

**C++规定了临时对象都是带const属性的，即临时变量具有常性**

```cpp
const int a = 10;
//int& ra = a; // 该语句编译时会出错。a原来只是只读(const int类型)，但是引用后，变成了int类型，成可读可写了，不合理
const int& ra = a; //正确
```

```cpp
// int& b = 10;    // 该语句编译时会出错，b为常量，不能单纯的int&引用
const int& b = 10; //应该改为常引用
```

```cpp
	double d = 12.34;
	int rd = d;	   //隐式类型转换,rd是临时变量，临时变量具有常性
	//int& rd = d; // 该语句编译时会出错，类型不同
	const int& rd = d; 
```

![image-20250220210044400](C:\Users\Aufire\AppData\Roaming\Typora\typora-user-images\image-20250220210044400.png)

```cpp
int c = 1;       //c是                  可读可写
int& d = c;
const int& e = c;//可以编译,e变成别名只能  只读
```

**引用取别名时,变量访问的权限可以变小,不能放大**

**权限缩小和权限放大的规则:只适用于引用和指针间**

### 6.4使用场景

> 1.引用**做参数**
>
> ```cpp
> void Swap(int& left, int& right)
> {
> 	int temp = left;
> 	left = right;
> 	right = temp;
> }
> int main()
> {
> 	int a = 0;
> 	int b = 1;
> 	Swap(a, b);
> 	cout << a <<" " << b << endl;
> }
> ```

这里做参数类比于指针，但是

- 传参的时候**不需要传地址**
- 形参的引用和实参是**同一块空间**，形参就是实参的别名，没有开辟新的空间，不同于指针会创建另一块空间

> 2.引用**做返回值**
>
> ```cpp
> int& Count()
> {
> 	static int n = 0;
> 	n++;
> 	return n;
> }
> ```

![image-20250222180013141](C:\Users\Aufire\AppData\Roaming\Typora\typora-user-images\image-20250222180013141.png)

**特殊例题：**

```cpp
int& Add(int a, int b)
{
	int c = a + b;
	return c;
}
int main()
{
	int& ret = Add(1, 2);
	Add(3, 4);
	cout << "Add(1, 2) is :" << ret << endl;
	return 0;
}
```

![image-20250222181643897](C:\Users\Aufire\AppData\Roaming\Typora\typora-user-images\image-20250222181643897.png)

```cpp
static int c = a + b;
```

**statci修饰**之后,**定义只会执行一次**，所以**后面调用**Add(3,4)的时候，函数内部的**c不会再被重新定义**，所以**c一直等于3**

**加了static后，变量c就移动到了静态区，栈帧销毁则不会销毁静态区的c，从而可以正常把c传给别名ret**

注意：**如果函数返回时，出了函数作用域，如果返回对象出了作用域还存在，则可以使用引用返回，**

​            **如果已经不存在了，则必须使用传值返回，否则不安全**

### 6.5传值、传引用效率比较

**传值**和**传返回值**都会**创建临时变量**

使用**引用返回**可以**少创建一个临时变量**,**提高效率**

- 全局变量、静态变量等可以使用引用返回

### 6.6引用和指针的区别

> 1.在**语法概念上**,引用是一个别名,**没有独立空间**，和其引用实体共用一块空间。

```cpp
int main()
{
	int a = 10;
	int& ra = a;

	cout << "&a = " << &a << endl;
	cout << "&ra = " << &ra << endl;
	return 0;
}
```

![image-20250222222954381](C:\Users\Aufire\AppData\Roaming\Typora\typora-user-images\image-20250222222954381.png)

> 2.在**底层实现上**实际**是有空间的**,因为引用是按照**指针方式**来实现的。

```cpp
int main()
{
	int a = 10;
	
	int& ra = a;
	ra = 20;

	int* pa = &a;
	*pa = 20;

	return 0;
}
```

![image-20250222223330748](C:\Users\Aufire\AppData\Roaming\Typora\typora-user-images\image-20250222223330748.png)

**引用一定要初始化，指针不一定，但建议给个NULL**

- **引用和指针的不同点**

1. **引用**在定义时**必须初始化**，指针没有要求
2. **引用**在初始化时**引用一个实体后**，就**不能再引用其他实体**，而**指针**可以在**任何时候指向任何一个**同类型

​	实体

3. **没有NULL引用**，但有NULL指针
4. 在sizeof中含义不同：**引用**结果为引用**类型的大小**，但**指针**始终是**地址空间所占字节个数**(**32位平台**下占

​	**4个字节**,**64位平台**下占**8个字节**)

5. **引用自加**即引用的**实体增加1**，**指针自加**即指针**向后偏移一个类型的大小**
6. 有多级指针，但是**没有多级引用**
7. 访问实体方式不同，**指针**需要显式**解引用**，**引用编译器自己处理**
8. **引用**比指针使用起来相对**更安全**

## 7.内联函数

**直接写在类里面的函数就是内联函数**

**内联函数会在调用它的地方进行展开，展开后就没有了地址，别人调用它就要去链接它，但是没有地址，链接不了**

### 7.1概念

> 以**inline修饰**的函数叫做内联函数，**编译时**C++编译器会在**调用内联函数的地方展开**，**没有函数压栈的开销**，
> 内联函数提升程序运行的效率。

![image-20250222230002376](C:\Users\Aufire\AppData\Roaming\Typora\typora-user-images\image-20250222230002376.png)

如果在上述**函数前**增加**inline**关键字将其改成内联函数，在编译期间**编译器**会**用函数体替换函数的调用**。
查看方式：

1. 在release模式下，查看编译器生成的汇编代码中是否存在call Add
2. 在debug模式下，需要对编译器进行设置，否则不会展开(因为debug模式下，编译器默认不会对代码进

​	行优化，以下给出vs2013的设置方式)

![image-20250222230023640](C:\Users\Aufire\AppData\Roaming\Typora\typora-user-images\image-20250222230023640.png)

![image-20250222230034064](C:\Users\Aufire\AppData\Roaming\Typora\typora-user-images\image-20250222230034064.png)

### 7.2特性

> 1. inline是一种**以空间换时间（用更多的空间来节省时间,增加空间复杂度，减少时间复杂度）**的做法，**省去调用函数额开销**。所以**代码很长**或者**有循环/递归**的函数不适宜使用作为内联函数。
>    - 简单来说，就是把函数都一窝蜂写出来，不再是调用函数，省去了调用函数时创建栈帧时的空间，来节省时间
>    - 假设一个函数有三行代码，调用1w次就是用10003行代码，但是展开之后就是30000行代码
>    - 但是太长就不适合用了:循环、递归,**内联函数适合小函数(小于20行)**
>
> 2. **inline对于编译器而言只是一个建议**，**编译器会自动优化**，如果定义为inline的函数体内有循环/递归等等，编译器优化时会忽略掉内联。
>
> 3. inline**不建议声明和定义分离**，**分离会导致链接错误**。**因为inline被展开，就没有函数地址了**，链接就会找不到。

宏的优缺点:

**优点：**
	1.增强代码的**复用性**。
	2.提高性能。
**缺点：**
	1.**不方便调试宏**。（因为预编译阶段进行了替换）
	2.导致代码**可读性差，可维护性差**，容易误用。
	3.**没有**类型安全的**检查** 。
**C++**有哪些技术替代宏？

1. **常量**定义 换用**const**
2. 函数定义 换用**内联函数**

## 8.auto关键字（c++11）

### 8.1 auto简介

> 可以**根据其初始化来推导其类型**

```cpp
int TestAuto()
{
	return 10;
}
int main()
{
	int a = 10;

	auto b = a; //a的类型是int，可以由auto来推导b的类型也是int
    auto& b = a;//别名也可以推导出是int
    
	auto c = 'a';
	auto d = TestAuto();
    
    

	cout << typeid(b).name() << endl; //可以查看一个变量的类型
	cout << typeid(c).name() << endl;
	cout << typeid(d).name() << endl;

	return 0;
}
```

![image-20250223104843492](C:\Users\Aufire\AppData\Roaming\Typora\typora-user-images\image-20250223104843492.png)

```cpp
auto e
```

无法编译通过，使用**auto定义变量**时必须对其进行**初始化**



### 8.2 auto的使用细则

> **1.auto与指针和引用结合起来使用**
> 用auto声明指针类型时，用auto和auto*没有任何区别，但用auto声明引用类型时则**必须加&**

```cpp
auto* b = &a;//可以推导出是int*类型
auto b = &a; //不加*号也可以推导出是int*类型
```

> **2.在同一行定义多个变量**
>
> 当在**同一行声明多个变量**时，这些变量必须是**相同的类型**，否则编译器将会报错，因为**编译器实际只对**
> **第一个类型进行推导**，然后用推导出来的类型定义其他变量。

```cpp
void TestAuto()
{
auto a = 1, b = 2;
auto c = 3, d = 4.0; // 该行代码会编译失败，因为c和d的初始化表达式类型不同
}
```

### 8.3 auto不能推导的场景

> **1.auto不能作为函数的参数**

```cpp
void TestAuto(auto a)
{}
//此处代码编译失败，auto不能作为形参类型，因为编译器无法对a的实际类型进行推导
```

> **2.auto不能直接用来声明数组**

```cpp
void TestAuto()
{
int a[] = {1,2,3};
auto b[] = {4，5，6};
}
```

> 3.为了避免与C++98中的auto发生混淆，C++11只保留了auto作为类型指示符的用法
>
> 4.auto在实际中最常见的优势用法就是跟以后会讲到的C++11提供的新式for循环，还有lambda表达式等
> 进行配合使用。

## 9.基于范围的for循环（c++11）

### 9.1 范围for的语法

> for循环后的括号由冒号“ ：”分为两部分：**第一部分**是范围内用于迭代的**变量**，**第二部分**则表示被迭代的**范围**。

```cpp
void TestFor()
{
	int array[] = { 1, 2, 3, 4, 5 };
	for(auto& e : array) //加&引用变成别名后，改变e才能改变array数组里面的值
	e *= 2;
	for(auto e : array)
	cout << e << " ";
	return 0;
}
```

**注意：与普通循环类似，可以用continue来结束本次循环，也可以用break来跳出整个循环。**

### 9.2 范围for的使用条件

> **1.for循环迭代的范围必须是确定的**

​	**对于数组而言，就是数组中第一个元素和最后一个元素的范围**；

​	对于类而言，应该提供begin和end的方法，begin和end就是for循环迭代的范围。
​	注意：以下代码就有问题，因为for的范围不确定

```cpp
void TestFor(int array[])
{
	for(auto& e : array) //这里的array已经不是数组了,这里已经退化成指针
	cout<< e <<endl;
}
```



> **2.迭代的对象要实现++和==的操作**

## 10.指针空值nullptr(C++11)

### 10.1 C++98中的指针空值

```cpp
void f(int)
{
	cout << "整形" << endl;
}
void f(int*)
{
	cout << "整形指针" << endl;
}
int main()
{
	f(0);
	f(NULL);
	f((int*)NULL);
	return 0;
}
```

![image-20250223114919614](C:\Users\Aufire\AppData\Roaming\Typora\typora-user-images\image-20250223114919614.png)

> **NULL实际是一个宏，在传统的C头文件(stddef.h)中，可以看到如下代码：**

```cpp
#ifndef NULL
#ifdef __cplusplus
#define NULL 0 //NULL可能被定义为字面常量0
#else
#define NULL ((void *)0) //或者被定义为无类型指针(void*)的常量
#endif
#endif
```

### 10.2 C++11中的空指针

**注意：**

1. 在使用**nullptr表示指针空值**时，**不需要包含头文件**，因为nullptr是C++11作为**新关键字**引入的。
   - **nullptr**被定义为**无类型指针(void*)**
2. 在C++11中，**sizeof(nullptr) 与 sizeof((void*)0)所占的字节数相同**。
3. 为了**提高代码的健壮性**，在后续表示指针空值时建议最好使用nullptr。
