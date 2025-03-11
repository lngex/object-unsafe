Object-unsafe
========================
Java中sun.misc.Unsafe类在Java9以后便不能直接获取，在Java23后使用方法会提示警告。
在不久后可能无法直接时使用，但是在项目中缺必不可却，虽然JDK提供反射和VarHandle以供操作/访问。
但是这个API并不能操作所有的类，为了解决这和问题，Object-unsafe便应运而生。


下载Object-unsafe
================
如果你使用的x86_64处理器的windows或linux，你可以直接下载jar引入到项目中

[1.下载Jar包](https://github.com/lngex/object-unsafe/releases/download/v1.0.0/object-unsafe.jar)
-----------
#### Jar包支持的平台
- windows_x86_64
- linux_x86_64

2.从源码构建
----------
1. clone 

    ``git clone https://github.com/lngex/object-unsafe.git``
2. 添加平台  
    默认linux与windows，添加平台需要编辑[CMakeLists.txt](clib/JNI_LIB/CMakeLists.txt)文件
2. 编译
   - windows平台,建议使用clion，它有完整的构建工具
   - linux  
   ``
    cd object-unsafe/clib/JNI_LIB && cmake . && make
   ``

3.使用
-----------
- 从源码构建需要删除[UnsafeObjectModify](src/main/java/cn/lingex/unsafe/UnsafeObjectModify.java)与[UnsafeObjectRead](src/main/java/cn/lingex/unsafe/UnsafeObjectRead.java)的静态代码快(使用jar包可忽视)
- 加载库  
```java
  static {
    System.load(/*动态链接库绝对路径*/);
  }
```
- 类[UnsafeObjectModify](src/main/java/cn/lingex/unsafe/UnsafeObjectModify.java)更改对象属性
- 类[UnsafeObjectRead](src/main/java/cn/lingex/unsafe/UnsafeObjectRead.java)读取对象属性

4.示例
-------
```java 
class Persion {
     private boolean field_bool;
     private byte field_byte;
     private char field_char;
     private short field_short;
     private int field_int;
     private long field_long;
     private float field_float;
     private double field_double;
     private Persion persion;
}

public static void main(String[] args) {

    Persion persion = new Persion();
    // 赋值
    UnsafeObjectModify.setObjectFieldValueBool(persion, "field_bool", true);
    UnsafeObjectModify.setObjectFieldValueByte(persion, "field_byte", Byte.MAX_VALUE);
    UnsafeObjectModify.setObjectFieldValueChar(persion, "field_char", 'C');
    UnsafeObjectModify.setObjectFieldValueShort(persion, "field_short", Short.MAX_VALUE);
    UnsafeObjectModify.setObjectFieldValueInt(persion, "field_int", Integer.MAX_VALUE);
    UnsafeObjectModify.setObjectFieldValueLong(persion, "field_long", Long.MAX_VALUE);
    UnsafeObjectModify.setObjectFieldValueFloat(persion, "field_float", Float.MAX_VALUE);
    UnsafeObjectModify.setObjectFieldValueDouble(persion, "field_double", Double.MAX_VALUE);
    UnsafeObjectModify.setObjectFieldValueRef(persion, "persion", persion);
    // 读取值
    System.out.println(UnsafeObjectRead.readObjectFieldValueBool(persion, "field_bool")); // true
    System.out.println(UnsafeObjectRead.readObjectFieldValueByte(persion, "field_byte"));  // 127
    System.out.println(UnsafeObjectRead.readObjectFieldValueChar(persion, "field_char"));  // C
    System.out.println(UnsafeObjectRead.readObjectFieldValueShort(persion, "field_short")); // 32767
    System.out.println(UnsafeObjectRead.readObjectFieldValueInt(persion, "field_int"));   // 2147483647
    System.out.println(UnsafeObjectRead.readObjectFieldValueLong(persion, "field_long"));  //9223372036854775807
    System.out.println(UnsafeObjectRead.readObjectFieldValueFloat(persion, "field_float")); // 3.4028235E38
    System.out.println(UnsafeObjectRead.readObjectFieldValueDouble(persion, "field_double")); // 1.7976931348623157E308
    System.out.println(UnsafeObjectRead.readObjectFieldValueRef(persion, "persion", Persion.class));  // cn.lingex.unsafe.Main$Persion@b4c966a
    System.out.println("======================");
}
```

5.警告
-----
UnsafeObjectModify与UnsafeObjectRead中的方法均会抛出错误，严重可能导致JVM崩溃，调用前一定要检查对象是否为空。并且使用trt-catch处理异常
