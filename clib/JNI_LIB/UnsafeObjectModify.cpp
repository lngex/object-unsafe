#include "cn_lingex_unsafe_UnsafeObjectModify.h"


void Java_cn_lingex_unsafe_UnsafeObjectModify_setObjectFieldValueInt
(JNIEnv *env, jclass, jobject object, jstring fieldName, jint value) {
    jclass cls = env->GetObjectClass(object);
    unsigned char copy = '0';
    const char *fieldStr = env->GetStringUTFChars(fieldName, &copy);
    jfieldID jfield_id = env->GetFieldID(cls, fieldStr, "I");
    env->ReleaseStringUTFChars(fieldName, fieldStr);
    if (jfield_id == NULL) {
        return;
    }
    env->SetIntField(object, jfield_id, value);
}


void Java_cn_lingex_unsafe_UnsafeObjectModify_setObjectFieldValueBool
(JNIEnv *env, jclass, jobject object, jstring fieldName, jboolean value) {
    jclass cls = env->GetObjectClass(object);
    unsigned char copy = '0';
    const char *fieldStr = env->GetStringUTFChars(fieldName, &copy);
    jfieldID jfield_id = env->GetFieldID(cls, fieldStr, "Z");
    env->ReleaseStringUTFChars(fieldName, fieldStr);
    if (jfield_id == NULL) {
        return;
    }
    env->SetBooleanField(object, jfield_id, value);
}

/*
 * Class:     cn_lingex_unsafe_UnsafeObjectModify
 * Method:    setObjectFieldValueRef
 * Signature: (Ljava/lang/Object;Ljava/lang/String;Ljava/lang/String;Ljava/lang/Object;)V
 */
void Java_cn_lingex_unsafe_UnsafeObjectModify_setObjectFieldValueRef
(JNIEnv *env, jclass, jobject object, jstring fieldName, jstring sigStr, jobject value) {
    jclass cls = env->GetObjectClass(object);
    unsigned char copy = '0';
    const char *fieldStr = env->GetStringUTFChars(fieldName, &copy);
    const char *sig = env->GetStringUTFChars(sigStr, &copy);
    jfieldID jfield_id = env->GetFieldID(cls, fieldStr, sig);
    env->ReleaseStringUTFChars(fieldName, fieldStr);
    env->ReleaseStringUTFChars(sigStr, sig);
    if (jfield_id == NULL) {
        return;
    }
    env->SetObjectField(object, jfield_id, value);
}

/*
 * Class:     cn_lingex_unsafe_UnsafeObjectModify
 * Method:    setObjectFieldValueLong
 * Signature: (Ljava/lang/Object;Ljava/lang/String;J)V
 */
void Java_cn_lingex_unsafe_UnsafeObjectModify_setObjectFieldValueLong
(JNIEnv *env, jclass, jobject object, jstring fieldName, jlong value) {
    jclass cls = env->GetObjectClass(object);
    unsigned char copy = '0';
    const char *fieldStr = env->GetStringUTFChars(fieldName, &copy);
    jfieldID jfield_id = env->GetFieldID(cls, fieldStr, "J");
    env->ReleaseStringUTFChars(fieldName, fieldStr);
    if (jfield_id == NULL) {
        return;
    }
    env->SetLongField(object, jfield_id, value);
}

/*
 * Class:     cn_lingex_unsafe_UnsafeObjectModify
 * Method:    setObjectFieldValueByte
 * Signature: (Ljava/lang/Object;Ljava/lang/String;B)V
 */
JNIEXPORT void JNICALL Java_cn_lingex_unsafe_UnsafeObjectModify_setObjectFieldValueByte
(JNIEnv *env, jclass, jobject object, jstring fieldName, jbyte value) {
    jclass cls = env->GetObjectClass(object);
    unsigned char copy = '0';
    const char *fieldStr = env->GetStringUTFChars(fieldName, &copy);
    jfieldID jfield_id = env->GetFieldID(cls, fieldStr, "B");
    env->ReleaseStringUTFChars(fieldName, fieldStr);
    if (jfield_id == NULL) {
        return;
    }
    env->SetByteField(object, jfield_id, value);
}


/*
 * Class:     cn_lingex_unsafe_UnsafeObjectModify
 * Method:    setObjectFieldValueShort
 * Signature: (Ljava/lang/Object;Ljava/lang/String;S)V
 */
JNIEXPORT void JNICALL Java_cn_lingex_unsafe_UnsafeObjectModify_setObjectFieldValueShort
(JNIEnv *env, jclass, jobject object, jstring fieldName, jshort value) {
    jclass cls = env->GetObjectClass(object);
    unsigned char copy = '0';
    const char *fieldStr = env->GetStringUTFChars(fieldName, &copy);
    jfieldID jfield_id = env->GetFieldID(cls, fieldStr, "S");
    env->ReleaseStringUTFChars(fieldName, fieldStr);
    if (jfield_id == NULL) {
        return;
    }
    env->SetShortField(object, jfield_id, value);
}

/*
 * Class:     cn_lingex_unsafe_UnsafeObjectModify
 * Method:    setObjectFieldValueChar
 * Signature: (Ljava/lang/Object;Ljava/lang/String;C)V
 */
JNIEXPORT void JNICALL Java_cn_lingex_unsafe_UnsafeObjectModify_setObjectFieldValueChar
(JNIEnv *env, jclass, jobject object, jstring fieldName, jchar value) {
    jclass cls = env->GetObjectClass(object);
    unsigned char copy = '0';
    const char *fieldStr = env->GetStringUTFChars(fieldName, &copy);
    jfieldID jfield_id = env->GetFieldID(cls, fieldStr, "C");
    env->ReleaseStringUTFChars(fieldName, fieldStr);
    if (jfield_id == NULL) {
        return;
    }
    env->SetCharField(object, jfield_id, value);
}

/*
 * Class:     cn_lingex_unsafe_UnsafeObjectModify
 * Method:    setObjectFieldValueFloat
 * Signature: (Ljava/lang/Object;Ljava/lang/String;F)V
 */
JNIEXPORT void JNICALL Java_cn_lingex_unsafe_UnsafeObjectModify_setObjectFieldValueFloat
(JNIEnv *env, jclass, jobject object, jstring fieldName, jfloat value) {
    jclass cls = env->GetObjectClass(object);
    unsigned char copy = '0';
    const char *fieldStr = env->GetStringUTFChars(fieldName, &copy);
    jfieldID jfield_id = env->GetFieldID(cls, fieldStr, "F");
    env->ReleaseStringUTFChars(fieldName, fieldStr);
    if (jfield_id == NULL) {
        return;
    }
    env->SetFloatField(object, jfield_id, value);
}

/*
 * Class:     cn_lingex_unsafe_UnsafeObjectModify
 * Method:    setObjectFieldValueDouble
 * Signature: (Ljava/lang/Object;Ljava/lang/String;D)V
 */
JNIEXPORT void JNICALL Java_cn_lingex_unsafe_UnsafeObjectModify_setObjectFieldValueDouble
(JNIEnv *env, jclass, jobject object, jstring fieldName, jdouble value) {
    jclass cls = env->GetObjectClass(object);
    unsigned char copy = '0';
    const char *fieldStr = env->GetStringUTFChars(fieldName, &copy);
    jfieldID jfield_id = env->GetFieldID(cls, fieldStr, "D");
    env->ReleaseStringUTFChars(fieldName, fieldStr);
    if (jfield_id == NULL) {
        return;
    }
    env->SetDoubleField(object, jfield_id, value);
}
