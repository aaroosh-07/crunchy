/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class com_google_security_crunchy_jni_CrunchySignerBindings */

#ifndef _Included_com_google_security_crunchy_jni_CrunchySignerBindings
#define _Included_com_google_security_crunchy_jni_CrunchySignerBindings
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     com_google_security_crunchy_jni_CrunchySignerBindings
 * Method:    createCrunchySignerBindings
 * Signature: ([B)J
 */
JNIEXPORT jlong JNICALL Java_com_google_security_crunchy_jni_CrunchySignerBindings_createCrunchySignerBindings
  (JNIEnv *, jclass, jbyteArray);

/*
 * Class:     com_google_security_crunchy_jni_CrunchySignerBindings
 * Method:    destroyCrunchySignerBindings
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_com_google_security_crunchy_jni_CrunchySignerBindings_destroyCrunchySignerBindings
  (JNIEnv *, jobject, jlong);

/*
 * Class:     com_google_security_crunchy_jni_CrunchySignerBindings
 * Method:    sign
 * Signature: (J[B)[B
 */
JNIEXPORT jbyteArray JNICALL Java_com_google_security_crunchy_jni_CrunchySignerBindings_sign
  (JNIEnv *, jobject, jlong, jbyteArray);

#ifdef __cplusplus
}
#endif
#endif