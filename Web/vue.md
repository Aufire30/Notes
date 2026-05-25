# vue2的引用

> 在body中引用
>
> ```html
> <script src="https://cdnjs.cloudflare.com/ajax/libs/vue/2.6.14/vue.js"></script>
> ```

# el挂载点

> el是用来设置vue实例挂载（管理）的元素

> el挂载点的作用范围是在el选项命中的元素及其内部的后代元素
>
> el挂载点不仅可以用**id选择器**，还可以用**类选择器**，实际开发一般使用id选择器，因为是**唯一的**
>
> 标签不仅支持`<div>`标签，还支持`<p>`标签、`<h1>`标签等，但是必须是**双标签**，除了`<html>`和`<body>`

# data数据对象

![image-20251219091522271](C:\Users\Aufire\AppData\Roaming\Typora\typora-user-images\image-20251219091522271.png)

![image-20251219091530939](C:\Users\Aufire\AppData\Roaming\Typora\typora-user-images\image-20251219091530939.png)

![image-20251219091540283](C:\Users\Aufire\AppData\Roaming\Typora\typora-user-images\image-20251219091540283.png)

# 内容绑定，事件绑定

## v-text

> 设置标签的文本值，无论内容是什么，只会解析成文本

![image-20251219091913151](C:\Users\Aufire\AppData\Roaming\Typora\typora-user-images\image-20251219091913151.png)

第一个是全替换，不管<h2></h2>之间添加什么都不会显示，只显示message里面的值

第二个是部分替换

## v-html

> 设置标签的innerHTML,会被解析成标签

![image-20251219092322828](C:\Users\Aufire\AppData\Roaming\Typora\typora-user-images\image-20251219092322828.png)

和v-text相比，**v-html可以解析`<a>`标签里面的链接**，而v-text不会，会之间输出url文本

![image-20251219092631988](C:\Users\Aufire\AppData\Roaming\Typora\typora-user-images\image-20251219092631988.png)

## v-on

> 为元素绑定事件

![image-20251219093018629](C:\Users\Aufire\AppData\Roaming\Typora\typora-user-images\image-20251219093018629.png)

v-on可以使用@来替代

**method和data同级**

### 修改元素

> 通过this来修改元素

在方法中添加函数

![image-20251219094413200](C:\Users\Aufire\AppData\Roaming\Typora\typora-user-images\image-20251219094413200.png)

![image-20251219094445049](C:\Users\Aufire\AppData\Roaming\Typora\typora-user-images\image-20251219094445049.png)

![image-20251219094424160](C:\Users\Aufire\AppData\Roaming\Typora\typora-user-images\image-20251219094424160.png)

每次点击这个标题就会将food元素拼接一个好好吃的字符串

## 简单计数器

![image-20251219095726174](C:\Users\Aufire\AppData\Roaming\Typora\typora-user-images\image-20251219095726174.png)

![image-20251219095642423](C:\Users\Aufire\AppData\Roaming\Typora\typora-user-images\image-20251219095642423.png)



# 显示切换，属性绑定



# 列表循环，表单元素绑定