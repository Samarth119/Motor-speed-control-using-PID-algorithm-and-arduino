# Motor-speed-control-using-PID-algorithm-and-arduino
Task of controlling the speed of motor with the the help of PID is achieved by using encoder which reads the rpm of motor shaft.
the encoder has two data pins and one of them is work like an interrupt signal to count the pulses and the other data signal is used to know the direction of rotation.
the software interrupt is used, which runs a fuction "ISR" where we calculate the rpm and then using that rpm as the input for pid algorithm we calculate the desired speed
