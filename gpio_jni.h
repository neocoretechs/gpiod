#include <jni.h>

JNIEXPORT jint JNICALL Java_com_neocoretechs_robocore_GpioNative_openChip(JNIEnv *, jobject, jstring);
JNIEXPORT jint JNICALL Java_com_neocoretechs_robocore_GpioNative_findChipLine(JNIEnv *, jobject, jstring);
JNIEXPORT jint JNICALL Java_com_neocoretechs_robocore_GpioNative_getChipLine(JNIEnv *, jobject, jint);
JNIEXPORT jint JNICALL Java_com_neocoretechs_robocore_GpioNative_lineRequestInput(JNIEnv *, jobject);
JNIEXPORT jint JNICALL Java_com_neocoretechs_robocore_GpioNative_lineRequestOutput(JNIEnv *, jobject);
JNIEXPORT jint JNICALL Java_com_neocoretechs_robocore_GpioNative_lineRequestRisingEdgeEvents(JNIEnv *, jobject);
JNIEXPORT jint JNICALL Java_com_neocoretechs_robocore_GpioNative_lineGetValue(JNIEnv *, jobject);
JNIEXPORT jint JNICALL Java_com_neocoretechs_robocore_GpioNative_lineSetValue(JNIEnv *, jobject, jint);
JNIEXPORT jint JNICALL Java_com_neocoretechs_robocore_GpioNative_lineEventWait(JNIEnv *, jobject);
JNIEXPORT jint JNICALL Java_com_neocoretechs_robocore_GpioNative_lineEventRead(JNIEnv *, jobject);
JNIEXPORT jint JNICALL Java_com_neocoretechs_robocore_GpioNative_lineRelease(JNIEnv *, jobject);
JNIEXPORT void JNICALL Java_com_neocoretechs_robocore_GpioNative_closeChip(JNIEnv *, jobject);