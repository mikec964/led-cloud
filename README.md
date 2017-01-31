# LED Cloud

This project controls an RGB LED strip in a cloud (pillow stuffing) as a room decoration.

The major aspects of the project are the cloud, the LED strip, the controller, and the power supply.

## Installing
* On Trinket, programmer: USBtinyISP. Note that the pins *must* be 4, 1, 0.
* On Arduino Uno, programmer: AVR ISP.
* On LightBlueBean, programmer: Bean Loader.

## Build a Cloud
The cloud is made of paper lamps glued together with poly-fill stuffing on the outside. Inside, there's an inexpensive LED strip that gives the cloud its changing colors.

The LED strip has individual red LEDs, green LEDs, and blue LEDs, about 16mm apart. Viewed from outside the cloud, the light is blended into other colors. The LEDs are not individually addressable, so all red LEDs turn on together. Hardware and software for controlling the strip are basically the same as controlling a single RGB LED. The only difference is that the strip is 12V.

## Unique Aspects
* I wrote an HSL (hue, saturation, lightness) to RGB converter. This helps:
    * Color selection. Blue is hue=240, red is hue=360, and purple is hue = 300.
    * Lighten or darken colors. Just change lightness.
    * Rainbows. Just increment hue from 0 to 359.

* The patterns are separate objects and files, easy to add or remove.

* Patterns use millis() timers instead of delay(), so they support multitasking and responsiveness to controls.

