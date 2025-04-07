Teensy audio project written in C++. Made for use as a low latency master FX chain for live performance. Takes two audio inputs, one for kick, one for main mix. Applies volume gate ducking, recombines signals, and applies compression and effects before passing to audio output. 
### Implements: 
- Volume gate ducking
- Peaked branch detector compressor class

### To-do: 
- Parametric EQ
- I2C knobs and faders
- Saturator

### Compressor references: 
- https://eecs.qmul.ac.uk/~josh/documents/2012/GiannoulisMassbergReiss-dynamicrangecompression-JAES2012.pdf
- https://raw.githubusercontent.com/p-hlp/CTAGDRC/refs/heads/master/Documentation/Base-Diagram.png

### Protoboard: 
![signal-2025-04-07-122601](https://github.com/user-attachments/assets/3f9a0e9e-b30d-4a67-b71d-3f2196a5552a)
