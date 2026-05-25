# 样式

> 优先级：内联样式>内部样式表>外部样式表

## 内联样式

> 直接在标签中设置全局样式

> ![image-20251215163608403](C:\Users\Aufire\AppData\Roaming\Typora\typora-user-images\image-20251215163608403.png)

## 内联样式表

> 在`<head>`标签里面加入`<style>`标签，将**所有对应标签**进行设置，不再单独设置一个标签里面的内容

> ![image-20251215163813201](C:\Users\Aufire\AppData\Roaming\Typora\typora-user-images\image-20251215163813201.png)

## 外部样式表

> 通过`<link>`标签引入外部css文件
>
> ```html
> <link href = "外部CSS文件的url">
> ```
>
> 

# 选择器

## 元素选择器

> 设置对应元素的样式

> ```css
> h1{
> 	font-size: 15px;
> }
> ```

## 类选择器

> 通过匹配`class`指定的类名来设置对应的样式
>
> 其表现形式是在类名前面加一个`.`

> ```css
> .test
> {
> 	font-size: 15px
> }
> ```

## id选择器

> 通过`id`属性来定位，与class类似
>
> **注意：HTML文档中元素的id属性的值必须是`唯一`的**
>
> 其表现形式是在id名前面加上一个`#`

> ```css
> #test
> {
> 	font-size: 15px;
> }
> ```

## 交集选择器

> 第一个必须是元素选择器，第二个必须是类选择器或者id选择器
>
> `元素选择器.类选择器 | 元素选择器#id选择器`



> ```css
> span.content
> {
> 	color: red;
> }
> ```
>
> 表示**所有span标签下的content类**的字体颜色变成红色

## 伪元素选择器

> 前面有两个冒号`::`

| 选择器                                                       | 作用                                                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [::after](https://man.ilovefishc.com/pageCSS3/dotAfter.html) | 在被选元素的内容后面插入内容。                               |
| [::before](https://man.ilovefishc.com/pageCSS3/dotBefore.html) | 在被选元素的内容前面插入内容。                               |
| [::first-letter](https://man.ilovefishc.com/pageCSS3/dotfirst-letter.html) | 用于选取指定选择器的**首字母**。                             |
| [::first-line](https://man.ilovefishc.com/pageCSS3/dotfirst-line.html) | 用于选取指定选择器的**首行**。                               |
| [::selection](https://man.ilovefishc.com/pageCSS3/dotdotselection.html) | 选匹配元素中**被用户选中**或处于高亮状态的部分。<br />即我们平时用鼠标指针划文本的时候文本背景变成蓝色的效果 |

## 伪类选择器

> 前面有一个冒号`:`

### 常用动态伪类选择器

| 属性                                                         | 作用                                       |
| ------------------------------------------------------------ | ------------------------------------------ |
| [:link](https://man.ilovefishc.com/pageCSS3/dotlink.html)    | 设置未被访问的链接的状态。                 |
| [:visited](https://man.ilovefishc.com/pageCSS3/dotvisited.html) | 设置已被访问的链接的状态。                 |
| [:hover](https://man.ilovefishc.com/pageCSS3/dothover.html)  | 设置鼠标指针悬浮在元素的上面时所表示的状态 |
| [:active](https://man.ilovefishc.com/pageCSS3/dotActive.html) | 当一个链接被点击的那一刻所表示的状态       |

