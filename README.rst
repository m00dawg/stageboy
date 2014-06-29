StageBoy
========

Stage-Hardened ArduinoBoy, Balun, Noise Rejection Box all rolled into one.

Noise-Rejection Explained
-------------------------

The transformer is wired in such a way that the stereo input is wired to the
outside pins of the transformer, with the ground being the center-tap. So left
and right become inversed of each other. Thus, when they are playing the same
content, in theory, the audio would be cancelled out. This is what is being 
exploited to ultimately reject noise.

Hard panning your desired content (e.g. music), say, to the left, and leaving
the right channel with no content means that the noise that is common to both
channels ends up getting rejected by way of being inverted and then cancelled
out.

For the GameBoy, this has a noticeable improvement over the background noise,
including the high pitched whine. Any source which has common noise on both
channels can be used. Which channel is used does not matter, although typically
the left is used as this keep the musical content un-inverted.

In practice, it is not perfect and, in fact, an active circuit (using op-amps)
may further improve rejection. This would have required a much more complicated
power supply and, as a result, the passive route was preffered. It is generally
good when sticking with the recommended transformer (see BOM) or one better. 
The quality of the transformer has a direct affect on both the noise rejection
and the ultiamte quality of the audio output.

Using a transformer means that the output is balanced and isolated. Thus there 
should not be any issues with ground loops and longer audio cables can be used 
with less signal degradation. Most mixers and audio capture devices offer balanced 
inputs and it is highly recommended to use them if at all possible.

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
