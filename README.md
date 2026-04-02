# qt-element-ui

目前使用 C++ Qt 5.14 版本，模拟实现 Web 组件库 Element Plus ( Element UI ) 的相关控件。

> 原仓库地址：https://github.com/yyx-dev/qt-element-ui
>
> 交流群：979732179

#### 更新内容
##### 一、Message类修改、添加MessageManager类
1. 为Message类添加淡入、淡出效果，同时不再负责自身的位置计算。增加回调信号、设置不自动关闭等等。
2. 新增MessageManager类，统一管理Message的位置，并实现消息队列的上移效果等。

###### 效果预览
![msg](https://github.com/user-attachments/assets/7895b1a6-f7be-4e38-a63b-10ff0c875791)

---

#### 代码规范

1. 成员变量命名以_开头，声明默认值时使用=。
2. getter、setter方法名需以get、set开头。
3. 公开的成员函数如不需要返回，请返回类对象引用，以支持链式调用。
4. 设计接口要考虑到使用场景，比如水印要提供setWatermark的静态方法，以便其他控件设置水印背景。
5. 字体统一从utils.h的FontHelper::getFont获取，字号等需和已有控件保持一致。
