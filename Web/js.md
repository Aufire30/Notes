# javascript

![image-20251113204206241](C:\Users\Aufire\AppData\Roaming\Typora\typora-user-images\image-20251113204206241.png)

## 引用外部脚本文件

![image-20251113204542257](C:\Users\Aufire\AppData\Roaming\Typora\typora-user-images\image-20251113204542257.png)

**注意：不能在同一个script元素里面及定义内嵌脚本，又引入外部脚本**

## 让浏览器延迟执行脚本

> **defer**使浏览器暂时忽略脚本，等HTML的DOM全部解析完成之后再去执行脚本

![image-20251113205231696](C:\Users\Aufire\AppData\Roaming\Typora\typora-user-images\image-20251113205231696.png)

**注意：defer属性只能用于外部脚本文件**

## 异步执行脚本

正常来说，HTML的解析会等待脚本加载完之后再继续进行解析

> **async**用于告诉浏览器该脚本可以被异步执行，HTML解析器在遇到该标签的时候不会停下来，使得HTML文档的解析和脚本的获取是同时进行的

**注意：**

**async属性也只能用于获取外部脚本文件**

**使用async属性会导致多个脚本的执行次序不可控，谁先加载完成谁就先被执行**

**如果脚本中使用了其他脚本定义的函数或者值,async属性就不适用了**

## noscript

![image-20251113210212272](C:\Users\Aufire\AppData\Roaming\Typora\typora-user-images\image-20251113210212272.png)

在头部使用noscript

![image-20251113210348377](C:\Users\Aufire\AppData\Roaming\Typora\typora-user-images\image-20251113210348377.png)

# parseInt

> `parseInt` 是 JavaScript 中的一个全局函数，用于**将字符串解析为整数**。
>
> - **语法**: `parseInt(string, radix)`，其中 `string` 是要解析的字符串，
>
>   ​	`radix` 是可选参数，表示数字的基数（例如，10 表示十进制，16 表示十六进制）。 
>
> - **返回值**: 如果解析成功，返回转换后的整数；如果无法解析，返回 NaN。 
>
> - **注意事项**: 当 `radix` 为 0 或未设置时，`parseInt` 会根据字符串的内容自动判断基数。
