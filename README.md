# drawdio-pico
Drawdio implementation using Raspberry Pi Pico

## What is drawdio?
Drawdio is a musical instrument based on impedance measurement. In this repository, you will find an implementation for the Raspberry Pi Pico, which features
a RP2040 microcontroller.

## How do I build it?
You only need:
- A RPi Pico
- 1MOhm resistor
- A buzzer
- A pencil
- Some wires

This program reads the voltage from a voltage divider made of the resistor and your own body, and plays a mapped voltage to the buzzer pin.