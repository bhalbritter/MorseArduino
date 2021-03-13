# MorseArduino
The goal was to send a string of characters using an Arduino program in Morse code Arduino. This receives the data with the help of a light sensor and then converts it back into a string that it also outputs.
![image](https://user-images.githubusercontent.com/63356794/111038530-d6f77800-8429-11eb-838e-05fca8cc56c7.png)

## Transmitter
### Sequence of the program: 
The user starts the program and is asked to enter the string to be sent.
This string is passed to the printmorse method.
In the setup method first the laser is switched on, then the program waits for an input. When this has been entered, it is passed to the corresponding printmorse method.
This method converts the individual characters using the ascii2morse method.
![image](https://user-images.githubusercontent.com/63356794/111038631-600eaf00-842a-11eb-9a61-9ce2b46c9218.png)
![image](https://user-images.githubusercontent.com/63356794/111038633-62710900-842a-11eb-89ea-5da0cedc9f08.png)
In the ascii2morse method the respective Morse code is returned from the single character via a switch. Thereby '.' stands for short and '-' for long.

## Receiver
### Sequence of the program: 
The user starts the program and the method getData() is called. There a do/while loop runs through and counts every 100 milliseconds a counter variable up by 1 if the sensor detects a brightness of at least 910, i.e. the laser is on. This way you can determine how long the laser is on. This way the whole string is assembled bit by bit.

# Problems encountered:

### Software Problems encountered:

#### What is the best and fastest way to read in the Morse code?
The first goal was that I first leave the time outside to concentrate on the transmission itself. My idea was to measure in a loop how long the light sensor has a higher value. So the laser is on. In the loop I have a counter which is incremented by 1 every 1000 milliseconds. This allows me to determine exactly how long the laser is on. This can then be easily reacted to afterwards.


#### How did I speed up the whole thing?
Increasing the transmission rate was quite easy, because I simply had to divide the repetition rate of the loop and the duration of a long or short signal by 10. 



### Hardware Problems encountered:

#### Light sensor always delivers the maximum value: 
This problem came about because I had connected the sensor the wrong way round and could only be solved by trying for a long time.

#### The light sensor reacts spontaneously hardly or not at all to the laser:
This problem is related to the brightness in the room and could be solved by a simple folder as a sunshade.


