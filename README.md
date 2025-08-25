<h1>gpio Example usage</h1>

```java

package com.neocoretechs.robocore;



public class GpioNative {

&nbsp;   static {

&nbsp;       System.loadLibrary("gpiodjni"); // Your compiled .so/.dll

&nbsp;   }



&nbsp;   public native int openChip(String chipName);

&nbsp;   public native int getChipLine(int lineNum);

&nbsp;   public native int lineRequestInput();

&nbsp;   public native int lineRequestOutput();

&nbsp;   public native int lineRequestRisingEdgeEvents();

&nbsp;   public native int lineGetValue();

&nbsp;   public native int lineSetValue(int value);

&nbsp;   public native int lineEventWait();

&nbsp;   public native int lineEventRead();

&nbsp;   public native void closeChip();

}

```

