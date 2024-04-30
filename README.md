[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-24ddc0f5d75046c5622901739e7c5dd533143b0c8e959d652212380cedb1ea36.svg)](https://classroom.github.com/a/2TmiRqwI)
# final-project-skeleton

    * Team Name: Deep's Dynamo
    * Team Members: Yanfu Ou and Srikrishna Chakravarthi
    * Github Repository URL: https://github.com/ese3500/final-project-yanfu-srikrishna
    * Github Pages Website URL: [for final submission]
    * Description of hardware: HP ENVY x360, MacBook Air (embedded hardware, laptop, etc) 

## Final Project Proposal

### 1. Abstract

In a few sentences, describe your final project. This abstract will be used as the description in the evaluation survey forms.

We are looking to build a small car-like robot which is self-driving and can avoid obstacles by mapping its surroundings. We hope to make our own scaled down version of an autonomous vehicle!

### 2. Motivation

What is the problem that you are trying to solve? Why is this project interesting? What is the intended purpose?

The problem we are trying to solve is autonomous navigation across warehouse spaces while avoiding collisions with obstacles and other robots. We envision that a human worker can place an object on our robot, which can then be transported from point A to B without the worker having to do it him/herself. The usage of the ultrasonic sensor to sweep 360 degrees to map objects in the surroundings makes this project interesting. Additionally, the autonomous navigation around the detected obstacles will make this project more interesting. The intended purpose of this project is to further automate warehouses and reduce human intervention.

### 3. Goals

These are to help guide and direct your progress.
Goal number: 
1. Mount and connect ultrasonic sensor on top of rotating servo/motor
2. Read in values from the untrasonic sensor and be able to detect objects
3. Map surrounding objects and store their location
4. Create the rover base and mount motors and wheels
5. Connect and wire up the motor with the power management system 
5. Mount the rotating ultrasonic senesor on the rover base
6. Program the autonomous obstacle avoidence algorithm


### 4. Software Requirements Specification (SRS)

Formulate key software requirements here.

The software component would be responsible for sensor collection, analysis, and decisions. First, we take in the ultrasonic sensor information to determine the distance to the obstance and combine it with the servo angle to determine the poisition of obstacles. The robot will act on the information and determine how to steer and move the robot. There will also be an IoT component where we connect with a remote device/controller that allows manual override if necessary. 

### 5. Hardware Requirements Specification (HRS)

Formulate key hardware requirements here.
The untrasonic sensor will be responsible for connecting information while the servo will serve to rotate the sensor to get 360 degrees of detection. The motors on the base of the rover will serve to provide torque and move the robot. A battery will serve to provide power for the robot. We will most likely need to implement power management system depending on the requirements of the components. 

### 6. MVP Demo

What do you expect to accomplish by the first milestone?

We hope to get a ultrasonic sensor-based radar system working which can map out the surroundings/detect the presence of obstacles.

### 7. Final Demo

What do you expect to achieve by the final demonstration or after milestone 1?

By the final demonstration, we hope to have a robot which is able to move around on it's own and avoid obstacles which are placed in its path. 
### 8. Methodology

What is your approach to the problem?

In working on this project, we will use modular design and work in steps. We will first work on just using an ultrasonic sensor mounted on a servo motor and coding it such that we can sweep the position of the sensor around and map the surroundings. Once we get this part to work, we work on the robot part, getting the motors/wheels to work, as well as manually control it to make sure the mechanical parts work as intended. Once the robot moves around as intended, we will combine the two parts by mounting the ultrasonic-based obstacle detection system onto the robot, while including code to allow for automated, self-driving abilities of our robot. Then, if time permits, we can include a feature (perhaps an app), to remotely control/manually takeover the robot as a failsafe in case something goes wrong. 

### 9. Components

What major components do you need and why?

We need an ultrasonic sensor to detect the presence of obstacles. We also want to have a servo on which the sensor is mounted. This will allow the sensor to be swept across different angles such that the surroundings are mapped. We will need a battery and power management IC(s) to control the power to the peripherals. We will also need a chasis and base for the robot to move around.  

### 10. Evaluation

What is your metric for evaluating how well your product/solution solves the problem? Think critically on this section. Having a boolean metric such as “it works” is not very useful. This is akin to making a speaker and if it emits sound, albeit however terrible and ear wrenching, declare this a success.
It is recommended that your project be something that you can take pride in. Oftentimes in interviews, you will be asked to talk about projects you have worked on.

When testing our project, we will see what types of obstacles the robot is able to detect/avoid as well as how repeatable the process is for detection/avoidance. We can correlate the success of our project with the number of types of obstacles the robot is able to avoid. The smaller the rate of collision, the better. 

### 11. Timeline

This section is to help guide your progress over the next few weeks. Feel free to adjust and edit the table below to something that would be useful to you. Really think about what you want to accomplish by the first milestone.

| **Week**            | **Task** | **Assigned To**    |
|----------           |--------- |------------------- |
| Week 1: 3/24 - 3/31 |  Ultrasonic sensor & servo working and plotting   |       both      |
| Week 2: 4/1 - 4/7   | Assembling the mechanical parts of the robot functioning as intended    |     both     |
| Week 3: 4/8 - 4/14  |  Attach sensor to robot    |         both        |
| Week 4: 4/15 - 4/21 |   Program manual control    |          both      |
| Week 5: 4/22 - 4/26 |   Program autonomous control and manual override    |         both        |

### 12. Proposal Presentation

Add your slides to the Final Project Proposal slide deck in the Google Drive.

## Final Project Report

Don't forget to make the GitHub pages public website!
If you’ve never made a Github pages website before, you can follow this webpage (though, substitute your final project repository for the Github username one in the quickstart guide):  <https://docs.github.com/en/pages/quickstart>

### 1. Video

[[Final Project Video]](https://www.youtube.com/watch?v=1S5jGHQ7WVk) 

### 2. Images

![20240429_225123](https://github.com/ese3500/final-project-yanfu-srikrishna/assets/122131796/b0c941b9-4f08-4bc5-b70d-1fb72213ef54)

![20240429_233456](https://github.com/ese3500/final-project-yanfu-srikrishna/assets/122131796/acee5d81-8008-4f9b-aa3b-c5420ece4038)
![20240429_225123](https://github.com/ese3500/final-project-yanfu-srikrishna/assets/122131796/15d9f475-2d57-4812-9d74-efee579c65e3)
![20240430_000805](https://github.com/ese3500/final-project-yanfu-srikrishna/assets/122131796/b69cd502-69e6-4ea2-b5cd-5b6932bdc626)


### 3. Results

What were your results? Namely, what was the final solution/design to your problem?

Our final project, Deep's Dynamo, involved an autonomous vehicle that has the ability to avoid obstacles placed in its path. Additionally, the vehicle can be manually overriden/controlled wirelessly through the Blynk app if needed. An ultrasonic sensor mounted on a servo motor was used for obstacle detection, with periodic scans occurring to keep the system updated. An LCD screen with a "radar" displaying the angle of the servo was also included. 

### NOTE: For the Software and Hardware Requirements, we lost points during the proposal stage (due to not having a detailed enough list). For this reason, we came up with a new list of hardware and software requirements before starting on our project. This is the list that I am including/commenting on below. 

#### 3.1 Software Requirements Specification (SRS) Results

Based on your quantified system performance, comment on how you achieved or fell short of your expected software requirements. You should be quantifying this, using measurement tools to collect data.

SRS 01 - Timer 0, an 8-bit timer, shall be used to control the motor in PWM mode. 

This is exactly what we implemented! We set up the registers/pins properly to enable Timer 0, and connected the servo motor's PWM pin to PD5 (the pin associated with Timer 0). Note that for the PWM mode, we chose phase-correct PWM since the signals are symmetric.

SRS 02 - Timer 1, a 16-bit timer, shall be used to control the echo pin of the ultrasonic sensor in PWM mode.

SRS 03 - Timer 2, an 8-bit timer, shall be used to control the trigger pin of the ultrasonic sensor in PWM mode. 

SRS 04 - The UART serial communication protocol shall be used to send commands between the two ATMEGA328PBs as well as between the one ATMEGA328PB and the ESP32. 

SRS 05 - Utilize Timer 1's interrupt to detect the reflected signal via the echo pin and translate the echo signal's time into a distance. 

SRS 06 - There shall be a wireless IoT based control mechanism allowing for manual control of the vehicle through the Blynk app.


#### 3.2 Hardware Requirements Specification (HRS) Results

Based on your quantified system performance, comment on how you achieved or fell short of your expected hardware requirements. You should be quantifying this, using measurement tools to collect data.

HRS 01 - Our system shall use two ATMEGA328PBs - One to control the LCD screen and the other to control the movement of the autonomous vehicle itself. 

HRS 02 - An ultrasonic sensor shall be used for obstacle detection. It shall detect obstacles at a distance 12cm or closer from the front of the vehicle. 

HRS 03 - The ultrasonic sensor shall be mounted on top of a servo motor. The servo motor should rotate 360 degrees to help enable scanning for obstacles around the vehicle by the ultrasonic sensor.

HRS 04 - We shall use an ESP32 for interfacing with the Blynk app, thereby enabling wireless control of the vehicle via phone.

HRS 05 - We shall utilize a 128x160 LCD screen to display a radar indicating the ultrasonic sensor's sweep. The display will interface with the corresponding ATMEGA328PB through the SPI protocol.

### 4. Conclusion

Reflect on your project. Some questions to consider: What did you learn from it? What went well? What accomplishments are you proud of? What did you learn/gain from this experience? Did you have to change your approach? What could have been done differently? Did you encounter obstacles that you didn’t anticipate? What could be a next step for this project?

Overall, we feel that our project was a success since we were able to meet the general goal of making an autonomous vehicle that avoids obstacles by monitoring its surroundings. We are proud of what we were able to accomplish in the short time frame and felt that we approached the project design and execution processes in a rational manner. The project was able to be completed using only parts in Detkin, and we made a conscious decision to do so to avoid any potential challenges with delays in part orders. We also were able to adapt and be resourceful to achieve the desired functionality. For example, we decided to use an ultrasonic sensor mounted on a servo motor for obstacle detection since these were widely available in Detkin, and would be easier to implement in the short time frame associated with the project. However, we cannot simply mount this setup on top of the halbot since this means the ultrasonic sensor would be quite high off the ground, meaning many obstacles smaller in height would not be detected properly. As a result, we used a piece of cardboard with a strategically placed hole that extends out from the rest of the chassis as a means to hold the servo/ultrasonic sensor, and this cardboard doubled as a "bumper" to protect the rest of the car in the event of an accidental collision. This does not mean that we did not face any challenges during the development process however. On the morning of the demo day, before our assigned time slot, the halbot platform we used to complete the project began to emit smoke, which forced us to quickly adapt and migrate to a new halbot platform. Luckily, upon rewiring, the project still worked as intended. However, due to the time spent debugging and making the transition onto the new platform, we were forced to refrain from adding certain features we initially wanted to. For example, in our radar, we do not show the position of the detected obstacle on the screen - a feature that we wanted to implement initially. 
## References

Fill in your references here as you work on your proposal and final submission. Describe any libraries used here.
1) We used the LCD library from Lab 4: Pong to draw the radar on the LCD screen.  
2) We used the Blynk library from Lab 4 to enable manual control of the motors via the Blynk app using the ESP32.
3) We used the uart.c library file provided in prior labs to enable sending of data from the ATMEGA328PB.
### Appendix
1) We used the HardwareSerial library (https://github.com/espressif/arduino-esp32/blob/master/cores/esp32/HardwareSerial.h) to facilitate serial communication between the Atmega328PB and ESP32. This library was not provided in any of the labs, but is an open source one that we decided to use. The library provides an interface to communicate with hardware serial ports (RX and TX) on the ESP32 microcontroller. It allows for the sending and receiving of data using the UART communication protocol. The ESP32 itself has 3 hardware serial ports, with the first one (UART0) being reserved for programmming the device itself, leaving the other two ports (UART1 and UART2) available for use in a project - exactly what this library enables by defining the pins associated with UART0, UART1, and UART2. The library provides a way of setting up the parameters and configuration for the serial communication, with many options provided in "enum SerialConfig". For example, in our project, we stuck with the commonly used "SERIAL_8N1", meaning whenever data is sent, there will be one start bit, eight data bits, no parity bit, and one stop bit. Furthermore, the baud rate, or the rate at which data is being transmitted, can be specified for each of the hardware serial ports. The library defines many methods for configuring and interacting with the serial ports. "Begin" starts the serial communication process at a certain baud rate; "end" finishes the serial communication process; "write" allows for the sending of data; "read" allows for receiving and decoding the incoming data; "available" checks and returns the number of bytes which are available for reading within the specified serial port etc. In this project, we used UART1 to receive data using the ESP32, and whenever bytes are available for reading, we read the incoming data and print it out using UART0. 

## Github Repo Submission Resources

You can remove this section if you don't need these references.

* [ESE5160 Example Repo Submission](https://github.com/ese5160/example-repository-submission)
* [Markdown Guide: Basic Syntax](https://www.markdownguide.org/basic-syntax/)
* [Adobe free video to gif converter](https://www.adobe.com/express/feature/video/convert/video-to-gif)
* [Curated list of example READMEs](https://github.com/matiassingers/awesome-readme)
* [VS Code](https://code.visualstudio.com/) is heavily recommended to develop code and handle Git commits
  * Code formatting and extension recommendation files come with this repository.
  * Ctrl+Shift+V will render the README.md (maybe not the images though)
