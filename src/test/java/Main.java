import cn.lingex.unsafe.UnsafeObjectModify;
import cn.lingex.unsafe.UnsafeObjectRead;

/**
 * @author King
 */
public class Main {
    static class Persion {
        private final boolean field_bool =false;
        private final byte field_byte = 0;
        private final char field_char = '0';
        private final short field_short = 0;
        private final int field_int = 0;
        private final long field_long = 0;
        private final float field_float = 0;
        private final double field_double = 0;
        private final Persion persion = null;
    }

    static class Test{
        private final int a = 12;
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
}
