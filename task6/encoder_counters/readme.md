# Arduino Rotary Encoder Counter

## Overview

- This Arduino skitch  utilizes a rotary encoder to count pulses. 
By using the train of impulse from A, and B signals , we can get more precise Accurate counts.

- using a interrupt to get the signal from the pin __2__ ,__3__  and make the type of this is change to get more accurate 

## Filter 

making a low pass filter to avoide a noise and the 

```py
# Given values
Pulse_per_rotation = 540  # Pulses Per Revolution
wheel_radius = 40  # cm
max_speed = 0.5  # m/s

# Calculate distance per rotation of the wheel
distance_per_rotation = 2 * np.pi * wheel_radius /100 
rotation_per_sec = max_speed / distance_per_rotation             # RPS
Pulse_per_sec = Pulse_per_rotation * rotation_per_sec            #PPS 
```

>we can calculate the cutt frequncy __is: 107HZ__