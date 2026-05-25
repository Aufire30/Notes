# Html基础

## h1

![image-20251113203855939](C:\Users\Aufire\AppData\Roaming\Typora\typora-user-images\image-20251113203855939.png)

## p

![image-20251113203901567](C:\Users\Aufire\AppData\Roaming\Typora\typora-user-images\image-20251113203901567.png)

## a

![image-20251113203908867](C:\Users\Aufire\AppData\Roaming\Typora\typora-user-images\image-20251113203908867.png)

> **在新标签页打开所跳转的网页**
>
> **target**属性规定了在何处打开超链接。
>
> 例如:
>
> ```html
> <a href = "http://bilibili.com" target = "_blank">小破站</a>
> ```

> **发送电子邮件**
>
> 将href属性值设置为**mailto:**邮箱地址，这样做可以调起邮箱应用，发送邮件到对应地址。
>
> 例如：
>
> ```html
> <p>发送邮件到：<a href="mailto:someone@email.com">someone</a>
> ```



## img

![image-20251113203915681](C:\Users\Aufire\AppData\Roaming\Typora\typora-user-images\image-20251113203915681.png)

# span

> 内联函数，在显示时通常不会以新行开始。
>
> 可用于**为部分文本设置样式属性**(style)

![image-20251124165256947](C:\Users\Aufire\AppData\Roaming\Typora\typora-user-images\image-20251124165256947.png)

![image-20251124165307366](C:\Users\Aufire\AppData\Roaming\Typora\typora-user-images\image-20251124165307366.png)

# br

> 一个简单的换行符

![image-20251124165417624](C:\Users\Aufire\AppData\Roaming\Typora\typora-user-images\image-20251124165417624.png)

![image-20251124165424533](C:\Users\Aufire\AppData\Roaming\Typora\typora-user-images\image-20251124165424533.png)

# pre

> 用于定义**预格式化文本**
>
> 预格式化文本：保留文本在源代码中的格式，使得页面中显示的和源代码中的效果完全一致
>
> (HTML要求浏览器将连续的空白字符合并成一个空格，所以即便是多个空格，在页面中也只会显示一个空格)

## HTML字符实体

> 在HTML文档中，某些字符是预留的，有特殊的含义，如<>，浏览器会误认为是标签，所以不能用来表示大于或者小于号

![image-20251124170251320](C:\Users\Aufire\AppData\Roaming\Typora\typora-user-images\image-20251124170251320.png)

![image-20251124170404540](C:\Users\Aufire\AppData\Roaming\Typora\typora-user-images\image-20251124170404540.png)

> 以上等字符如果想在HTML中正确显示，需要利用它的实体编号
>
> ![image-20251124170457102](C:\Users\Aufire\AppData\Roaming\Typora\typora-user-images\image-20251124170457102.png)	
>
> ![image-20251124170509489](C:\Users\Aufire\AppData\Roaming\Typora\typora-user-images\image-20251124170509489.png)
>
> ![image-20251124170532367](C:\Users\Aufire\AppData\Roaming\Typora\typora-user-images\image-20251124170532367.png)

## code

> 这是更适合展示源码的一个标签
>
> ![image-20251124171018958](C:\Users\Aufire\AppData\Roaming\Typora\typora-user-images\image-20251124171018958.png)
>
> ![image-20251124171028941](C:\Users\Aufire\AppData\Roaming\Typora\typora-user-images\image-20251124171028941.png)
>
> 如果有很多代码，可以在pre里面内嵌code
>
> ![image-20251124171103572](C:\Users\Aufire\AppData\Roaming\Typora\typora-user-images\image-20251124171103572.png)

# var、kbd、samp

> var:定义程序的变量
>
> kbd:定义用户的输入
>
> samp:定义程序的输出

![image-20251124171936438](C:\Users\Aufire\AppData\Roaming\Typora\typora-user-images\image-20251124171936438.png)

# meta

## meta解决乱码问题

![image-20251111201702702](C:\Users\Aufire\AppData\Roaming\Typora\typora-user-images\image-20251111201702702.png)

![image-20251111201721781](C:\Users\Aufire\AppData\Roaming\Typora\typora-user-images\image-20251111201721781.png)

在**头部(head)**添加

## 实现网页尺寸自适应

![image-20251111202040522](C:\Users\Aufire\AppData\Roaming\Typora\typora-user-images\image-20251111202040522.png)

## 搜索引擎优化

**例如：**

![image-20251111202707075](C:\Users\Aufire\AppData\Roaming\Typora\typora-user-images\image-20251111202707075.png)

还可以添加关键词、作者等重要摘要

![image-20251111202615153](C:\Users\Aufire\AppData\Roaming\Typora\typora-user-images\image-20251111202615153.png)

## 自动刷新后跳转到新页面

![image-20251111202940397](C:\Users\Aufire\AppData\Roaming\Typora\typora-user-images\image-20251111202940397.png)

content为多少秒后刷新进入新的网站

# style

## 给相关内容添加样式

![image-20251111203547604](C:\Users\Aufire\AppData\Roaming\Typora\typora-user-images\image-20251111203547604.png)

![image-20251111203600454](C:\Users\Aufire\AppData\Roaming\Typora\typora-user-images\image-20251111203600454.png)

![image-20251111204504173](C:\Users\Aufire\AppData\Roaming\Typora\typora-user-images\image-20251111204504173.png)

## media

### 打印模式

![image-20251111204932271](C:\Users\Aufire\AppData\Roaming\Typora\typora-user-images\image-20251111204932271.png)

### 网页尺寸

> 调整网页在浏览器的尺寸范围

![image-20251111205332677](C:\Users\Aufire\AppData\Roaming\Typora\typora-user-images\image-20251111205332677.png)

在屏幕中的网页尺寸为512像素到1024像素之间，会显示bc2.png这张图片，如果不满足其中一个条件，就会恢复成一开始的样子



# link

![image-20251113202239297](C:\Users\Aufire\AppData\Roaming\Typora\typora-user-images\image-20251113202239297.png)

![image-20251113202255713](C:\Users\Aufire\AppData\Roaming\Typora\typora-user-images\image-20251113202255713.png)

![image-20251113202401379](C:\Users\Aufire\AppData\Roaming\Typora\typora-user-images\image-20251113202401379.png)

**将style样式相关的body代码单独保存为.css文件，运用link链接，使得html代码不这么冗余**

## 为网页标题的左侧添加小图标

![image-20251113202850242](C:\Users\Aufire\AppData\Roaming\Typora\typora-user-images\image-20251113202850242.png)

![image-20251113202929180](C:\Users\Aufire\AppData\Roaming\Typora\typora-user-images\image-20251113202929180.png)

使用rel的icon

# base

![image-20251113203339242](C:\Users\Aufire\AppData\Roaming\Typora\typora-user-images\image-20251113203339242.png)

![image-20251113203519959](C:\Users\Aufire\AppData\Roaming\Typora\typora-user-images\image-20251113203519959.png)

就相当于url只用在最前面指定一次，后面的test1、test2、test3直接加在base的url后面，从而实现**绝对路径**



# 注释

## HTML的注释

> <!-- 在此添加要注释的内容 -->

## CSS的注释

> /* 在此添加要注释的内容 */

## javascript的注释

> // 单行的注释
>
> 
>
> /*
>
> ​	多行的
>
> ​	注释
>
> */

# 引用

## q

> 用于较短的引用
>
> ![image-20251124172212241](C:\Users\Aufire\AppData\Roaming\Typora\typora-user-images\image-20251124172212241.png)
>
> ![image-20251124172220910](C:\Users\Aufire\AppData\Roaming\Typora\typora-user-images\image-20251124172220910.png)
>
> 浏览器默认加上一对双引号

## blockquote

> 用于引用一大段文本
>
> 使用缩进的形式来区分
>
> ![image-20251124172458850](C:\Users\Aufire\AppData\Roaming\Typora\typora-user-images\image-20251124172458850.png)
>
> ![image-20251124172512577](C:\Users\Aufire\AppData\Roaming\Typora\typora-user-images\image-20251124172512577.png)
>
> 

> 可以用cite属性来指定引用的来源
>
> ![image-20251124172316700](C:\Users\Aufire\AppData\Roaming\Typora\typora-user-images\image-20251124172316700.png)

## cite

> 主要用于定义作品的标题，默认样式是斜体

![image-20251124173119765](C:\Users\Aufire\AppData\Roaming\Typora\typora-user-images\image-20251124173119765.png)

![image-20251124173134859](C:\Users\Aufire\AppData\Roaming\Typora\typora-user-images\image-20251124173134859.png)

## abbr

> 用于定义简称、缩写，配合全局属性title可以解释该缩写的含义 

![image-20251124173428481](C:\Users\Aufire\AppData\Roaming\Typora\typora-user-images\image-20251124173428481.png)

![image-20251124173435461](C:\Users\Aufire\AppData\Roaming\Typora\typora-user-images\image-20251124173435461.png)

## dfn

> 表示一些专业术语，默认样式是斜体，可以配合addr缩写使用

![image-20251124173722891](C:\Users\Aufire\AppData\Roaming\Typora\typora-user-images\image-20251124173722891.png)

![image-20251124173743594](C:\Users\Aufire\AppData\Roaming\Typora\typora-user-images\image-20251124173743594.png)

![image-20251124173809092](C:\Users\Aufire\AppData\Roaming\Typora\typora-user-images\image-20251124173809092.png)

![image-20251124173815824](C:\Users\Aufire\AppData\Roaming\Typora\typora-user-images\image-20251124173815824.png)

## address

> 定义文档或文章的联系信息（作者/拥有者）
>
> 此元素通常以***斜体***显示。大多数浏览器会在此元素前后添加折行。

![image-20251124173959081](C:\Users\Aufire\AppData\Roaming\Typora\typora-user-images\image-20251124173959081.png)

![image-20251124174007359](C:\Users\Aufire\AppData\Roaming\Typora\typora-user-images\image-20251124174007359.png)

## ruby、rt、rp

> 用于对一些生僻词添加拼音注释

![image-20251124174143043](C:\Users\Aufire\AppData\Roaming\Typora\typora-user-images\image-20251124174143043.png)

![image-20251124174225818](C:\Users\Aufire\AppData\Roaming\Typora\typora-user-images\image-20251124174225818.png)

## bdo

> 可以指定文本**从左往右(ltr)**开始显示或者**从右往左(rtl)**

![image-20251124174507787](C:\Users\Aufire\AppData\Roaming\Typora\typora-user-images\image-20251124174507787.png)

![image-20251124174512816](C:\Users\Aufire\AppData\Roaming\Typora\typora-user-images\image-20251124174512816.png)



# 列表

## 无序列表

> ul
>
> ![image-20251208164634380](C:\Users\Aufire\AppData\Roaming\Typora\typora-user-images\image-20251208164634380.png)
>
> ![image-20251208164652354](C:\Users\Aufire\AppData\Roaming\Typora\typora-user-images\image-20251208164652354.png)

## 有序列表

> ol
>
> ![image-20251208164748559](C:\Users\Aufire\AppData\Roaming\Typora\typora-user-images\image-20251208164748559.png)
>
> ![image-20251208164804019](C:\Users\Aufire\AppData\Roaming\Typora\typora-user-images\image-20251208164804019.png)
>
> ![image-20251208164848663](C:\Users\Aufire\AppData\Roaming\Typora\typora-user-images\image-20251208164848663.png)

## 定义列表

> dl、dt、dd
>
> ![image-20251208165539215](C:\Users\Aufire\AppData\Roaming\Typora\typora-user-images\image-20251208165539215.png)
>
> ![image-20251208165545531](C:\Users\Aufire\AppData\Roaming\Typora\typora-user-images\image-20251208165545531.png)

# 表格

## 表格的边框属性

> 默认的表格是没有边框的
>
> 想给表格加上边框有两种方式
>
> 1.使用边框属性来显示一个带有边框的表格：
>
> ```html
> <table border = "1">
> 
> </table>
> ```
>
> 2.使用css样式
>
> ```html
> <style>
> 	table
>     {
> 		border: 1px;
>     }
> </style>
> ```
>
> 正常的表格是“买一送一的”，是一个双线框
>
> ![image-20251208171351198](C:\Users\Aufire\AppData\Roaming\Typora\typora-user-images\image-20251208171351198.png)
>
> 为了把双线框变成单线框，我们可以使用css样式里面的**border-collapse**属性来设置
>
> ```html
> <style>
> 	table
>     {
> 		border: 1px;
> 		border-collapse: collapse;
>     }
> </style>
> ```
>
> ![image-20251208171332555](C:\Users\Aufire\AppData\Roaming\Typora\typora-user-images\image-20251208171332555.png)

## 表格

> 每个表格有若干行，用**tr(table row)**表示
>
> 每行被分割成若干单元格，用**td(table data)**表示
>
> ![image-20251208170736500](C:\Users\Aufire\AppData\Roaming\Typora\typora-user-images\image-20251208170736500.png)

## 表头

> 表格的表头用**th**表示
>
> 默认样式为粗体居中
>
> ![image-20251208170826259](C:\Users\Aufire\AppData\Roaming\Typora\typora-user-images\image-20251208170826259.png)

## 空单元格

> 在空单元格中添加一个空格占位符
>
> ![image-20251208170949590](C:\Users\Aufire\AppData\Roaming\Typora\typora-user-images\image-20251208170949590.png)

## thead和tbody

> 将表格划分得更细致，以便于对不同的部分进行更细致的设置

## tfoot

> 表脚，用于添加一些注释说明
>
> 一般搭配**colspan**属性来使用，用于设置单元格**横跨的列数**
>
> **rowspan**：用于**跨行**

## colgroup

> 用于批量设置一列或者多列的样式
>
> ![image-20251208172518350](C:\Users\Aufire\AppData\Roaming\Typora\typora-user-images\image-20251208172518350.png)
>
> ![image-20251208172525529](C:\Users\Aufire\AppData\Roaming\Typora\typora-user-images\image-20251208172525529.png)

# 表单

## form

> `<form>` 标签用于为用户输入创建 HTML 表单。用于向服务器传输数据。
>
> | 属性   | 值        | 描述                                  |
> | ------ | --------- | ------------------------------------- |
> | method | get、post | 规定用于发送 form-data 的 HTTP 方法。 |
> | action | URL       | 规定当提交表单时向何处发送表单数据。  |
>
> get方式提交会**在url中显示提交的内容**，post方式提交则不会

## button

> `<button>` 标签用于定义一个按钮。
>
> 属性：
>
> | 属性 | 值                    | 描述             |
> | ---- | --------------------- | ---------------- |
> | type | button、reset、submit | 指定按钮的类型。 |
>
> button表示**这就是一个按钮而已**
>
> reset表示点击这个按钮会**重写**
>
> submit表示点击这个按钮就会**提交**

## input

> `<input>` 标签用于搜集用户信息。
>
> 
>
> ```html
> 名字：<input type="text" name="name"><br><br>
> 邮箱：<input type="text" name="email"><br><br>
> ```
>
> `<br>标签是 HTML 的换行标签，它的作用是在文本或内容中强制插入一个换行,这样就在两个输入项之间创建了明显的垂直间距，使得表单在页面上看起来更清晰、更易填写`
>
> ![image-20251208175634479](C:\Users\Aufire\AppData\Roaming\Typora\typora-user-images\image-20251208175634479.png)
>
> | 属性         | 值                                                           | 描述                                                         |
> | ------------ | ------------------------------------------------------------ | ------------------------------------------------------------ |
> | autocomplete | on、off                                                      | 指定是否启用浏览器预测输入                                   |
> | autofocus    | autofocus                                                    | 指定是否自动获得焦点                                         |
> | formtarget   | _blank、_self、_parent、_top、framename                      | 指定表单提交后在何处打开 action URL（只能作用于具有提交性质的按钮，比如 type="submit" 或 type="image"） |
> | readonly     | readonly                                                     | 将文本框设为只读模式，防止用户编辑其内容                     |
> | disabled     | disabled                                                     | 指定是否禁用该 input 元素                                    |
> | type         | button、checkbox、color、date、datetime-local、email、file、hidden、image、month、number、password、radio、range、reset、search、submit、tel、text、time、url、week | 规定 input 元素的类型                                        |
> | value        | text                                                         | 指定输入字段的初始值                                         |
> | checked      | checked                                                      | 指定该属性的复选框，默认显示为勾选状态                       |
> | max          | number、date                                                 | 指定可接受的最大值，以便进行输入验证                         |
> | maxlength    | number                                                       | 指定用户可以在文本框输入的最大字符数                         |
> | min          | number、date                                                 | 指定可接受的最小值，以便进行输入验证                         |
> | multiple     | multiple                                                     | 指定该属性后可以上传多个文件                                 |
> | name         | field_name                                                   | 指定元素的名称，用于在 JavaScript 中引用元素，或者在表单提交后引用表单数据，只有设置了 name 属性的表单才能在提交表单时传递该值 |
> | pattern      | regexp_pattern                                               | 指定一个用于输入验证的正则表达式                             |
> | required     | required                                                     | 表明用户必须输入一个值，否则无法通过输入验证                 |
> | size         | number_of_char                                               | 指定文本框的宽度                                             |
> | list         | datalist-id                                                  | 指定一个数据列表，即 datalist 元素的 id 值                   |
>
> readonly和disable的区别：两个都不可修改，但是readonly会提交给服务器，但是disable是将这个数据相当于销毁，不会提交给服务器
>
> | type属性                                                     | 描述                                 |
> | ------------------------------------------------------------ | ------------------------------------ |
> | value                                                        | 描述                                 |
> | [button](https://man.ilovefishc.com/pageHTML5/input.html#bt1) | 按钮                                 |
> | [checkbox](https://man.ilovefishc.com/pageHTML5/input.html#bt2) | 多选框                               |
> | [color](https://man.ilovefishc.com/pageHTML5/input.html#bt3) | 颜色盘                               |
> | [date](https://man.ilovefishc.com/pageHTML5/input.html#bt4)  | 时间日历（年，月，日（没有时间））   |
> | [datetime-local](https://man.ilovefishc.com/pageHTML5/input.html#bt5) | 本地时间日历 年，月，日，时间）      |
> | [email](https://man.ilovefishc.com/pageHTML5/input.html#bt6) | 邮箱地址栏                           |
> | [file](https://man.ilovefishc.com/pageHTML5/input.html#bt7)  | 上传文件栏                           |
> | [hidden](https://man.ilovefishc.com/pageHTML5/input.html#bt8) | 隐藏                                 |
> | [image](https://man.ilovefishc.com/pageHTML5/input.html#bt9) | 图片                                 |
> | [month](https://man.ilovefishc.com/pageHTML5/input.html#bt10) | 日历栏（年，月）                     |
> | [number](https://man.ilovefishc.com/pageHTML5/input.html#bt11) | 数字栏                               |
> | [password](https://man.ilovefishc.com/pageHTML5/input.html#bt12) | 密码栏                               |
> | [radio](https://man.ilovefishc.com/pageHTML5/input.html#bt13) | 单选栏(name属性一致可以实现互斥选项) |
> | [range](https://man.ilovefishc.com/pageHTML5/input.html#bt14) | 滑块栏                               |
> | [reset](https://man.ilovefishc.com/pageHTML5/input.html#bt15) | 重置按钮                             |
> | [search](https://man.ilovefishc.com/pageHTML5/input.html#bt16) | 搜索字段（比如站内搜索或谷歌搜索等） |
> | [submit](https://man.ilovefishc.com/pageHTML5/input.html#bt17) | 提交按钮                             |
> | [tel](https://man.ilovefishc.com/pageHTML5/input.html#bt18)  | 输入电话号码的字段                   |
> | [text](https://man.ilovefishc.com/pageHTML5/input.html#bt19) | 默认.输入单行文本字段                |
> | [time](https://man.ilovefishc.com/pageHTML5/input.html#bt20) | 时间栏                               |
> | [url](https://man.ilovefishc.com/pageHTML5/input.html#bt21)  | 输入URL字段                          |
> | [week](https://man.ilovefishc.com/pageHTML5/input.html#bt22) | 周年栏                               |
>
> 

## fieldset

> `<fieldset>` 标签将表单内容的一部分打包，生成一组相关表单的字段。
>
> 当一组表单元素放到 `<fieldset>` 标签内时，浏览器会以特殊方式来显示它们，它们可能有**特殊的边界**、3D 效果，或者甚至可创建一个子表单来处理这些元素。
>
> ```html
>  <fieldset>
>     <legend>健康信息</legend>
>      身高：<input type="text" />
>      体重：<input type="text" />
> </fieldset>
> ```
>
> `<legend>` 标签用于为 [fieldset](https://man.ilovefishc.com/pageHTML5/fieldset.html) 元素定义说明文字。
>
> **注意：legend 元素必须是 [fieldset](https://man.ilovefishc.com/pageHTML5/fieldset.html) 元素的第一个子元素。**
>
> ![image-20251210164825573](C:\Users\Aufire\AppData\Roaming\Typora\typora-user-images\image-20251210164825573.png)
>
> ![image-20251210164841595](C:\Users\Aufire\AppData\Roaming\Typora\typora-user-images\image-20251210164841595.png)

## select

> `<select>` 标签用于创建单选或多选下拉列表菜单
>
> select 元素中的 [`option`](https://man.ilovefishc.com/pageHTML5/option.html) 标签用于定义列表中的可用选项。
>
> ```html
> <select>
>        <option>鱼C</option>
>        <option>FishC</option>
>        <option>Web课程</option>
>        <option>Python课程</option>
> </select>
> ```
>
> ![image-20251210165427063](C:\Users\Aufire\AppData\Roaming\Typora\typora-user-images\image-20251210165427063.png)

## optgroup

> `<optgroup>` 标签用于为下拉列表的选项进行分组。
>
> ```html
>  <select>
>         <optgroup label="零基础入门学习Web（Html5+Css3）">
>             <option value="H5001">第一讲</option>
>             <option value="H5002">第二讲</option>
>         </optgroup>
>         <optgroup label="零基础入门学习Web（JavaScript）">
>             <option value="JS001">第一讲</option>
>             <option value="JS002">第二讲</option>
>         </optgroup>
>  </select>
> ```
>
> `<lable>`可以指定该分组的标签
>
> ![image-20251210165757546](C:\Users\Aufire\AppData\Roaming\Typora\typora-user-images\image-20251210165757546.png)
>
> 

## textarea

> `<textarea>` 标签定义多行的文本输入控件。

> 文本区中可容纳无限数量的字符，其中的文本的默认字体是**等宽字体**
>
> 可以通过 cols 和 rows 属性来规定 textarea 的尺寸（用字符而不是用像素），不过更好的办法是使用 CSS 的 height 和 width 属性。
>
> 

# 多媒体

## video

> `video`标签定义视频，如电影片段或其他视频流

> | 属性     | 值                   | 说明                                                         |
> | -------- | -------------------- | ------------------------------------------------------------ |
> | autoplay | autoplay             | 如果指定该属性，则视频在就绪后将自动播放。                   |
> | controls | controls             | 如果指定该属性，则向用户显示控件，比如播放/暂停按钮。        |
> | height   | pixels               | 指定视频播放器的高度。                                       |
> | loop     | loop                 | 如果指定该属性，将循环播放视频。                             |
> | muted    | muted                | 如果指定该属性，则将视频的音频输出为静音。                   |
> | poster   | URL                  | 指定视频正在下载时显示的图像。                               |
> | preload  | auto、metadata、none | 指定视频在页面加载时，是否进行预加载。注意：如果同时指定了 autoplay 属性，则忽略该属性。 <br />auto：要求浏览器尽快加载整个视频，默认行为 <br />metadata：只加载视频的元数据（宽度、高度、第一帧影像和视频总长度等） <br />none：在用户点击开始播放之前不会加载视频 |
> | src      | URL                  | 指定要播放的视频文件的 URL 地址。                            |
> | width    | pixels               | 指定视频播放器的宽度。                                       |
>
> 
