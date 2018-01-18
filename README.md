<h1>Particle Lamp</h3>

<img src="https://i1.wp.com/www.coreyalexandersmith.com/wp-content/uploads/2017/12/LampGIF.gif?resize=270%2C250&ssl=1">

<h3>Description</h3>

Particle Lamp is a 3D printed internet connected smart lamp. The lamp is equipped with and WiFi enabled Arduino and 176 individually addressable RGB leds. The lamp can be controlled through may different ways including:
<ul>
 	<li>Amazon voice assistant (Alexa)</li>
 	<li>iOS Application</li>
 	<li>watchOS Application</li>
 	<li>Web Application</li>
 	<li>IFTTT Applets</li>
</ul>


<h3>Table of Contents</h3>

<ul>
 	<li>Design</li>
 	<li>The build</li>
 	<li>Firmware</li>
 	<li>Web Application</li>
 	<li>Alexa Integration</li>
 	<li>iOS and watchOS Application</li>
 	<li>IFTTT Integration</li>
</ul>

<img src="https://i2.wp.com/www.coreyalexandersmith.com/wp-content/uploads/2017/12/LampMockUpCloseLights.png?ssl=1">

<h3>The build</h3>

<h4>Materials</h4>
Particle Photon- A WiFi enable micro-controller that is compatible with Arduino IED and the Particle Cloud.

Led Strip- I decided to go with an addressable led strip that would allow changing colors of individual leds. 5v input makes compatible with the Particle.

Power Supply- The led strip consume 18 watts/meter, the Particle uses 80mA on average. With four 3/4 meter led strips the max power consumption of the system is  aprox. 55 watts. So I selected a 5v 15Amp power supply just because it was cheaper that the 12Amp alternative.

Filament- I opted to use PLA because it is the easiest material to print. Using a black and clear color.



<img src="https://i0.wp.com/www.coreyalexandersmith.com/wp-content/uploads/2017/12/LampMockUpCloseRender.png?w=1145&ssl=1">


<h4>Design</h4>

The lamp was designed using Autodesk's Fusion 360 CAD software. I design the lamp in 4 different pieces that allowed for an easy print.

<img src="https://i0.wp.com/www.coreyalexandersmith.com/wp-content/uploads/2017/12/LEDLidBasic.jpg?w=1150&ssl=1">

<h5>Base</h5>
 
Made wide enough to  support the lamp and 15mm deep to house the micro controller and the starting support of the lamp core.

<img src="https://i0.wp.com/www.coreyalexandersmith.com/wp-content/uploads/2017/12/LEDLidBasic.jpg?w=1150&ssl=1">

<h5>Lid</h5>

Just something enclose the micro controller and to help support the core.


<img src="https://i0.wp.com/www.coreyalexandersmith.com/wp-content/uploads/2017/12/LEDCoreBasic.jpg?ssl=1">

<h5>Lamp Core</h5>

I design the core to hold 11 led's each and at 183mm high it can he printed on just about any 3D printer.

<img src="https://i0.wp.com/www.coreyalexandersmith.com/wp-content/uploads/2017/12/LEDSleaveBasic.jpg?w=1150&ssl=1">

<h5>Lamp Sleeve</h5>

The sleeve slides over the core and locks inside the base to support the core. At just 1mm thick it will be just thick enough so that the clear PLA will be cloudy and disperse the led's nicely.

<h5>Firmware</h5>

I used the <a href="https://github.com/FastLED/FastLED">FastLED</a> library to make it easy to handle addressing and assigning colors to the leds. With the FastLED library I could assign four arrays of type CRGB that would represent the four led strips. I then set up three partial cloud functions, one to change the color, another to adjust the brightness, and lastly one to deal with notifications. In addition to the cloud function I declared a partial variable so that I can see what is the status of the lamp from any device.

<img src="https://i2.wp.com/www.coreyalexandersmith.com/wp-content/uploads/2017/12/webAPP.jpg?ssl=1">

<h3>Web Application</h3>

The goal form the beginning was to control the lamp through Alexa, but to make sure that the firmware is working perfectly I chose to make a simple web app hosted on my website so that I can access and test from anywhere.

<img src="https://i2.wp.com/www.coreyalexandersmith.com/wp-content/uploads/2016/08/alexa.jpg?w=1000&ssl=1">

<h3>Alexa Integration</h3>


In order to communicate with the lamp I needed to build two things, an Alexa skill and a cloud function. The Alexa skill is hosted on the device and is responsible for sending JSON data to cloud function. I chose to utilize Amazon's lambda for ease of use with the Alexa skill. The lambda function parses the incoming JSON data and ether calls the appropriate particle cloud function or returns with and error. In the event of an error Alexa will tell the user that the command was invalid and suggest a correct command.

Some things you can ask Alexa:

Alexa, ask Lamp to turn blue.
Alexa, tell Lamp to set brightness 4.
Alexa, ask Lamp to turn off.
Alexa, ask Lamp for help.

</div>

<h3>iOS and watchOS Application</h3>


I found my self using the web app on my phone quite regularly but it was slow. I decided to combat this by making a native iOS application. I built this application using Swift 4. The native app speed up the process substantially.  In fact it had exceeded my expectation. I am now able to change the color of the lamp in less than a second even when the app is not in the background.  I thought why stop there, so I make a watchOS app as well  to control a few common lighting schemes.


<img src="https://i2.wp.com/www.coreyalexandersmith.com/wp-content/uploads/2017/12/lampWatchPhone.png?ssl=1">

 
<h3>IFTTT Integration</h3>


I configure a couple of IFTTT Applets that call the notification function on the Participle. At this moment I have only two active applets, one that flashes the lamp red when I get a personal email and anther that strobes purple when any Twitch streamer I fallow goes live. Endless possibility here due to the huge network of API's IFTTT has access to.

</div>

 
<h3>References</h3>
<ul>
  <li><a href="https://github.com/rlisle/alexaParticleBridge">Particle Datasheet</a> </li>
  <li><a href="https://github.com/FastLED/FastLED">FastLED</a> </li>
  <li><a href="https://github.com/rlisle/alexaParticleBridge">alexaParticalBridge</a> </li>
  <li><a href="https://developer.amazon.com/alexa">Amazon Alexa Documentation</a> </li>
  <li><a href="https://aws.amazon.com/lambda/">Amazon Lambda Documentation</a> </li>
  <li><a href="https://platform.ifttt.com/maker/guide">IFTTT Developer Documentation</a> </li>

</div>
</div>
</div>
</div>
</div>
