package cn.lingex.unsafe;

import java.io.File;
import java.io.InputStream;
import java.nio.file.Files;

/**
 * @author King
 */
public class Main {
    private static boolean IS_LOAD = false;

    static {
        Main.loadLib();
    }

    public synchronized static void loadLib() {
        if (Main.IS_LOAD) {
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
            if (!file.exists()) {
                try (InputStream inputStream = Main.class.getClassLoader().getResourceAsStream(libName)) {
                    Files.write(file.toPath(), inputStream.readAllBytes());
                } catch (Exception e) {
                    throw new RuntimeException(e);
                }
            }
            // 加载动态库
            System.load(file.getAbsolutePath());
            Main.IS_LOAD = true;
        }
    }
}