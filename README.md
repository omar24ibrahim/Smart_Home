# Smart Home
Using Arduino Uno to implement a sample of smart home automation with 6 functions placed in a hand-made maqeutte.
## 1. Overview:
Automation (such as home automation and industrial automation) has become important in today’s world as it helps to complete a task with lesser human assistance and in a smarter way. Houses are becoming smarter and developed these days with the help of automation devices.
Home electrical appliances are using remote-controlled switches rather than conventional switches. In today’s world, most people have access to smartphones and their use has become very popular and essential in our lives. We can use smartphones to control household appliances with just one click or one message. With the help of controllers and communication devices home appliances can be remotely controlled.  In this project, we will use the Arduino UNO board for the development of Smart Home Automation project with the HC-05 Bluetooth module which is remotely controlled by a smartphone.
This project is an example of smart home automation using a small house prototype model.

## 2. Components:
- Small house prototype model

- Arduino UNO

- Bluetooth Module HC-05

- PIR motion sensor

- IR flame sensor (3-pin)

- Water level/detection sensor

- Photo-resistor LDR light sensor 

- MQ-4 gas sensor 

- DHT22 temperature and humidity sensor 
## 2.1. Smart Home Model:
Made of photo hole based on MDF board, it consists of only a kitchen, a dining room, and a backyard representing a section of a house to show the essential functions in the house that may get repeated in other rooms and sectors of the house. The model contains the following functionalities: detection of motion in the dining room, detection of flame in the kitchen, detection of rain in the backyard, detection of light in the backyard to enable ambient light in the night, detection of gas leakage in the kitchen, and measuring temperature and humidity in the dining room.
## 2.2. Arduino UNO: 
Arduino UNO is a single-board microcontroller developed by the Arduino Company. In this project, it is the brain of the smart home automation as it controls the functionality of all the sensors and the Bluetooth module through a source code implemented for each sensor through the Arduino IDE (Integrated Development Environment). The Arduino Uno components are shown in the figure below: 

**2.2.1. USB Connector:**

The USB Connector is used to upload the code from the Arduino IDE onto the Arduino board. It is also used to power up the board (just like the power port). 

**2.2.2. Digital Pins:**

Arduino Uno has 14 digital pins. Digital pins can be used as either input or output pins. These pins are connected to the sensors to connect the board to them and implement the Arduino code in the sensors. When used as output, these pins act as a power supply source for the components connected to them. When used as input pins, they read the signals from the component connected to them. 

**2.2.3. Analog Pins:**

The Arduino UNO board has 6 analog input pins, labeled “Analog 0 to 5.” These pins can read the signal from an analog pin of some sensors like gas sensor and perform certain task depending on the accurate value read from the sensor.
## 2.3. PIR Motion Sensor:
PIR motion sensor is designed for motion detection, is used to detect human presence in indoors in alarm and lighting systems. PIRs are made of pyroelectric sensors, a round metal can with a rectangular crystal in the center, which can detect levels of infrared radiation. Everything emits low-level radiation, and the hotter something is, the more radiation is emitted. 
The sensor in a motion detector is split into two halves. This is to detect motion (change) and not average IR levels. The two halves are connected so that they cancel out each other. If one-half sees more or less IR radiation than the other, the output will swing high or low. This sensor has 3 pins: Ground, VCC, and digital out.
- Ground Pin: Connected to the ground on the Arduino board
- VCC:  Connected to the 5v output of the Arduino Board
- Digital Out: generates the pulse (high) in case of detected body motion. 
(Connected to pin 4 on Arduino Board)
(Response of sensor is LEDs connected to pin 10 on Arduino Board)
## 2.4. IR Flame Sensor (3-pin):
The flame sensor is used to trigger a buzzer and it alerts the user through the mobile application on their phone whenever it detects fire in the smart home. This sensor basically detects IR (Infrared) light wavelength between 760 nm – 1100 nm that is emitted from the fire flame or light source. 
The IR flame sensor is active low so the D0 pin’s output is low whenever the sensor detects fire otherwise, the D0 pin’s output is high.
- Ground Pin: Connected to the ground on the Arduino board
- Vcc:  Connected to the 5v output of the Arduino Board
- D0 (Digital Out): output low when a flame is detected and high otherwise. 
(Connected to pin 2 on Arduino Board) 
(Response of sensor is Buzzer connected to pin 5 on Arduino Board)
## 2.5. Water Level/Detection Sensor:
This sensor is used to detect the presence of water for purposes such as providing an alert in time to prevent water leakage or detecting the presence of rain…etc.
In this project, the water sensor is used to detect the presence of rain. The output pin of the sensor generates an analog output but in case of this project, it is required just to tell the user via the mobile application on his phone if there is rain or not. The sensor is used for the detection of water not measuring its level.
In other words, it is required from the sensor to tell if there is water or not, so the output pin of the sensor is connected to a digital pin on the Arduino Board in order to read output high in case of water presence (rain) or low in case of no water presence (no rain). 
- Ground Pin: Connected to the ground on the Arduino board
- VCC:  Connected to the 5v output of the Arduino Board
- Analog Output: Generates a signal in case of detection of water
(Connected to pin 8 on Arduino Board)
(Response of sensor is Message displayed on the User’s Application) 
## 2.6. Photo-Resistor LDR Light Sensor:
LDR light sensor is used to detect light. This sensor has an onboard LDR (Light Dependent Resistor), that helps it to detect light. The output of the module goes high in the absence of light and it becomes low in the presence of light (Active Low). 
The most obvious application for an LDR is to automatically turn on a light at a certain light level. An example of this could be a streetlight or a garden light as it used in the smart home.
LDR or Light Dependent Resistor:
LDR or Light Dependent Resistor is one type of variable resistor. It is also known as a photoresistor. The Light Dependent Resistor (LDR) works on the principle of “Photo Conductivity”. The LDR resistance changes according to the light intensity that falls on the LDR.  When light intensity increases on the LDR surface, then the LDR resistance will decrease, and the element conductivity will increase. When light intensity decreases on the LDR surface, then the LDR resistance will increase, and the element conductivity will decrease.
- Ground Pin: Connected to the ground on the Arduino board
- Vcc:  Connected to the 5v output of the Arduino Board
- D0: Output low when certain light intensity (threshold) is detected and high otherwise.
(Connected to pin 3 on Arduino Board)
(Response of sensor is LEDs connected to pin 6 on Arduino Board)
## 2.7. MQ-4 Gas Sensor:
It is used to detect any gas leakage in our smart home project. The sensor is used to trigger a buzzer and alert the user through the mobile application on his phone whenever a gas leakage happens.
This sensor detects a wide range of flammable gases, especially natural gas, and is a low-cost sensor for a variety of applications (ex: detection of gas leakage). The MQ-4 gas sensor has high sensitivity to butane, propane, and methane, and has a good balance between methane and propane.
The sensor is enclosed in two layers of fine stainless-steel mesh called Anti-explosion network. It ensures that heater element inside the sensor will not cause an explosion, as we are sensing flammable gases.
- Ground Pin: Connected to the ground on the Arduino board
- VCC:  Connected to the 5v output of the Arduino Board
- AOUT: Generates a signal carrying information about the value of detected gas leakage
(Connected to pin A5 on Arduino Board)
(Response of sensor is Buzzer connected to pin 11 on Arduino Board)
## 2.8. DHT Temperature and Humidity Sensor:
This sensor is used to measure the temperature and humidity of surrounding air. It provides readings through the mobile application on the user’s phone.
The DHT22 is a low-cost digital temperature and humidity sensor with a single wire digital interface. It uses a capacitive humidity sensor and a thermistor to measure the surrounding air and spits out a digital signal on the data pin (no analog input pins needed).
The sensor is calibrated and doesn’t require extra components so you can get the right of measuring relative humidity and temperature.
It is quite simple to use but requires careful timing to grab data. You can only get new data from it once every 2 seconds.
- Ground Pin: Connected to the ground on the Arduino board
- VCC:  Connected to the 5v output of the Arduino Board
- Data pin: Generates digital signal carrying information about the surrounding temperature as well as relative humidity
(Connected to pin 7 on Arduino Board)
(Response of sensor is Message displayed on the User’s Application)
## 2.9. Bluetooth module HC-05:
HC-05 is a Bluetooth module that is designed for wireless communication. It is used in the project to connect the Arduino Board wirelessly to the user’s phone via a mobile application.
