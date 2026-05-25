# C++题库

## 求1+2+3+...+n

> 要求不能使用乘法、for、while 、if、else、switch、case等关键词以及条件判断语句(A ? B ：C)、也不能用递归

```cpp
#include<iostream>
using namespace std;
class Sum
{
public:
	Sum()
	{
		//每次进来构造都会加上i,然后i++,一直到n
		_sum += _i;
		_i++;
	}
	static void Init() //这里设置成static,如果不设置成静态成员函数,调用的时候会调用构造函数，会出错
	{
		_i = 1;
		_sum = 0;
	}
	static int GetSum()
	{
		return _sum;
	}
private:
	//静态成员变量，类似于全局变量，全局都是同一个_i和_sum
	static int _i;
	static int _sum;
};
//静态成员变量在类外初始化
int Sum::_i = 1;
int Sum::_sum = 0;

class Solution
{
public:
	int Sum_Solution(int n)
	{
		//Sum a[n];//C98变长数组
		//构造一个数组，数组里面有n个元素，就会构造n次

		Sum::Init();//之间调用函数，不用通过对象来调用,通过对象来调用会调用到构造函数,从而导致问题的出现

		Sum* p = new Sum[n];	
		return Sum::GetSum();//因为_sum是私有的，需要通过调用成员函数来进行访问
	}
};
int main()
{
	Solution Sum;
	cout << Sum.Sum_Solution(5) << endl;
	cout << Sum.Sum_Solution(6) << endl;
	return 0;
}
```

## **计算日期到天数转换**

> 输出一个整数，代表输入的日期是这一年的第几天。

```CPP
#include <iostream>
using namespace std;

class Date 
{
    friend int calculateDayOfYear(const Date& date);
    friend istream& operator>>(istream& _cin, Date& d);
public:
    Date(int year = 0, int month = 1, int day = 1)
        : _year(year),
          _month(month),
          _day(day)
    {}
private:
    int _year;
    int _month;
    int _day;
};

int calculateDayOfYear(const Date& d)
{
    int months[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };//每个月的天数
    bool isLeap = (d._year % 4 == 0 && d._year % 100 != 0) || (d._year % 400 == 0);//判断是否是闰年
    if (isLeap) 
    {
        months[2] = 29;
    }

    int totalDays = 0;
    for (int i = 1; i < d._month; ++i)//从1月到输入的月份
    {
        totalDays += months[i];
    }
    totalDays += d._day;//最后再加上输入的当月的天数

    return totalDays;
}
istream& operator>>(istream& _cin, Date& d)//不用const，否则就不能输入来改变了
{
    _cin >> d._year;//空格或者是换行都可以依次输入
    _cin >> d._month;
    _cin >> d._day;
    return _cin;
}
int main() 
{
    //int year, month, day;
    //cin >> year >> month >> day;
    //Date d(year, month, day);
    ////输入也可以用元友输入函数来实现
    Date d;
    cin >> d;

    cout << calculateDayOfYear(d) << endl;
    return 0;
}
```

**更简单的方法:**

```cpp

```



## 日期差值

> 有两个日期，求两个日期之间的天数，如果两个日期是连续的我们规定他们之间的天数为两天

```cpp
//日期差值
#include <iostream>
#include <string>
#include <cmath>

class Date 
{
private:
    int year;
    int month;
    int day;

    static const int months_days[13]; // 每月天数表

public:
    // 构造函数：解析字符串格式为YYYYMMDD
    Date(const std::string& date_str) 
    {
        year = std::stoi(date_str.substr(0, 4));//stoi函数用于将字符串转换为整型，头文件是#include <string>
        month = std::stoi(date_str.substr(4, 2));
        day = std::stoi(date_str.substr(6, 2));
    }

    // 计算该日期到基准日期的总天数
    int to_days() const 
    {
        int total = 0;
        // 累加年份天数
        for (int y = 1; y < year; ++y)
        {
            total += is_leap(y) ? 366 : 365;//如果是闰年，一年就是366天
        }
        // 累加月份天数
        for (int m = 1; m < month; ++m)
        {
            if (m == 2 && is_leap(year)) 
            {
                total += 29;
            }
            else
            {
                total += months_days[m];
            }
        }
        // 累加日
        total += day;
        return total;
    }

    // 计算与另一个日期的差值（包含两端）
    int days_diff(const Date& other) const
    {
        return std::abs(this->to_days() - other.to_days()) + 1;
    }

    // 静态方法：判断闰年
    static bool is_leap(int year)
    {
        return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
    }
};

// 初始化静态成员：每月天数（非闰年）
const int Date::months_days[13] = { 0,31, 28, 31, 30, 31, 30,31, 31, 30, 31, 30, 31 };

int main()
{
    std::string date1_str, date2_str;
    std::getline(std::cin, date1_str);
    std::getline(std::cin, date2_str);

    Date date1(date1_str);  // 创建日期对象
    Date date2(date2_str);

    std::cout << date1.days_diff(date2) << std::endl;

    return 0;
}
```

## 构造和析构顺序

![image-20250311091417391](C:\Users\Aufire\AppData\Roaming\Typora\typora-user-images\image-20250311091417391.png)

**构造：**局部的静态对象，第一次进来的时候才初始化， 

**析构：**局部对象先析构，全局对象和静态对象再析构，D又是局部的，所以先D后C（**后定义先析构**）

## 求拷贝构造的次数

![image-20250311094208095](C:\Users\Aufire\AppData\Roaming\Typora\typora-user-images\image-20250311094208095.png)

## 仅仅反转字母

> **利用字符下标**
>
> ![image-20250325211618420](C:\Users\Aufire\AppData\Roaming\Typora\typora-user-images\image-20250325211618420.png)

```cpp
class Solution {
public:
    bool IsChar(char ch)
    {
        if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))//判断是否是字符
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    string reverseOnlyLetters(string s)
    {
        int begin = 0;
        int end = s.size() - 1;
        while(begin < end)
        {
            while(begin < end && IsChar(s[begin]) == false)//这里只有判断不是字符后才向后或者向前进
            {
                begin++;
            }
            while(begin < end && IsChar(s[end]) == false)
            {
                end--;
            }
            swap(s[begin],s[end]);
            begin++;//所以这里交换后要手动进一位或者减一位
            end--;
        }

        return s;
    }
};
```

## 字符中的第一个唯一字符(利用映射)

> 给定一个字符串 `s` ，找到 *它的第一个不重复的字符，并返回它的索引(下标)* 。如果不存在，则返回 `-1`

```cpp
class Solution
 {
public:
    int firstUniqChar(string s) 
    {
        int count[26] = {0};//26个字母
        for(auto ch : s)
        {
            count[ch - 'a']++;//每个字符（ch）通过 ch - 'a' 转换为 0-25 的索引，对应 26 个小写字母。
        }

        for(size_t i = 0;i < s.size();i++)
        {
            if(count[s[i] - 'a'] == 1)//通过s[i] - 'a'找到对应s[i]的字符的索引，判断其是否出现过
            {
                return i;//如果只出现一次，则返回该字符的下标
            }
        }

        return -1;//字符串检索完之后,如果没有唯一出现过一次的字符，就返回-1
    }
};
```

## 找出字符串中第一个匹配项的下标

> 给你两个字符串 `haystack` 和 `needle` ，请你在 `haystack` 字符串中找出 `needle` 字符串的第一个匹配项的下标（下标从 0 开始）。如果 `needle` 不是 `haystack` 的一部分，则返回 `-1` 。

```CPP
class Solution {
public:
    int strStr(string haystack, string needle) 
    {
        int n = haystack.size();
        int m = needle.size();
        
        if(m == 0)
        return 0;//needle为空字符串的特殊情况

        if(n < m)
        return -1;//haystack比needle短，无法匹配
        
        for(size_t i = 0;i <= n - m;i++)//遍历所有可能的起始位置(除去needle的字符个数后第一个字符可能出现的位置)
        {
            bool found = true;//默认匹配
            for(size_t j = 0;j < m;j++)//遍历needle
            {
                if(haystack[i + j] != needle[j])//haystack[i + j]即从开始匹配的位置(i)后的第j个字符(对应needle的第j个字符)
                {
                    found = false;//这里不能直接return false,因为false的本质是0
                    break;
                }
            }
            if(found)//如果遍历完needle后，如果还匹配的话，就是匹配了
            {
                return i;
            }
        }
        return -1;
    }
};
```

## 实部和虚部

> 定义一个复数类 Complex，满足以下要求：
>
> 1. 包含两个私有成员变量 real 和 imag，分别表示复数的实部和虚部。
> 2. 提供一个构造函数，用于初始化复数的实部和虚部。
> 3. 重载 + 运算符，实现两个复数相加。
> 4. 重载 - 运算符，实现两个复数相减。
> 5. 重载 << 运算符，使其可以直接输出复数的信息（格式：实部 + 虚部 i 或 实部 - 虚部 i）。（**利用友元**）

```cpp
#include<iostream>
using namespace std;
class Complex
{
private:
	int _real;
	int _imag;
public:
	Complex(int real = 0, int imag = 0)
		:_real(real)
		,_imag(imag)
	{}
	Complex operator+(const Complex& a)
	{
		return Complex(_real + a._real, _imag + a._imag);
	}
	Complex operator-(const Complex& a)
	{
		return Complex(_real - a._real, _imag - a._imag);
	}
	//输出运算符(利用友元函数)
	friend ostream& operator<<(ostream& _cout,const Complex& _c);
};
ostream& operator<<(ostream& _cout,const Complex& _c)
{
	if (_c._imag == 0)//虚部为0
	{
		_cout << _c._real;
	}
	else if (_c._real == 0)//实部为0
	{
		_cout << _c._imag << "i";
	}
	else//两个都不为0
	{
		_cout << _c._real;
		if (_c._imag > 0) 
		{
			_cout << " + " << _c._imag << "i";
		}
		else 
		{
			_cout << " - " << -_c._imag << "i";
		}
	}
	return _cout;
}
int main()
{
	Complex a (2, -2);
	Complex b (1, -2);
	cout << a << endl;
	cout << a + b << endl;//要用const修饰
	cout << a - b << endl;
	return 0;
}

```

## 分离网址的协议、域名、资源名称

```cpp
#include<iostream>
using namespace std;
void split_url(const string& url)
{
	//分离url
	//分离出协议，域名，资源名称
	//https://legacy.cplusplus.com/reference/string/string/substr/
	//https://www.baidu.com/index.php?tn=68018901_58_oem_dg

	//协议
	size_t i1 = url.find(':');
	if (i1 != string::npos)
	{
		cout << url.substr(0, i1) << endl;//从第一个位置开始，i1是字符':'的下标为4，又因为刚好找四个字符
	}

	//域名
	size_t i2 = url.find('/', i1 + 3);//从i1 + 3的位置(w)开始找，找到字符'/'
	if (i2 != string::npos)
	{
		cout << url.substr(i1 + 3, i2 - (i1 + 3)) << endl;//从w开始，取w和i2之间的字符
	}

	//资源名称
	cout << url.substr(i2) << endl;//从i2的位置开始，一直找到最后
}
int main()
{
	string cpp("https://legacy.cplusplus.com/reference/string/string/substr/");
	string bd("https://www.baidu.com/index.php?tn=68018901_58_oem_dg");


	split_url(cpp);
	split_url(bd);
	return 0;
}
```

## 求字符串最后一个单词的长度

> ![image-20250403084514221](C:\Users\Aufire\AppData\Roaming\Typora\typora-user-images\image-20250403084514221.png)

```cpp
#include<iostream>
#include<string>
using namespace std;
int main()
{
    string s;
    //cin >> s; //读到换行或者空格就结束

    getline(cin, s);//读到换行才结束

    size_t pos = s.rfind(' ');
    cout << s.size() - (pos + 1) << endl;

    return 0;
}
```

## 验证一个字符串是否回文

> 全部转换成小写再去判断

```cpp
class Solution {
public:
    bool isCharOrNum(char ch)
    {
        if ((ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9'))
            return true;
        else
            return false;
    }
    bool isPalindrome(string s)
    {
        //将字符全部转换成小写
        for (auto& ch : s)
        {
            if (ch >= 'A' && ch <= 'Z')
            {
                ch += 32;
            }
        }
        int begin = 0, end = s.size() - 1;
        while (begin < end)
        {
            while(begin < end && !isCharOrNum(s[begin]))//如果begin小于end，就一直找，直到找到s[begin]为字符或者数字的时候
                begin++;
            while(begin < end && !isCharOrNum(s[end]))//同上
                end--;
            if (s[begin] != s[end])
            {
                return false;
            }
            else
            {
                begin++;
                end--;
            }
        }
        return true;
    }
};
int main()
{
    Solution s;
    cout << s.isPalindrome("A man, a plan, a canal: Panama") << endl;

    return 0;
}
```

## 字符串相加

> ![image-20250403111804625](C:\Users\Aufire\AppData\Roaming\Typora\typora-user-images\image-20250403111804625.png)

```cpp
class Solution 
{
public:
    string addStrings(string num1, string num2)
    {
        //从后往前面加，相加得到的字符可以尾插之后再用reverse逆置
        int end1 = num1.size() - 1;
        int end2 = num2.size() - 1;
        int val1 = 0,val2 = 0,next = 0;
        string addret;
        while(end1 >= 0 || end2 >= 0)//'||'表示只要有一个没有结束就还要继续加
        {
            if(end1 >= 0)
            {
                val1 = num1[end1] - '0';//减去字符0，得到数值
                end1--;
            }
            else
            {
                val1 = 0;
            }
            if(end2 >= 0)
            {
                val2 = num2[end2] - '0';
                end2--;
            }
            else
            {
                val2 = 0;
            }
            int ret = val1 + val2 + next;
            if(ret > 9 )
            {
                next = 1;
                ret -= 10;
            }
            else
            {
                next = 0;
            }
            //将数值变成字符串
            addret += (ret + '0');//尾插
        }
        if(next == 1)
            {
                addret += '1';
            }
            reverse(addret.begin(),addret.end());
            return addret;
    }
};
```

## 字符串相乘

```cpp
class Solution 
{
public:
    string addStrings(string num1, string num2)
    {
        //从后往前面加，相加得到的字符可以尾插之后再用reverse逆置
        int end1 = num1.size() - 1;
        int end2 = num2.size() - 1;
        int val1 = 0,val2 = 0,next = 0;
        string addret;
        while(end1 >= 0 || end2 >= 0)//'||'表示只要有一个没有结束就还要继续加
        {
            if(end1 >= 0)
            {
                val1 = num1[end1] - '0';//减去字符0，得到数值
                end1--;
            }
            else
            {
                val1 = 0;
            }
            if(end2 >= 0)
            {
                val2 = num2[end2] - '0';
                end2--;
            }
            else
            {
                val2 = 0;
            }
            int ret = val1 + val2 + next;
            if(ret > 9 )
            {
                next = 1;
                ret -= 10;
            }
            else
            {
                next = 0;
            }
            //将数值变成字符串
            addret += (ret + '0');//尾插
        }
        if(next == 1)
            {
                addret += '1';
            }
            reverse(addret.begin(),addret.end());
            return addret;
    }
    string multiply(string num1, string num2)
    {
       string i("0");
       string one("1");
       string ret("0");
       while(i != num1)
       {
           //将乘法变成加法，将num2加num1次
        ret = addStrings(ret,num2);
        i = addStrings(i,one);
       }
       return ret;
    }
};
```

