# PART-C: Servo Motor Control System

## Summary
This configuration uses an Arduino Uno to operate two servo motors (Servo Motor A and Servo Motor B):
- A **push-button switch** allows toggling control between Servo A and Servo B.
- A **rotary potentiometer** adjusts the angle of the selected servo within a range of 0° to 180°.
- A **16x2 LCD display** provides real-time feedback, showing the active servo (e.g., "Servo: A" or "Servo: B") and its current angle (e.g., "Angle: 90").


## System Layout

```
+-----------------+
|   Arduino Uno   |
+-----------------+
        |
+-------+-------+-------+----------+
|               |       |          |
|               |       |          |
v               v       v          v
Potentiometer  Button  LCD      Servo Motors
 (Analog In)  (Digital In) (Digital Out) (PWM Out)
```

## Explanation
- **Potentiometer**: Rotational control to set the servo position.
- **Push-button**: Switches the control between Servo A and Servo B.
- **16x2 LCD**: Displays which servo is selected and its position angle.
- **Servo Motors**: Receive PWM signals from Arduino to set the desired angle.

## Visual Representation

![Servo Control System](Block_Diagram_2.png)

