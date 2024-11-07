# Distance-Based Warning System with Arduino

This project is a **Distance-Based Warning System** created using an Arduino, an ultrasonic sensor, three LEDs, and a potentiometer. The system is designed to visually indicate the proximity of objects detected by the ultrasonic sensor. The system was first tested virtually on Tinkercad, where it was assembled and simulated to ensure proper functionality. Once the simulation succeeded, the physical build was constructed, tested, and documented in a video.

## Project Description

The Distance-Based Warning System operates as follows:
- **Distance Detection**: The ultrasonic sensor measures the distance to the nearest object.
- **LED Indication**: Based on the measured distance, different LEDs light up:
  - **Green LED**: Lights up if the object is beyond 20 cm.
  - **Yellow LED**: Lights up if the object is between 10 cm and 20 cm.
  - **Red LED**: Lights up if the object is closer than 10 cm.
  - **Flashing Mode**: If the distance is particularly large, all LEDs flash on and off together.
- **Adjustable Thresholds**: A joystick allows real-time adjustment of the distance thresholds, providing flexibility in setting proximity ranges.

After completing the Tinkercad simulation, the same setup was built physically using Arduino components. A video was recorded to document the assembly and demonstrate the system's response to varying distances, showing the joystick's effect on distance thresholds.

## Code Overview

The Arduino program controls the distance-based warning system using the following components:
- **Ultrasonic Sensor (HC-SR04)**: Measures the distance to an object.
- **LEDs**: Three LEDs (Green, Yellow, Red) provide visual feedback based on distance thresholds.
- **Potentiometer**: Adjusts the threshold distances dynamically.

### Code Description

1. **Pin Setup**: Define the pins for the ultrasonic sensor (`trigPin` and `echoPin`), LEDs (`led1Pin`, `led2Pin`, `led3Pin`), and the potentiometer (`potPin`).
  
2. **Threshold Mapping**: Read the potentiometer value and map it to set the distance thresholds (`threshold1`, `threshold2`, `threshold3`). The potentiometer value provides flexible adjustments to the range values.
  
3. **Distance Calculation**:
   - Send a pulse from the `trigPin` to trigger the ultrasonic sensor.
   - Measure the echo duration on the `echoPin` and calculate the distance.

4. **LED Logic**:
   - If the object is closer than `threshold1`, all three LEDs light up.
   - If the object is between `threshold1` and `threshold2`, two LEDs turn on.
   - If the object is between `threshold2` and `threshold3`, only one LED is on.
   - If the object is beyond `threshold3`, all LEDs blink together at a set interval.

5. **Flashing Mode**: For distances beyond the third threshold, the LEDs flash on and off together at a fixed interval (`interval` set to 500 ms).
