<h1>gpio Example usage</h1>

```java

public static void main(String\[] args) {

<t/>GpioNative gpio = new GpioNative();

&nbsp;	gpio.openChip("gpiochip0");

&nbsp;	gpio.getChipLine("PIN\_16");

&nbsp;	gpio.linRequestInput();

&nbsp;	System.out.println(gpio.lineGetValue());

&nbsp;	gpio.closeChip();

}

```

<h2>Native bindings</h2>

```java

package com.neocoretechs.robocore;



public class GpioNative {

&nbsp;	static {

&nbsp;	System.loadLibrary("gpiodjni"); // Your compiled .so/.dll	

&nbsp;	}

&nbsp;	public native int openChip(String chipName);

&nbsp;	public native int getChipLine(int lineNum);

&nbsp;	public native int lineRequestInput();

&nbsp;	public native int lineRequestOutput();

&nbsp;	public native int lineRequestRisingEdgeEvents();

&nbsp;	public native int lineGetValue();

&nbsp;	public native int lineSetValue(int value);

&nbsp;	public native int lineEventWait();

&nbsp;	public native int lineEventRead();

&nbsp;	public native void closeChip();

}

```

