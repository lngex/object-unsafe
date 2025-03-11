package cn.lingex.unsafe;


/**
 * @author liao jian bo
 */
public class UnsafeObjectRead {
    static {
        Main.loadLib();
    }
    /**
     * 读取bool类型字段
     *
     * @param object 对象
     * @param field  对象字段名称
     * @return 读取结果
     */
    public static native boolean readObjectFieldValueBool(Object object, String field) throws Error;

    /**
     * 读取byte类型字段
     *
     * @param object 对象
     * @param field  对象字段名称
     * @return 读取结果
     */
    public static native byte readObjectFieldValueByte(Object object, String field) throws Error;

    /**
     * 读取char类型字段
     *
     * @param object 对象
     * @param field  对象字段名称
     * @return 读取结果
     */
    public static native char readObjectFieldValueChar(Object object, String field) throws Error;

    /**
     * 读取short类型字段
     *
     * @param object 对象
     * @param field  对象字段名称
     * @return 读取结果
     */
    public static native short readObjectFieldValueShort(Object object, String field) throws Error;

    /**
     * 读取int类型字段
     *
     * @param object 对象
     * @param field  对象字段名称
     * @return 读取结果
     */
    public static native int readObjectFieldValueInt(Object object, String field) throws Error;

    /**
     * 读取 long类型字段
     *
     * @param object 对象
     * @param field  对象字段名称
     * @return 读取结果
     */
    public static native long readObjectFieldValueLong(Object object, String field) throws Error;

    /**
     * 读取float类型字段
     *
     * @param object 对象
     * @param field  对象字段名称
     * @return 读取结果
     */
    public static native float readObjectFieldValueFloat(Object object, String field) throws Error;

    /**
     * 读取double类型字段
     *
     * @param object 对象
     * @param field  对象字段名称
     * @return 读取结果
     */
    public static native double readObjectFieldValueDouble(Object object, String field) throws Error;

    /**
     * 读取引用类型字段
     *
     * @param object 对象
     * @param field  对象字段名称
     * @param clasz  对象字段类型
     * @return 读取结果
     */
    public static Object readObjectFieldValueRef(Object object, String field, Class<?> clasz) throws Error {
        return UnsafeObjectRead.readObjectFieldValueRef(object, field, clasz.descriptorString());
    }

    /**
     * 读取Object类型字段
     *
     * @param object   对象
     * @param field    对象字段名称
     * @param classSig 类型签名
     * @return 读取结果
     */
    public static native Object readObjectFieldValueRef(Object object, String field, String classSig) throws Error;
}
