#include <jni.h>
#include <string.h>
#include <android/log.h>

#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class: com_marakana_NativeLib
 * Method: add
 * Signature: (II)I
 */
JNIEXPORT jstring JNICALL Java_com_cagry_gdg_MainActivity_getNativeString (JNIEnv *, jobject);
JNIEXPORT jint JNICALL Java_com_cagry_gdg_MainActivity_nativeSum (JNIEnv *, jobject, jint, jint);
JNIEXPORT jint JNICALL Java_com_cagry_gdg_MainActivity_nativeArraySum (JNIEnv *, jobject, jintArray);
JNIEXPORT jint JNICALL Java_com_cagry_gdg_MainActivity_nativePerformanceTest(JNIEnv *, jobject);

#ifdef __cplusplus
}
#endif
