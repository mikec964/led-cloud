# LED Cloud

This project controls an RGB LED strip in a cloud (pillow stuffing) as a room decoration.

The major aspects of the project are the cloud, the LED strip, the controller, and the power supply.

## The Cloud
The cloud is made of paper lamps glued together with pillow stuffing on the outside. Inside, there's an inexpensive LED strip that gives the cloud its color.

The LED strip has individual red LEDs, green LEDs, and blue LEDs, about 16mm apart. Viewed from outside the cloud, the light is blended into other colors. The LEDs are not individually addressable, so all red LEDs turn on together. Hardware and software for controlling the strip are basically the same as controlling a single RGB LED. The only difference is that the strip is 12V.

For a controller I started with an Arduino Uno for prototyping and debugging, and then embedded an AdaFruit Trinket for the final project.
* The Arduino has a serial port so I could use print statements while debugging.
* I could use virtually any pin on the Arduino. (If found out later I had to use certain pins on the Trinket. That's not a disadvantage, but at first it took some debugging before I realized why it wasn't working as expected.)
* The Trinket's small form factor, voltage regulation, and cost made it ideal for embedding. With no effort, I could drive it with the same 12V power supply used to power the LEDs.

## Unique Aspects
* I wrote an HSL (hue, saturation, lightness) to RGB converter. This helps:
    * Color selection. Blue is hue=240, red is hue=360, and purple is hue = 300.
    * Lighten or darken colors. Just change lightness.
    * Rainbows. Just increment hue from 0 to 359.

* The patterns are separate objects and files, easy to add or remove.

