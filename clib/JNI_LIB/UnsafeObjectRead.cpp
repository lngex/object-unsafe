#include <iostream>

#include "cn_lingex_unsafe_UnsafeObjectRead.h"


/*
 * Class:     cn_lingex_unsafe_UnsafeObjectRead
 * Method:    readObjectFieldValueBool
 * Signature: (Ljava/lang/Object;Ljava/lang/String;)Z
 */
JNIEXPORT jboolean JNICALL Java_cn_lingex_unsafe_UnsafeObjectRead_readObjectFieldValueBool
(JNIEnv *env, jclass, jobject object, jstring fieldName) {
    jclass clz = env->GetObjectClass(object);
    jboolean bol = '0';
    const char *fieldStr = env->GetStringUTFChars(fieldName, &bol);
    jfieldID fieldId = env->GetFieldID(clz, fieldStr, "Z");
    env->ReleaseStringUTFChars(fieldName, fieldStr);
    if (fieldId == nullptr) {
        return false;
    }
    return env->GetBooleanField(object, fieldId);
}

/*
 * Class:     cn_lingex_unsafe_UnsafeObjectRead
 * Method:    readObjectFieldValueByte
 * Signature: (Ljava/lang/Object;Ljava/lang/String;)B
 */
JNIEXPORT jbyte JNICALL Java_cn_lingex_unsafe_UnsafeObjectRead_readObjectFieldValueByte
(JNIEnv *env, jclass, jobject object, jstring fieldName) {
    jclass clz = env->GetObjectClass(object);
    jboolean bol = '0';
    const char *fieldStr = env->GetStringUTFChars(fieldName, &bol);
    jfieldID fieldId = env->GetFieldID(clz, fieldStr, "B");
    env->ReleaseStringUTFChars(fieldName, fieldStr);
    if (fieldId == nullptr) {
        return '0';
    }
    return env->GetByteField(object, fieldId);
}

/*
 * Class:     cn_lingex_unsafe_UnsafeObjectRead
 * Method:    readObjectFieldValueChar
 * Signature: (Ljava/lang/Object;Ljava/lang/String;)C
 */
JNIEXPORT jchar JNICALL Java_cn_lingex_unsafe_UnsafeObjectRead_readObjectFieldValueChar
(JNIEnv *env, jclass, jobject object, jstring fieldName) {
    jclass clz = env->GetObjectClass(object);
    jboolean bol = '0';
    const char *fieldStr = env->GetStringUTFChars(fieldName, &bol);
    jfieldID fieldId = env->GetFieldID(clz, fieldStr, "C");
    env->ReleaseStringUTFChars(fieldName, fieldStr);
    if (fieldId == nullptr) {
        return '0';
    }
    return env->GetCharField(object, fieldId);
}

/*
 * Class:     cn_lingex_unsafe_UnsafeObjectRead
 * Method:    readObjectFieldValueShort
 * Signature: (Ljava/lang/Object;Ljava/lang/String;)S
 */
JNIEXPORT jshort JNICALL Java_cn_lingex_unsafe_UnsafeObjectRead_readObjectFieldValueShort
(JNIEnv *env, jclass, jobject object, jstring fieldName) {
    jclass clz = env->GetObjectClass(object);
    jboolean bol = '0';
    const char *fieldStr = env->GetStringUTFChars(fieldName, &bol);
    jfieldID fieldId = env->GetFieldID(clz, fieldStr, "S");
    env->ReleaseStringUTFChars(fieldName, fieldStr);
    if (fieldId == nullptr) {
        return 0;
    }
    return env->GetShortField(object, fieldId);
}

/*
 * Class:     cn_lingex_unsafe_UnsafeObjectRead
 * Method:    readObjectFieldValueInt
 * Signature: (Ljava/lang/Object;Ljava/lang/String;)I
 */
JNIEXPORT jint JNICALL Java_cn_lingex_unsafe_UnsafeObjectRead_readObjectFieldValueInt
(JNIEnv *env, jclass, jobject object, jstring fieldName) {
    jclass clz = env->GetObjectClass(object);
    jboolean bol = '0';
    const char *fieldStr = env->GetStringUTFChars(fieldName, &bol);
    jfieldID fieldId = env->GetFieldID(clz, fieldStr, "I");
    env->ReleaseStringUTFChars(fieldName, fieldStr);
    if (fieldId == nullptr) {
        return 0;
    }
    return env->GetIntField(object, fieldId);
}

/*
 * Class:     cn_lingex_unsafe_UnsafeObjectRead
 * Method:    readObjectFieldValueLong
 * Signature: (Ljava/lang/Object;Ljava/lang/String;)J
 */
JNIEXPORT jlong JNICALL Java_cn_lingex_unsafe_UnsafeObjectRead_readObjectFieldValueLong
(JNIEnv *env, jclass, jobject object, jstring fieldName) {
    jclass clz = env->GetObjectClass(object);
    jboolean bol = '0';
    const char *fieldStr = env->GetStringUTFChars(fieldName, &bol);
    jfieldID fieldId = env->GetFieldID(clz, fieldStr, "J");
    env->ReleaseStringUTFChars(fieldName, fieldStr);
    if (fieldId == nullptr) {
        return 0L;
    }
    return env->GetLongField(object, fieldId);
}

/*
 * Class:     cn_lingex_unsafe_UnsafeObjectRead
 * Method:    readObjectFieldValueFloat
 * Signature: (Ljava/lang/Object;Ljava/lang/String;)F
 */
JNIEXPORT jfloat JNICALL Java_cn_lingex_unsafe_UnsafeObjectRead_readObjectFieldValueFloat
(JNIEnv *env, jclass, jobject object, jstring fieldName) {
    jclass clz = env->GetObjectClass(object);
    jboolean bol = '0';
    const char *fieldStr = env->GetStringUTFChars(fieldName, &bol);
    jfieldID fieldId = env->GetFieldID(clz, fieldStr, "F");
    env->ReleaseStringUTFChars(fieldName, fieldStr);
    if (fieldId == nullptr) {
        return 0.f;
    }
    return env->GetFloatField(object, fieldId);
}

/*
 * Class:     cn_lingex_unsafe_UnsafeObjectRead
 * Method:    readObjectFieldValueDouble
 * Signature: (Ljava/lang/Object;Ljava/lang/String;)D
 */
JNIEXPORT jdouble JNICALL Java_cn_lingex_unsafe_UnsafeObjectRead_readObjectFieldValueDouble
(JNIEnv *env, jclass, jobject object, jstring fieldName) {
    jclass clz = env->GetObjectClass(object);
    jboolean bol = '0';
    const char *fieldStr = env->GetStringUTFChars(fieldName, &bol);
    jfieldID fieldId = env->GetFieldID(clz, fieldStr, "D");
    env->ReleaseStringUTFChars(fieldName, fieldStr);
    if (fieldId == nullptr) {
        return 0.0;
    }
    return env->GetDoubleField(object, fieldId);
}

/*
 * Class:     cn_lingex_unsafe_UnsafeObjectRead
 * Method:    readObjectFieldValueRef
 * Signature: (Ljava/lang/Object;Ljava/lang/String;Ljava/lang/String;)Ljava/lang/Object;
 */
JNIEXPORT jobject JNICALL Java_cn_lingex_unsafe_UnsafeObjectRead_readObjectFieldValueRef
(JNIEnv *env, jclass, jobject object, jstring fieldName, jstring clsSig) {
    jclass clz = env->GetObjectClass(object);
    jboolean bol = '0';
    const char *fieldStr = env->GetStringUTFChars(fieldName, &bol);
    const char *sig = env->GetStringUTFChars(clsSig, &bol);
    jfieldID fieldId = env->GetFieldID(clz, fieldStr, sig);
    env->ReleaseStringUTFChars(fieldName, fieldStr);
    env->ReleaseStringUTFChars(clsSig, sig);
    if (fieldId == nullptr) {
        return nullptr;
    }
    return env->GetObjectField(object, fieldId);
}
