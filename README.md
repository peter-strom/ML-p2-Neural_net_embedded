# Project II - Machine learning and sensor technology - Ela21, YRGO

Supervisor: Erik Pihl 

By: Daniel Mentzer och Peter Strömblad
            
## A neural network in an embedded system

## Introduction
In this project an artificial neural network was to be created with the purpose to sense the input signals of four buttons. In the other end of the neural network an LED was connected. If an even number of buttons was pressed the output signal should be 0/low otherwise the output should be 1/high and turn on the LED. The neural network was designed to work with any number of nodes and hidden layers. The program is running on a raspberry pi 4 with the gpiod library to manage the LED and buttons. We hope this repository can bring some clarity for those who are struggling with ReLU or backpropagation.

## Discussion
This project was the last project in our machine learning course and had lots of fun problems to solve. Our biggest issue in this assignment was to get the neural network to work with a higher number of input signals. We got our machine working easily with three buttons, see Fig.1. Any number above three input signals seemed to only create faulty predictions no matter how many numbers of hidden layers, nodes or epochs we choose, see Fig.2. We spent hours trying to understand why and tried one last thing, and it worked! 
To solve our issue, we had to change the activation function from ReLU to Tanh. We hardly knew other activation methods existed, so coming by this solution was quite fun. After this the rest was smooth sailing, and we could quite easily implement all other features we wanted.

![alt text](https://github.com/peter-strom/ML-p2-Neural_net_embedded/blob/4df7a1c26fd78acbf8bc1d4e7d95d58fd228faa2/img/fig1.png)

Fig.1 - Three input signals - Worked great when our machine running ReLU activation with different settings. 

![alt text](https://github.com/peter-strom/ML-p2-Neural_net_embedded/blob/3613ae104815c9729222e099af963688991a007f/img/fig2.png)

Fig.2 - Four input signals - Our best predictions using ReLU. 

## Artificial Neural Network
A neural network is a collection of nodes/neurons connected to each other in layers. Minimum is three layers, one input, one hidden layer and one output layer. Each node has their own bias(m) value. The connections between each node have a weight(k) value. To train a neural network you also need training data, input(x) and output(y). With these you have the formula (y = kx + m) which gives the output for each node in feedforward.
When training a neural network there are three stages, feedforward, backpropagation and optimization.

### Feedforward. (input layer -> output layer) 
Feedforward calculates the new output values for each node by adding the bias(m) value, the input and the weight for each input connection, see Fig.3. 
>y = m + (k1 * x1) + (k2 * x2) + ...
	      
### Backpropagation. (input layer <- output layer) 
After feedforward for all layers are done you get an y-prediction from the output node. With this you calculate the deviation/error for each node. For the output layer you compare the y-prediction to the y-reference from the training data from the training data, see Fig.4. 
>error = y reference - y prediction 

For the hidden nodes you take the error value and the weight from the previous calculated layer. For example, the to calculate the last hidden layer you take the weight(k) and error from the output nodes, see Fig.5. 
>error = error1(next_layer) * k1(next_layer) + error2(next_layer) * k2(next_layer) + …

### Optimization. 
The last step is to adjust all the nodes by calculating new weight(k) and bias(m) values. The new bias(m) value for each node by adding the old bias value with the error times learning rate you want, see Fig.6. 
>m(new) = m(old) + error * LR

All new weights are calculated by adding the old weight(k) with the error, learng_rate and the input signal(x). For example: to optimize a new weight in the output layer, you take the old weight(k) + the error value for the output layer node * learning rate * the input(x), see Fig.6. 
>k(new) = k(old) + error * LR * x.


And repeat!



![alt text](https://github.com/peter-strom/ML-p2-Neural_net_embedded/blob/80bb41a867ca11fd8f38e42aa5c175df469d737f/img/fig3.png)

Fig.3 - Feed forward.

![alt text](https://github.com/peter-strom/ML-p2-Neural_net_embedded/blob/80bb41a867ca11fd8f38e42aa5c175df469d737f/img/fig4.png)

Fig.4 - Backpropagation (output layer).

![alt text](https://github.com/peter-strom/ML-p2-Neural_net_embedded/blob/80bb41a867ca11fd8f38e42aa5c175df469d737f/img/fig5.png)

Fig.5 - Backpropagation (hidden layer).

![alt text](https://github.com/peter-strom/ML-p2-Neural_net_embedded/blob/80bb41a867ca11fd8f38e42aa5c175df469d737f/img/fig6.png)

Fig.6 - Optimizeation (gradient descent).



[![Watch the video](https://github.com/peter-strom/ML-p2-Neural_net_embedded/blob/4df7a1c26fd78acbf8bc1d4e7d95d58fd228faa2/img/youtube.png)](https://youtu.be/20bjsbjJasY)

Movie.1 - Video of the neural net in action.
