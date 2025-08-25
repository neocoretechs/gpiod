export JAVA_HOME=/usr/lib/jvm
export OUT_DIR=${PWD}/out
export LIBGPIOD_DIR=/usr/lib/aarch64-linux-gnu
export LIBGPIOD_HEADER_DIR=/usr/include
export MY_JNI_HEADERS=${OUT_DIR}/gpio_jni
export CPP_FOLDER=${PWD}/cpp
export LD_LIBRARY_PATH=${LIBGPIOD_DIR}

CC=gcc
CFLAGS=-Wall

all: clean
	#mkdir -p ${OUT_DIR} ${MY_JNI_HEADERS}
	$(CC) -c -fPIC -I${JAVA_HOME}/include -I${JAVA_HOME}/include/linux -I${MY_JNI_HEADERS} -I${LIBGPIOD_HEADER_DIR} ${CPP_FOLDER}/gpio_jni.c -o ${OUT_DIR}/gpiodLib.o
	$(CC) -c -fPIC -I${JAVA_HOME}/include -I${JAVA_HOME}/include/linux -I${MY_JNI_HEADERS} -I${LIBGPIOD_HEADER_DIR} ${CPP_FOLDER}/gpio.c -o ${OUT_DIR}/gpiodLib2.o
	$(CC) -shared -fPIC -o ${OUT_DIR}/libgpiodjni.so ${OUT_DIR}/gpiodLib.o ${OUT_DIR}/gpiodLib2.o -lc -L${LIBGPIOD_DIR} -lgpiod
#gcc -fPIC -I${JAVA_HOME}/include -I${JAVA_HOME}/include/linux -shared -o libgpiodjni.so gpio_jni.c -lgpiod
run: all

clean:
	#rm -rf ${OUT_DIR} ${MY_JNI_HEADERS}