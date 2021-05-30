Step 2: Making the Chassis

![drill](https://user-images.githubusercontent.com/67673221/120104672-579a5a80-c175-11eb-8069-d8e074c68037.JPG)



Drill two holes for motor:

![5](https://user-images.githubusercontent.com/67673221/120104763-caa3d100-c175-11eb-9b43-f6ff7d8e210d.JPG)



Connect two motors:



Make three holes for caster wheel:



![7](https://user-images.githubusercontent.com/67673221/120104769-d42d3900-c175-11eb-96bd-df0b8a26b68c.JPG)






Connect the caster wheel:


![8](https://user-images.githubusercontent.com/67673221/120104775-dd1e0a80-c175-11eb-9ed4-e891c671c032.JPG)



Make two holes on either side of the box for connecting the motors and three holes on the bottom for connecting the caster wheel after measuring and marking the correct diameter. Then install the motors and the caster.

Batteries


![0](https://user-images.githubusercontent.com/67673221/120104798-fa52d900-c175-11eb-814c-d962cfecb80f.JPG)



Connecting the batteries.



![2 battery](https://user-images.githubusercontent.com/67673221/120104838-3ab25700-c176-11eb-909a-453e4f0c54e1.JPG)




Connection diagram.




![++](https://user-images.githubusercontent.com/67673221/120104847-47cf4600-c176-11eb-9d56-a1d852610108.JPG)




Mount two 9 volt batteries inside the box above the caster. Then wire them in parallel and connect a switch as shown in above diagram.






Connecting the Arduino and Motor Shield



![--](https://user-images.githubusercontent.com/67673221/120104887-6b928c00-c176-11eb-919a-f5438f7d3e7d.JPG)




Attach the motor shield above the Arduino.



Connect the battery wires to the PWR terminals of motor shield.

Connect the motors to the motor shield.

Remove the jumper from this port.

Connect the motor shield above the Arduino and place it above the battery. Then connect the wires from the motors and battery to the motor shield. Check out the connection diagram before connecting, as it is very important.

Wiring Instructions:

Connect the left motor to "M1" of motor shield
Connect the right motor to "M3" of motor shield
Connect the the wire from battery to "ext pwr" of motor shield
Don't forget to remove the jumper from the "pwr" of motor shield
Make two holes and power the Arduino
Mark the spot to make holes. 

Make the holes.

Connect the battery clip to DC male jack to the 9V battery.

Place this 9 volt battery inside the box.

Make two holes for accessing the USB port and the DC input port of the Arduino. Take another 9 volt battery and connect a battery clip to a DC male jack adapter, then connect the DC male jack to the Arduino DC input port, to power the Arduino. Then place the battery between the motors and Arduino inside the box.

Connecting Bluetooth Module and Switch
Connect the Bluetooth module to the Arduino as shown in the connection diagram and place it inside the box. Then make hole to mount the switch on the back side of the box and connect the switch (here I have changed the switch which is used earlier because of some soldering problem).

Wiring Instruction of Bluetooth module:

"TX" of Bluetooth Module goes to "RX" of Arduino
"RX" of Bluetooth Module goes to "TX" of Arduino
"VCC" of Bluetooth Module goes to "5v" of Arduino
"GND" of Bluetooth Module goes to "GND" of Arduino
The State & Key pins of the BT modules are kept unused.
Overall Circuit diagram
Sensor Ultrasonic Mounting
Take the ultrasonic sensor and glue a small 'L' shaped plastic piece to it and glue it on top of the plastic box (or if you don't have a glue stick use double sided tape). Then connect the jumper wires to as shown in the circuit diagram above.

Wiring Instruction of ultrasonic sensor:

"VCC" of Ultra sonic sensor goes to "+5" of Arduino
"GND" of Ultra sonic sensor goes to "GND" of Arduino
"Trig" pin of Ultra sonic sensor goes to "Analog pin 1" of Arduino
"Echo" pin of Ultra sonic sensor goes to "Analog pin 0" of Arduino
Now we finished the all the connections and it's time to program.

Last step - Arduino codes and Bluetooth app editing
Upload the "Final Sketch" provided in the code section. If you face any error, make sure you have installed the AFmotor library.

Now, we learned how to program a Arduino easily. I have shown here some programs to work this robot as a obstacle avoiding robot, Wall follower, and Bluetooth controlled. and at last i have combined this three functions together. Watch the video for more details and information
