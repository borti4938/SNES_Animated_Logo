### Animated Logo for the SNES
---

This is an earlier project. This project is not under development anymore. Documentation is rather simple or simply not present.

Please don't write me for any support. Please reach out to community forums and use the knowledge and experiences there.

Best Regards, Peter

---

### From Original README

##### Installation

The PCB is designed to be assembled to the extension port of the ‘normal’ SNES.
/Rst is a combination of a pad and a jumper, which can be used as follows:
– connect the pad with a wire to CIC pad 10 (animation is repeated on a reset using reset button and the IGR (PIC-microcontroller code)
– close jumper: animation is repeated on every reset (I do not like this, e.g., because the sd2snes performs a reset on startup and the animation is started a second time while the initial animation is running)
– neither connect the wire or the close the jumper: animation is just played once

##### Others:

- Software: http://circuit-board.de/forum/index.php/Thread/7573-Super-Nintendo-Beleuchtetes-animiertes-Logo/ (can now be accessed here, too)
- Fuse Bits for the ATTiny45: lfuse: 0xe2, hfuse:w:0xdf
- The given resistor values for the LEDs (2x 180Ohm (yellow, red) and 2x 120Ohm (green, blue)) are just examples. You may adjust these values according to your needs :)
- LEDs are in 0805 or P-LCC-2 package.
