<h1>gpio Example usage</h1>



```java

public static void main(String\[] args) {

&nbsp;   GpioNative gpio = new GpioNative();

&nbsp;   gpio.openChip("gpiochip0");

&nbsp;   gpio.getChipLine("PIN\_16");

&nbsp;   gpio.linRequestInput();

&nbsp;   System.out.println(gpio.lineGetValue());

&nbsp;   gpio.closeChip();

}

```

<h2>Native bindings</h2>



```java

package com.neocoretechs.robocore;



public class GpioNative {

&nbsp;   static {

&nbsp;   System.loadLibrary("gpiodjni"); // Your compiled .so/.dll	

&nbsp;   }

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

