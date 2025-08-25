<h1>gpio Example usage</h1>



```java

public static void main(String\[] args) {
    GpioNative gpio = new GpioNative();
    gpio.openChip("gpiochip0");
    gpio.getChipLine("PIN\_16");
    gpio.linRequestInput();
    System.out.println(gpio.lineGetValue());
    gpio.closeChip();
}

```

<h2>Native bindings</h2>



```java

package com.neocoretechs.robocore;

public class GpioNative {

    static {
    System.loadLibrary("gpiodjni"); // Your compiled .so/.dll
    }

    public native int openChip(String chipName);
    public native int getChipLine(int lineNum);
    public native int lineRequestInput();
    public native int lineRequestOutput();
public native int lineRequestRisingEdgeEvents();
    public native int lineGetValue();
    public native int lineSetValue(int value);
    public native int lineEventWait();
    public native int lineEventRead();
    public native void closeChip();
}

```

