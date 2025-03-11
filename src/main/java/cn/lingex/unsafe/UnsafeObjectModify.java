package cn.lingex.unsafe;


/**
 * @author liao jian bo
 */
public class UnsafeObjectModify {
    static {
        Main.loadLib();
    }
    /**
     * 为对象字段设置Integer值
     *
     * @param object    对象
     * @param fieldName 字段名称
     * @param value     值
     */
    public static native void setObjectFieldValueInt(Object object, String fieldName, int value) throws Error;

    /**
     * 为对象字段设置long值
     *
     * @param object    被设置的对象
     * @param fieldName 字段名称
     * @param value     字段值
     */
    public static native void setObjectFieldValueLong(Object object, String fieldName, long value) throws Error;


    /**
     * 为对象字段设置bool值
     *
     * @param object    对象
     * @param fieldName 字段名称
     * @param value     值
     */
    public static native void setObjectFieldValueBool(Object object, String fieldName, boolean value) throws Error;


    /**
     * 为对象字段设置byte值
     *
     * @param object    对象
     * @param fieldName 字段名称
     * @param value     值
     */
    public static native void setObjectFieldValueByte(Object object, String fieldName, byte value) throws Error;

    /**
     * 为对象字段设置short值
     *
     * @param object    对象
     * @param fieldName 字段名称
     * @param value     值
     */
    public static native void setObjectFieldValueShort(Object object, String fieldName, short value) throws Error;
    /**
     * 为对象字段设置char值
     *
     * @param object    对象
     * @param fieldName 字段名称
     * @param value     值
     */
    public static native void setObjectFieldValueChar(Object object, String fieldName, char value) throws Error;
    /**
     * 为对象字段设置float值
     *
     * @param object    对象
     * @param fieldName 字段名称
     * @param value     值
     */
    public static native void setObjectFieldValueFloat(Object object, String fieldName, float value) throws Error;
    /**
     * 为对象字段设置double值
     *
     * @param object    对象
     * @param fieldName 字段名称
     * @param value     值
     */
    public static native void setObjectFieldValueDouble(Object object, String fieldName, double value) throws Error;


    /**
     * 为对象字段设置引用值
     *
     * @param object    对象
     * @param fieldName 字段名称
     * @param value     值
     */
    public static void setObjectFieldValueRef(Object object, String fieldName, Object value) throws Error {
        UnsafeObjectModify.setObjectFieldValueRef(object, fieldName, value.getClass().descriptorString(), value);
    }

    /**
     * 为对象字段设置引用类型值
     * @param object 对象
     * @param fieldName 字段名称
     * @param sig 类型签名
     * @param value 设置的值
     * @throws Error 错误
     */
    public static native void setObjectFieldValueRef(Object object, String fieldName, String sig, Object value) throws Error;
}
