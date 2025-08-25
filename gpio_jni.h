#include <jni.h>

JNIEXPORT jint JNICALL Java_com_neocoretechs_robocore_GpioNative_openChip(JNIEnv *, jobject, jstring);
JNIEXPORT jint JNICALL Java_com_neocoretechs_robocore_GpioNative_findChipLine(JNIEnv *, jobject, jstring);
JNIEXPORT jint JNICALL Java_com_neocoretechs_robocore_GpioNative_lineRequestInput(JNIEnv *, jobject, jint);
JNIEXPORT jint JNICALL Java_com_neocoretechs_robocore_GpioNative_lineRequestOutput(JNIEnv *, jobject, jint);
JNIEXPORT jint JNICALL Java_com_neocoretechs_robocore_GpioNative_lineRequestRisingEdgeEvents(JNIEnv *, jobject, jint);
JNIEXPORT jint JNICALL Java_com_neocoretechs_robocore_GpioNative_lineGetValue(JNIEnv *, jobject, jint);
JNIEXPORT jint JNICALL Java_com_neocoretechs_robocore_GpioNative_lineSetValue(JNIEnv *, jobject, jint, jint);
JNIEXPORT jint JNICALL Java_com_neocoretechs_robocore_GpioNative_lineEventWait(JNIEnv *, jobject, jint);
JNIEXPORT jint JNICALL Java_com_neocoretechs_robocore_GpioNative_lineEventRead(JNIEnv *, jobject, jint);
JNIEXPORT jint JNICALL Java_com_neocoretechs_robocore_GpioNative_lineRelease(JNIEnv *, jobject, jint);
JNIEXPORT void JNICALL Java_com_neocoretechs_robocore_GpioNative_closeChip(JNIEnv *, jobject);