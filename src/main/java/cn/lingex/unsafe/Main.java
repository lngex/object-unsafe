package cn.lingex.unsafe;

import java.io.File;
import java.io.InputStream;
import java.nio.file.Files;

/**
 * @author King
 */
public class Main {
    static boolean IS_LOAD = false;

    static {
        Main.loadLiber();
    }

    public synchronized static void loadLiber() {
        if (Main.IS_LOAD){
            return;
        }
        String os = System.getProperty("os.name").toLowerCase();
        String libName = null;
        if (os.contains("windows")) {
            libName = "libJNI_LIB.dll";
        } else if (os.contains("linux")) {
            libName = "libJNI_LIB.so";
        }
        if (libName != null) {
            String userDir = System.getProperty("user.dir");
            File file = new File(userDir, libName);
            try (InputStream inputStream = Main.class.getClassLoader().getResourceAsStream(libName)) {
                Files.write(file.toPath(), inputStream.readAllBytes());
                // 加载动态库
                System.load(file.getAbsolutePath());
                Main.IS_LOAD = true;
            } catch (Exception e) {
                throw new RuntimeException(e);
            }
        }
    }

    static class Persion {
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
}