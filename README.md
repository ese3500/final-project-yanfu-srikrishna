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

[Insert final project video here]

### 2. Images

[Insert final project images here]

### 3. Results

What were your results? Namely, what was the final solution/design to your problem?

Our final project, Deep's Dynamo, involved an autonomous vehicle that has the ability to avoid obstacles placed in its path. Additionally, the vehicle can be manually overriden/controlled wirelessly through the Blynk app if needed. An ultrasonic sensor mounted on a servo motor was used for obstacle detection, with periodic scans occurring to keep the system updated. An LCD screen with a "radar" displaying the angle of the servo was also included. 

#### 3.1 Software Requirements Specification (SRS) Results

Based on your quantified system performance, comment on how you achieved or fell short of your expected software requirements. You should be quantifying this, using measurement tools to collect data.

#### 3.2 Hardware Requirements Specification (HRS) Results

Based on your quantified system performance, comment on how you achieved or fell short of your expected hardware requirements. You should be quantifying this, using measurement tools to collect data.

### 4. Conclusion

Reflect on your project. Some questions to consider: What did you learn from it? What went well? What accomplishments are you proud of? What did you learn/gain from this experience? Did you have to change your approach? What could have been done differently? Did you encounter obstacles that you didn’t anticipate? What could be a next step for this project?

Overall, we feel that our project was a success since we were able to meet the general goal of making an autonomous vehicle that avoids obstacles by monitoring its surroundings. We are proud of what we were able to accomplish in the short time frame and felt that we approached the project design and execution processes in a rational manner. The project was able to be completed using only parts in Detkin, and we made a conscious decision to do so to avoid any potential challenges with delays in part orders. We also were able to adapt and be resourceful to achieve the desired functionality. For example, we decided to use an ultrasonic sensor mounted on a servo motor for obstacle detection since these were widely available in Detkin, and would be easier to implement in the short time frame associated with the project. However, we cannot simply mount this setup on top of the halbot since this means the ultrasonic sensor would be quite high off the ground, meaning many obstacles smaller in height would not be detected properly. This does not mean that we did not face any challenges during the development process however. Around an hour before our time slot on demo day, the halbot platform we used to complete the project began to emit smoke, which forced us to quickly adapt and migrate to a new halbot platform. Luckily, upon rewiring, the project still worked as intended. 
## References

Fill in your references here as you work on your proposal and final submission. Describe any libraries used here.

## Github Repo Submission Resources

You can remove this section if you don't need these references.

* [ESE5160 Example Repo Submission](https://github.com/ese5160/example-repository-submission)
* [Markdown Guide: Basic Syntax](https://www.markdownguide.org/basic-syntax/)
* [Adobe free video to gif converter](https://www.adobe.com/express/feature/video/convert/video-to-gif)
* [Curated list of example READMEs](https://github.com/matiassingers/awesome-readme)
* [VS Code](https://code.visualstudio.com/) is heavily recommended to develop code and handle Git commits
  * Code formatting and extension recommendation files come with this repository.
  * Ctrl+Shift+V will render the README.md (maybe not the images though)
