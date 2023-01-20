# Project II - Maskininlärning och sensorteknik (Machine learning and sensor technology ) - Ela21, YRGO

Supervisor: Erik Pihl 

By: Daniel Mentzer och Peter Strömblad
            
## Neuralt nätverk i ett inbyggt system (A neural network in an embedded system) 



## Introduction
In this project an artificial neural network was to be created with the purpose to sense the input signals of four buttons. In the other end of the neural network an LED was connected. If an even number of buttons was pressed the output signal should be 0/low otherwise the output should be 1/high and turn on an LED. The neural network was designed to work with nay number of nodes and hidden layers.  The program is running on a raspberry pi 4 with the gpiod library to manage the LED and buttons.





## Discussion

This project was the last project in our machine learning course and had lots of fun problems to solve. Our biggest issue in this assignment was to get the neural network to work with a higher number of input signals. We got our machine working easily with three buttons, see Fig. 1. Any number above three input signals seemed to only create faulty predictions no matter how many numbers of hidden layers, nodes or epochs we choose, see Fig. 2. We spent hours trying to understand why and tried one last thing, and it worked! 
To solve our issue, we had to change the activation function from ReLU to Tanh. We hardly knew other activation methods existed, so coming by this solution was quite fun. After this the rest was smooth sailing, and we could quite easily implement all other features we wanted.



## Artificial Neural Network



![alt text](https://github.com/peter-strom/rp_neural_network/blob/79120f8e67cc45bbf3da65b98d9f7b271186022d/img/fig1.png)

Fig.1 - Our machine running ReLU activation worked great with trhee input signals. 


![alt text](https://github.com/peter-strom/rp_neural_network/blob/79120f8e67cc45bbf3da65b98d9f7b271186022d/img/fig2.png)

Fig.2 - xxxxx. 


![alt text](https://github.com/peter-strom/MQTT-cpp/blob/master/bild3.png)

Fig.3 - xxxxx.




[![Watch the video](https://github.com/peter-strom/rp_neural_network/blob/79120f8e67cc45bbf3da65b98d9f7b271186022d/img/youtube.png)](https://youtu.be/20bjsbjJasY)

Movie.1 - Video of the neural net in action.
