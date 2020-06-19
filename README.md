# Multi-Filter-Delay
An original digital audio effect programmed through Juce/C++. Some potential uses for the plugin are to create complex polyrhythms from very simple section of MIDI drums, apply
delays to multiple instruments from a single audio recording separately and delay different
frequency bands within a single sound individually. The audio effect has the following features:
* 3 separate delays of the same signal with the following adjustable parameters:
  * Delay time, in terms of milliseconds or sixteenth notes
  * Feedback
  * Filter Type e.g. No-Filter/Low-Pass/High-Pass
  * Filter Cutoff, in Hz
  * Ping Pong Delay e.g On/Off
  * Gain, in dB
* Dry/Wet knob for specifying mix of the Dry and Wet signals
* Power switches for each delay to activate/deactivate delay

The audio effect was created in Juce using C++, with Ableton
Live 10 and Microsoft Visual Studio used for debugging.

![Mult-Delay GUI](https://github.com/lbros96/Multi-Filter-Delay/blob/master/GUI.PNG?raw=true)
