# paddleboard
Digispark morse key interface

This is a very simple method of using an an inexpensive Digispark development board to work as an interface for morse key/paddle for Ham Radio Solutions's [vband](https://hamradio.solutions/vband/) (Virtual CW Band).

Setting up the USB drivers was the most difficult part for me, but [this video](https://www.youtube.com/watch?v=MmDBvgrYGZs) helped me get it sorted out. 

To connect your paddle to the digispark, you can use a 3-pole (TRS) 3.5mm pigtail plug, soldering the tip (left paddle) to P0, the ring (right paddle) to P2, and the sleeve to ground. Note that without an external pull-up resitor P1 will always read `LOW`, but P0 and P2 work just fine with no additional resistors. Pins 3 and 4 can't be used while the board is connected via USB.

Install the sketch to the board. Now your key will look like a usb keyboard that just presses left and right `Ctrl` keys with your paddles. It should also work fine with a straight key.

Some inspiration was taken from https://github.com/kevintechie/CWKeyboard, but this is a much simpler set-up.
