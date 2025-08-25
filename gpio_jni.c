#include <jni.h>
#include <gpiod.h>
#include <stdio.h>  
#include <unistd.h>
#include <time.h>
#include "gpio_jni.h"
JNIEXPORT jint JNICALL Java_com_neocoretechs_robocore_GpioNative_openChip(JNIEnv *env, jobject obj, jstring chipName) {
    const char *nativeChipName = (*env)->GetStringUTFChars(env, chipName, 0);
    int ret = open_chip(nativeChipName);
    (*env)->ReleaseStringUTFChars(env, chipName, nativeChipName);
    return ret;
}
JNIEXPORT jint JNICALL Java_com_neocoretechs_robocore_GpioNative_getChipLine(JNIEnv *env, jobject obj, jint lineNum) {
    return get_chip_line((unsigned int)lineNum);
}
JNIEXPORT jint JNICALL Java_com_neocoretechs_robocore_GpioNative_lineRequestInput(JNIEnv *env, jobject obj) {
    return line_request_input();
}
JNIEXPORT jint JNICALL Java_com_neocoretechs_robocore_GpioNative_findChipLine(JNIEnv *env, jobject obj, jstring lineName) {
    const char *nativeLineName = (*env)->GetStringUTFChars(env, lineName, 0);
    int ret = find_chip_line(nativeLineName);
    (*env)->ReleaseStringUTFChars(env, lineName, nativeLineName);
    return ret;
}
JNIEXPORT jint JNICALL Java_com_neocoretechs_robocore_GpioNative_lineRequestOutput(JNIEnv *env, jobject obj) {
    return line_request_output();
}
JNIEXPORT jint JNICALL Java_com_neocoretechs_robocore_GpioNative_lineRequestRisingEdgeEvents(JNIEnv *env, jobject obj) {
    return line_request_rising_edge_events();
}
JNIEXPORT jint JNICALL Java_com_neocoretechs_robocore_GpioNative_lineGetValue(JNIEnv *env, jobject obj) {
    return line_get_value();
}
JNIEXPORT jint JNICALL Java_com_neocoretechs_robocore_GpioNative_lineSetValue(JNIEnv *env, jobject obj, jint value) {
    return line_set_value();
}
JNIEXPORT jint JNICALL Java_com_neocoretechs_robocore_GpioNative_lineEventWait(JNIEnv *env, jobject obj) {
  return line_event_wait();
}
JNIEXPORT jint JNICALL Java_com_neocoretechs_robocore_GpioNative_lineEventRead(JNIEnv *env, jobject obj) {
    return line_event_read();
}
JNIEXPORT jint JNICALL Java_com_neocoretechs_robocore_GpioNative_lineRelease(JNIEnv *env, jobject obj) {
    return line_release();
}
JNIEXPORT void JNICALL Java_com_neocoretechs_robocore_GpioNative_closeChip(JNIEnv *env, jobject obj) {
    close_chip();
}
