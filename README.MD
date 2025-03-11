Object-unsafe
========================
Java中sun.misc.Unsafe类在Java9以后便不能直接获取，在Java23后使用方法会提示警告。
在不久后可能无法直接时使用，但是在项目中缺必不可却，虽然JDK提供反射和VarHandle以供操作/访问。
但是这个API并不能操作所有的类，为了解决这和问题，Object-unsafe便应运而生。

使用Object-unsafe
================



