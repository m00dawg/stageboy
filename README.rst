StageBoy
========

Stage-Hardened ArduinoBoy, Balun, Noise Rejection Box all rolled into one.

Programming the StageBoy
------------------------

Pulling the Chip
~~~~~~~~~~~~~~~~

If you don't want to mess with the ISP headers, you can likely just stuff
an AVR chip which is already Arduinofied (it has the bootlodaer already -
as in you previously flashed it with the bootloader or bought an AVR 
from a place that will flash it for you) into an Uno board and upload
the code as you normally would. Then you can pull the chip and put it into
the StageBoy.

If you're not making any changes, and are reasonably confident with your 
soldering work, this should work without issue. Using the ISP headers, 
however, makes thins easier to troubleshoot.

Using the ISP Headers
~~~~~~~~~~~~~~~~~~~~~

ISP headers have been used successful with EvilMadScientist's ISP Shield
(see http://shop.evilmadscientist.com/productsmenu/tinykitlist/253-ispshield)
and an Arduino Duemilanove. Wires are hooked up in a similar way to the
Arduino ISP how-to (see: http://arduino.cc/en/Tutorial/ArduinoISP) but
with a 6-pin ISP header on the other end. A standard ISP cable should
work, and would be a lot easier, but hasn't been tested.

With the ISP Shield, program the Arduino connect to the shield using the
ArduinoISP sketch available with the Ardunio IDE (under Examples). Then
connect the shield to the Arduino and the ISP cable to the StageBoy. Burning
the bootloader should be optional, but it has never been tested without. To
burn the bootloader, pick the Arduino board you are using as the programmer
in the Tools -> Board menu. Then set the Programmer to Arduino As ISP under
Tools -> Programmer. Then go to Tools -> Burn Bootloader.

Having done that, load up the StageBoy sketch, and then press SHIFT and click
on the upload icon. This uploads the code to the StageBoy instead of to the
Arduino board acting as the programmer.
