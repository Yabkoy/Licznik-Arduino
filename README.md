### **Arduino Counter**

I created a school lesson counter that calculate time to next break and the next lesson. I used Arduino to develop it, but after that I took a ATMega chip and created a separate board for that in kicad with schematics and when I insert programmed the chip and other electronic parts everything should work properly.

### **Electronic Parts**
- ATMega328
- Led diode 
- crystal  16 MHz
- Resistor 10K
- Ceramic capacitor 22pF
- Max 7219 7 segment
- RTC Module

![schematic]("images/schematic.jpg")


### **KICAD**

Beside the source code for Arduino the repository contains the KiCad Project with full schematic and PCB for this counter.
So in the KicadProj/Licznik directory you will find all files that you will need.


**[KiCad Download](https://www.kicad.org/)**

![PCB]("images/PCB.jpg")

### **Dependencies**
As a dependencies I used two libraries for DS3231 chip and Max7219 chip. The source code of libs is containing in libraries folder. 
**NOTE: THE CODE OF THIS LIBRARIES IS NOT MINE** 