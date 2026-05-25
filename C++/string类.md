# string类

## 1.标准库中的string类

### 1.1 string类(了解)

1. string是表示字符串的字符串类
2. 该类的接口与常规容器的接口基本相同，再添加了一些专门用来操作string的常规操作。
3. string在底层实际是：basic_string模板类的别名，typedef basic_string<char, char_traits, allocator>string;
4. 不能操作多字节或者变长字符的序列。

在**使用string类时，必须包含#include头文件以及using namespace std;**

### 1.2string类的常用接口说明（最常用的接口）

#### **string类对象的常见构造**

```cpp
void test_string1()
{
	string s1;
	string s2("hello");
	string s3(s2, 1);//从1位置开始向后面拷贝
	string s4(s2, 1, 2);//从1位置开始，向后面拷贝两个字符
	string s5(s2, 1, 6);//如果第三个参数比剩余的字符数大，则输出完后面剩下的字符
	string s6(s2, 1, string::npos);//或者用npos,npos的本质是static const size_t = -1;
	//-1不是真正的负值,无符号的-1换算成补码其实是最大的整形
	//所以s6和s5的第三个参数是差不多的，都是较大的整数,使其可以输出完后面的字符


	cout << s1 << endl;
	cout << s2 << endl;
	cout << s3 << endl;
	cout << s4 << endl;
	cout << s5 << endl;
	cout << s6 << endl;


	string s7(10, 'a');//输出10个字符a
	cout << s7 << endl;

	//字符串的尾插
	s2.push_back('!');//插入一个字符
	s2.append("?");//插入一个字符串
	cout << s2 << endl;

	//更推荐用+=
	s2 += " world";
	cout << s2 << endl;

	//字符串的赋值
	s1 = s7;//最开始的s1只构造却没有赋值 
	cout << s1 << endl;
}

```

#### **string类对象的访问及遍历操作**

**遍历(推荐用这个)**

```cpp
void test_string2()
{
	//遍历
	string s("hello world");

	//[] + 下标  
	//读
	for (size_t i = 0; i < s.size(); i++)//s2.size()得到的是s2中字符串的字符个数,也可以用size(s2)
	{
		cout << s[i];//s2[i]访问的是字符s2中的每一个字符,从s2[0]开始
	}
	cout << endl;

	//写
	for (size_t i = 0; i < s.size(); i++)
	{
		s[i] += 1;
	}
	cout << s << endl;
}
```

**迭代器**

> **迭代器不一定是指针，像指针一样的东西**
>
> **迭代器的底层原理：**
>
> ```cpp
> typedef char*iterator
> ```
>
> 其实iterator是一个**char类型的指针**

![image-20250324174515734](C:\Users\Aufire\AppData\Roaming\Typora\typora-user-images\image-20250324174515734.png)

```cpp
void test_string3()
{
	string s("hello world");
	//迭代器
	cout << s << endl;
	//写
	string::iterator it = s.begin();
	while (it != s.end())
	{
		*it -= 1;
		it++;
	}

	//读
	it = s.begin(); //上面已经定义，可以不用再用string::iterator来再次定义
	while (it != s.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;
}
```

**反向迭代器**

```cpp
void test()
{
	string s("hello world");
	string::reverse_iterator rit = s.rbegin();//iterator 变成了 reverse_iterator  //begin 变成了 rbegin
	while (rit != s.rend())//end 变成了 rend
	{
		cout << *rit << " ";
		rit++;
	}
	cout << endl;
}
```

**const迭代器**

```cpp
//字符串转换为整数
int string2int(const string& str)
{
	int val = 0;
	string::const_iterator it = str.begin();//const_iterator对应const参数
	while (it != str.end())
	{
		val *= 10;
		val += (*it - '0');//1 10+2 120+3 1230+4
		it++;
	}
    
    ////反着遍历
	//val = 0;
	//string::const_reverse_iterator rit = str.rbegin();
	//while (rit != str.rend())
	//{
	//	val *= 10;
	//	val += (*rit - '0');
	//	rit++;
	//}
	return val;
}
int main()
{
	string nums("12345");
	cout << string2int(nums) << endl;

	return 0;
}
```

> **与普通迭代器不同的是:*it的值不能被修改，只能读不能写**

**【优化】:**

每次定义it 或者 rit 的时候，如果有过多的条件的话，前面的类型就很复杂

此时我们可以用auto，让系统帮我们推出类型

```cpp
//优化前
string::const_iterator it = str.begin();
//优化后
auto it = str.begin();
```

**范围for**

```cpp
for(auto ch : s)//从头到尾得输出,s指向第一个字符
{
    cout << ch << endl;
}
```

s从第一个字符开始，每次给ch赋值一个字符并输出，他会自动判断(auto)什么时候结束

**c_str**

> 获取字符数组首地址，用C字符串的形式遍历

> 将字符串变成C语言的形式(结尾有一个\0)

```cpp
const char* str = s.c_str();
while (*str)//str最后面是一个\0,读取到\0会自动停止
{
	cout << *str << " ";
	str++;
}

	cout << s << " " << endl;		 //调用string重载的operator<< （将对象数组中的所有字符输出）
	cout << s.c_str() << " " << endl;//直接输出const char* str = s.c_str() (遇到\0就结束)

	s += '\0';
	s += " world";

	cout << s <<endl;//正常输出
	cout << s.c_str() <<endl;//加了\0后，后面的world则无法输出
```

![image-20250327114052392](C:\Users\Aufire\AppData\Roaming\Typora\typora-user-images\image-20250327114052392.png)

**find & rfind**

> **find(char)**找到对应**字符**char的下标,或者找**字符串**,找到就返回0，找不到就返回-1
>
> **find(char,pos)**从pos的位置开始找，找到字符char
>
> **rfind(char)**找到最后一次出现char的下标

```cpp
void test1()
{
	string s1("string.cpp");
	string s2("string.c");
	string s3("string.txt");

	size_t found1 = s1.find('.');//find返回找到的字符在字符串的下标
	if (found1 != string::npos)
	{
		cout << s1.substr(found1) << endl;//通过下标找到那个字符,并顺着这个字符找下去，形成新的字符串，第二个参数是取字符串的长度，如果第二个参数没有的话，就直接找到结束
	}

	string s4("string.cpp.zip");

	size_t found2 = s4.rfind('.');//rfind，返回在字符串中搜索字符最后一次出现的下标
	if (found2 != string::npos)
	{
		cout << s4.substr(found2) << endl;
	}
}
```

**substr**

> ```cpp
> string substr (size_t pos = 0, size_t len = npos) const;
> //pos是开始找的位置,len是要取出字符的个数
> ```

**取出来的字符重新构成一个新的字符串**



**getline**

> 输入字符串时
>
> **cin**遇到换行或者空格就结束
>
> **getline**遇到换行才结束
>
> ```cpp
> string s
> getline(cin,s);
> ```
>
> 

#### **string类对象的容量操作**

**capacity**

> 返回当前字符串对象分配的内存容量（以字符数为单位）。

```cpp
void TestPushBack()
{
	string s;
	size_t sz = s.capacity();
	cout << "making s grow:\n";
	for (int i = 0; i < 100; ++i)
	{
		s.push_back('c');
		if (sz != s.capacity())
		{
			sz = s.capacity();
			cout << "capacity changed: " << sz << '\n';
		}
	}
}
```

![image-20250324201509314](C:\Users\Aufire\AppData\Roaming\Typora\typora-user-images\image-20250324201509314.png)

**每次扩容大约1.5倍**,但是**随着扩容的次数增多，运行速度会变慢**，因为基数变大了，扩容的增量也变大了，速度会变慢



**reserve**

> 用于在开头给定一个空间的大小

```cpp
void TestPushBackReserve()
{
	string s;
	s.reserve(100);//在一开始就给了100个空间，但实际上不是100个空间
    
	size_t sz = s.capacity();
	cout << "making s grow:\n";
	for (int i = 0; i < 100; ++i)
	{
		s.push_back('c');
		if (sz != s.capacity())
		{
			sz = s.capacity();
			cout << "capacity changed: " << sz << '\n';
		}
	}
}
```

![image-20250324202206743](C:\Users\Aufire\AppData\Roaming\Typora\typora-user-images\image-20250324202206743.png)

**准确来说不是111个，其实是112个，因为还有一个\0,要给\0留一个空间**



**resize**

> 用于调整字符串的长度。如果新长度大于当前长度，可以指定填充字符；如果小于当前长度，则会截断字符串。

![image-20250324203524058](C:\Users\Aufire\AppData\Roaming\Typora\typora-user-images\image-20250324203524058.png)

#### **string类对象的修改操作**

**尾插字符**

```cpp
void test1()
{
	string s("hello");
	s.push_back(' ');
	s.push_back('w');
	s.append("orld1");
	cout << s << endl;
}

//更推荐用这种
void test2()
{
	string s("hello");
	s += " world2";
	cout << s << endl;
}
```

**头插**

```cpp
s.insert(s.begin(), '0');//利用迭代器，在最前面插入一个字符0
cout << s << endl;
```

**中间插入**

```cpp
s.insert(2, "2");//在第二个字符后面插入一个字符2
cout << s << endl;
```

**删除**

```cpp
s.erase(2, 3);//从第二个字符开始，往后删除三个字符
cout << s << endl;
```

![image-20250324211439332](C:\Users\Aufire\AppData\Roaming\Typora\typora-user-images\image-20250324211439332.png)

**如果要删除的字符个数比剩下的字符多，系统不会报错，删到结束为止**

### 各个接口的底层原理

> **模拟实现，类的名字要么大写String，如果是小写string，需要用命名空间namespace进行封装，防止和库里面的string冲突**
>
> 
>
> **模拟实现至少能实现正确的管理资源：构造+析构+拷贝+operator=(赋值)**

```cpp
class String
{
private:
	char* _str;
	size_t _size;
	size_t _capacity;
    static size_t npos;
public:
    //构造
string(const char* str = "")
	:_str(new char[strlen(str) + 1])
{
	strcpy(_str, str);
}

//拷贝构造string s2(s1)

//深拷贝 - 传统写法
string(const string& s)
	:_str(new char[strlen(s._str) + 1])
{
	strcpy(_str, s._str);
}
//赋值 s1 = s2
string& operator=(const string& s)
{
	if (this != &s)//防止自己给自己赋值
	{
		char* tmp = new char[strlen(s._str) + 1];
		strcpy(tmp, s._str);//将s2拷贝给tmp
		delete[] _str;//释放原来s1的空间
		_str = tmp;//让_str(s1)指向tmp(s2),完成赋值
	}
	return *this;
}


//深拷贝 - 现代写法  
string(const string& s)
	:_str(nullptr)
{
	string tmp(s._str);
	swap(_str, tmp._str);
}

//s1 = s2
string& operator=(string s)//这个更简洁,更推荐用这个
{
	swap(_str, s._str);
	return *this;
}
    
string& operator=(const string& s)
{
	if (this != &s)
	{
		string tmp(s);//拷贝构造
		swap(_str, tmp._str);
	}
	return *this;
}

//析构
~string()
{
	delete[] _str;
	_str = nullptr;
}

size_t size()
{
	return strlen(_str);
}

char& operator[](size_t i)
{
	return _str[i];
}
    
    size_t string::npos = -1;
    //reserve将容量扩展到n
	void reserve(size_t n)
	{
		if (n > _capacity)
		{
			//新建一个空间为newstr,是一个char类型的数组
			char* newstr = new char[n + 1];//+1是为了给\0留一个位置
			strcpy(newstr, _str);
			delete[] _str;
			_str = newstr;
			_capacity = n;
		}
	}
    
    //插入
	void push_back(char ch)//插入字符
	{
		//空间满了就增容
		if (_size == _capacity)
		{
			size_t newcapacity = _capacity == 0 ? 2 : _capacity * 2;//如果为0则赋值2，如果不为0就乘二倍
			reserve(newcapacity);
		}
		_str[_size] = ch;
		++_size;
		_str[_size] = '\0';//放完字符后，在最后加上\0
        
        //insert(_size,ch);
	}
    
	void append(const char*str)//插入字符串
	{
		//空间不够增容
		size_t len = strlen(str);
		if (_size + len > _capacity) //注意这里不能用2倍去增，因为不一定够
		{
			reserve(_size + len);
		}

		strcpy(_str + _size, str);
		_size += len;
        
        //insert(_size,str);
	}

    
	//s1 += 'a'
	string& operator+=(char ch)
	{
		this->push_back(ch);
		return *this;
	}
	//s1 += "aaaaaa"
	string& operator+=(const char* str)
	{
		this->append(str);
		return *this;
	}
    
    
    //insert
    string& insert(size_t pos, char ch)//插入字符
{
	assert(pos <= _size);
	if (_size == _capacity)
	{
		size_t newcapacity = _capacity == 0 ? 2 : _capacity * 2;//如果为0则赋值2，如果不为0就乘二倍
		reserve(newcapacity);
	}

	int end = _size;
	while (end >= pos)
	{
		_str[end + 1] = _str[end];
		end--;
	}
		_str[pos] = ch;
		++_size; 
    	return *this;
}
	string& insert(size_t pos, const char* str)//插入字符串
	{
	assert(pos <= _size);

	//如果空间不够则增容
	size_t len = strlen(str);
	if (_size + len > _capacity)
	{
		reserve(_size + len);
	}

	//挪动数据
	int end = _size;
	while (end >= (int)pos)//不强转的话，end会变成-1进入
	{
		_str[end + len] = _str[end];
		end--;
	}
	//插入数据
	//1.循环插入
	for (size_t i = 0; i < len; i++)
	{
		_str[pos] = str[i];
		pos++;
		i++;
	}
		//2.strncpy
		strncpy(_str + pos, str, len);//(相比于strcpy)strncpy:在_str + pos的位置插入字符串str中的len个字符

		_size += len;
    	return *this;
	}
    
    //resize
    void resize(size_t n, char ch = '\0')
{
	if (n < _size)//如果n小于_size
	{
		_str[n] = '\0';//在对应位置赋值\0,相当于删去后面的字符
		_size = n;
	}
	else
	{
		if (n > _capacity)//如果n大于容量
		{
			reserve(n);//则先增容
		}
		for (size_t i = _size; i < n; i++)//再在最后一个有效字符后面加上用户所要求的字符,直至字符个数为n个为止
		{
			_str[i] = ch;
			_size = n;
			_str[_size] = '\0';
		}
	}
}
    
	//erase，从pos位置开始，往后面删除len个字符
string& erase(size_t pos, size_t len = npos)
{
	assert(pos < _size);
	if (len >= (_size - pos))
	{
		_str[pos] = '\0';
		_size = pos;
	}
	else
	{
		size_t i = pos + len;
		while (i <= _size)
		{
			_str[i - len] = _str[len];//数据往前挪
			//或者_str[pos++] = _str[i++]；
			i++;
		}
		_size -= len;
	}
	return *this;
}
    
    //strstr查找一段字符串
char* strstr( char* str1, char* str2)
{
	char* begin = str1;//begin为s1进行移动的初始地址
	char* s1;//s1为str1中进行移动的地址
	char* s2;//s2为str2中进行移动的地址
	if (*str2 == '\0')
	{
		return str1;//如果要查找的字符串为空字符串，则返回字符串str1
	}
	while (*begin)
	{
		s1 = begin;//先从str1的第一个字符开始匹配
		s2 = str2;
		while (*s1 != '\0' && *s2 != '\0' && *s1 == *s2)
		{
			//匹配成功后，进行下一次匹配
			s1++;
			s2++;
		}
		
		if (*s2 == '\0')//当s2 = \0时，说明s2已经被全部找到
		{
			return begin;
		}
		begin++;//再匹配str1的下一个字符
	}
	return nullptr;
}
    
    //find
size_t find(char ch, size_t pos = 0)//查找一个字符
{
	for (size_t i = npos; i < _size; i++)
	{
		if (_str[i] = ch)
			return i;
	}
	return npos;
}
size_t find( char* str, size_t pos = 0)//查找一个字符串
{
	char* p = strstr(_str,str);
	if (p == nullptr)
	{
		return npos;
	}
	else
	{
		return p - _str;//返回字符串首字符的下标,
	}
}


//s1 < s2
bool operator<(const string& s)
{
	int ret = strcmp(_str, s._str);
	return ret < 0;
}
bool operator==(const string& s)
{
	int ret = strcmp(_str, s._str);
	return ret == 0;
}
bool operator<=(const string& s)
{
	return *this < s || *this == s;
}
bool operator>(const string& s)
{
	return !(*this <= s);
}
bool operator>=(const string& s)
{
	return !(*this < s);
}
bool operator!=(const string& s)
{
	return !(*this == s);
}
    
    // >>
    istream& operator>>(istream& in, string& s)
{
	while (1)
	{
		char ch;
		in >> ch;
		if (ch == ' ' || ch == '\0')
		{
			break;
		}
		else
		{
			s += ch;
		}
	}
	return in;
}
    //getline
    istream& operator>>(istream& in, string& s)
{
	while (1)
	{
		char ch;
		in >> ch;
		if (ch == '\0')
		{
			break;
		}
		else
		{
			s += ch;
		}
	}
	return in;
}
};
```



## 2.string类的模拟实现

### 2.1经典的string类问题

> 

```cpp
class string
{
public:
	/*string()
	:_str(new char[1])
	{*_str = '\0';}
	*/
	//string(const char* str = "\0") 错误示范
	//string(const char* str = nullptr) 错误示范
	string(const char* str = "")
	{
		// 构造string类对象时，如果传递nullptr指针，认为程序非法，此处断言下
		if (nullptr == str)
		{
			assert(false);
			return;
		}
		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
	}
	~string()
	{
		if (_str)
		{
			delete[] _str;
			_str = nullptr;
		}
	}
private:
	char* _str;
};
// 测试
void Teststring()
{
	string s1("hello bit!!!");
	string s2(s1);
}
```

> ![image-20250416194938528](C:\Users\Aufire\AppData\Roaming\Typora\typora-user-images\image-20250416194938528.png)
>
> 说明：上述string类没有显式定义其拷贝构造函数与赋值运算符重载，此时编译器会合成默认的，当用s1构
> 造s2时，编译器会调用默认的拷贝构造。最终导致的问题是，s1、s2共用同一块内存空间，在释放时同一块
> 空间被释放多次而引起程序崩溃，这种拷贝方式，称为浅拷贝。

### 2.2浅拷贝(值拷贝)

> 【浅拷贝】：也称位拷贝/值拷贝，编译器**只是将对象中的值拷贝过来**。
>
> 
>
> 如果对象中管理资源，最后就会导致**多个对象共享同一份资源**，
>
> **当一个对象销毁时就会将该资源释放掉，而此时另一些对象不知道该资源已经被释放，以为**
> **还有效，所以 当继续对资源进项操作时，就会发生发生了访问违规**。
>
> ![image-20250416201114564](C:\Users\Aufire\AppData\Roaming\Typora\typora-user-images\image-20250416201114564.png)
>
> 要解决浅拷贝问题，C++中引入了深拷贝。

### 2.3深拷贝

> 如果一个类中涉及到资源的管理，其拷贝构造函数、赋值运算符重载以及析构函数**必须要显式给出**。一般情
> 况都是按照**深拷贝**方式提供。
>
> 【深拷贝】：**给每个对象独立分配资源**，保证多个对象之间不会因共享资源而造成多次释放而造成程序崩溃的问题
>
> ![image-20250416201200459](C:\Users\Aufire\AppData\Roaming\Typora\typora-user-images\image-20250416201200459.png)

#### 深拷贝的传统写法

```cpp
//深拷贝 - 传统写法
string(const string& s)
	:_str(new char[strlen(s._str) + 1])
{
	strcpy(_str, s._str);
}
//赋值 s1 = s2
string& operator=(const string& s)
{
	if (this != &s)//防止自己给自己赋值
	{
		char* tmp = new char[strlen(s._str) + 1];
		strcpy(tmp, s._str);//将s2拷贝给tmp
		delete[] _str;//释放原来s1的空间
		_str = tmp;//让_str(s1)指向tmp(s2),完成赋值
	}
	return *this;
}
```



#### 深拷贝的现代写法

```cpp
//深拷贝 - 现代写法  
//string s2(s1)
string(const string& s)
	:_str(nullptr)
{
	string tmp(s._str);
	swap(_str, tmp._str);
}

//s1 = s2
string& operator=(string s)//这个更简洁,更推荐用这个
{
	swap(_str, s._str);
	return *this;
}
    
string& operator=(const string& s)
{
	if (this != &s)
	{
		string tmp(s);//拷贝构造
		swap(_str, tmp._str);
	}
	return *this;
}

```

```cpp
//string s2(s1)
string(const string& s)
	:_str(nullptr)
	,_size(0)
	,_capacity(0)
{
	string tmp(s._str);
	this->swap(tmp);
    //实际上是这样写的: swap(tmp)
}
//s1.swap(s2)
void swap(string& s)
{
	::swap(_str, s._str);
	::swap(_size, s._size);
	::swap(_capacity, s._capacity);
	//::的意思是1. 避免与标准库的 std::swap 冲突   2. 强制使用全局函数,如果作用域有同名函数，优先使用这个函数
}

//s1 = s2
string& operator=(string s)
{
	this->swap(s);//this是string*,相当于调用自己的成员函数swap
    //实际上是这样写的: swap(s)
	return *this;
}
```

### 2.4string类的模拟实现

```C++
namespace bit
{
	class string
	{
	public:
		typedef char* iterator;
	public:
		string(const char* str = "")
		{
			_size = strlen(str);
			_capacity = _size;
			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}
		string(const string& s)
			: _str(nullptr)
			, _size(0)
			, _capacity(0)
		{
			string tmp(s._str);
			this->swap(tmp);
		}
		string& operator=(string s)
		{
			this->Swap(s)
			return *this;
		}
		~string()
		{
			if (_str)
			{
				delete[] _str;
				_str = nullptr;
			}
		}

		/////////////////////////////////////////////////////////////////
		// iterator
		iterator begin() { return _str; }
		iterator end() { return _str + _size; }

		/////////////////////////////////////////////////////////////////
		// modify
		void push_back(char c)
		{
			if (_size == _capacity)
				Reserve(_capacity * 2);
			_str[_size++] = c;
			_str[_size] = '\0';
		}
		string& operator+=(char c)
		{
			PushBack(c);
			return *this;
		}
		// 作业实现
		void append(const char* str);
		string& operator+=(const char* str);
		void clear()
		{
			_size = 0;
			_str[_size] = '\0';
		}
		void swap(string& s)
		{
			swap(_str, s._str);
			swap(_size, s._size);
			swap(_capacity, s._capacity);
		}
		const char* c_str()const
		{
			return _str;
		}
		/////////////////////////////////////////////////////////////////
		// capacity
		size_t size()const
			size_t capacity()const
			bool empty()const
			void resize(size_t newSize, char c = '\0')
		{
			if (newSize > _size)
			{
				// 如果newSize大于底层空间大小，则需要重新开辟空间
				if (newSize > _capacity)
				{
					Reserve(newSize);
				}
				memset(_str + _size, c, newSize - _size);
			}
			_size = newSize;
			_str[newSize] = '\0';
		}
		void reserve(size_t newCapacity)
		{
			// 如果新容量大于旧容量，则开辟空间
			if (newCapacity > _capacity)
			{
				char* str = new char[newCapacity + 1];
				strcpy(str, _str);
				// 释放原来旧空间,然后使用新空间
				delete[] _str;
				_str = str;
				_capacity = newCapacity;
			}
		}
		////////////////////////////////////////////////////////////////////
		// access
		char& operator[](size_t index)
		{
			assert(index < _size);
			return _str[index];
		}
		const char& operator[](size_t index)const
		{
			assert(index < _size);
			return _str[index];
		}
		////////////////////////////////////////////////////////////////////
		// 作业
		bool operator<(const string& s);
		bool operator<=(const string& s);
		bool operator>(const string& s);
		bool operator>=(const string& s);
		bool operator==(const string& s);
		bool operator!=(const string& s);
		// 返回c在string中第一次出现的位置
		size_t find(char c, size_t pos = 0) const;
		// 返回子串s在string中第一次出现的位置
		size_t find(const char* s, size_t pos = 0) const;
		// 在pos位置上插入字符c/字符串str，并返回该字符的位置
		string& insert(size_t pos, char c);
		string& insert(size_t pos, const char* str);
		// 删除pos位置上的元素，并返回该元素的下一个位置
		string& erase(size_t pos, size_t len);
private:
	friend ostream& operator<<(ostream& _cout, const bit::string& s);
	friend istream& operator>>(istream& _cin, bit::string& s);
private:
	char* _str;
	size_t _capacity;
	size_t _size;
	};
}
ostream& bit::operator<<(ostream& _cout, const bit::string& s)
{
	// 不能使用这个
	//cout << s._str;
	for (size_t i = 0; i < s.size(); ++i)
	{
		_cout << s[i];
	}
	return _cout;
}
///////对自定义的string类进行测试
void TestBitstring()
{
	bit::string s1("hello");
	s1.push_back(' ');
	s1.push_back('b');
	s1.append(1, 'i');
	s1 += 't';
	cout << s1 << endl;
	cout << s1.size() << endl;
	cout << s1.capacity() << endl;
	// 利用迭代器打印string中的元素
	string::iterator it = s1.begin();
	while (it != s1.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
	// 这里可以看到一个类只要支持的基本的iterator，就支持范围for
	for (auto ch : s1)
		cout << ch << " ";
	cout << endl;
}
```



## 3.扩展阅读 