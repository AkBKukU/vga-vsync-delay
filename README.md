# VGA V Sync Delay

VGA V Sync delay for Datapath VisionRGB capture cards that can't sync to some 640x480 signals. This is done with an Arduino microcontroller.

## How

The Arduino has the V Sync and H Sync for a VGA signal connected to its interrupts. It watches for a V Sync pulse and then starts a counter of H Sync pulses. When the counter reaches the value of a defined offset it begins a separate V Sync pulse that lasts for two lines.

The original V Sync signal should either be only connected to the Arduino or set with a switch to toggle between the original and delayed outputs. The delayed V Sync from the Arduino should be connected to the output connector.

The H Sync needs to be connected to both the Arduino and passed directly through to the output connector.
