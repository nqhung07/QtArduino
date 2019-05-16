# QtArduino
***This project is building****
Control Arduino by Qt app via Serial Port and Wireless

Update commit: Control LED lightness
- Arduino: read data from serial port to change value of LED 13, received 1 byte data
- QtApp: 
  + Send data to serial port when move slider (0-255), send 1 byte data.
  + Received data from serial port (resend value which send to arduino).
