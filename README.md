# Project II - Maskininlärning och sensorteknik (Machine learning and sensor technology ) - Ela21, YRGO

Supervisor: Erik Pihl 

By: Daniel Mentzer och Peter Strömblad
            
## Neuralt nätverk i ett inbyggt system (A neural network in an embedded system) 

## Introduction
In this project an artificial neural network was to be created with the purpose to sense the input signals of four buttons. In the other end of the neural network an LED was connected. If an even number of buttons was pressed the output signal should be 0/low otherwise the output should be 1/high and turn on an LED. The neural network was designed to work with nay number of nodes and hidden layers.  The program is running on a raspberry pi 4 with the gpiod library to manage the LED and buttons.

## Discussion

This project was the last project in our machine learning course and had lots of fun problems to solve. Our biggest issue in this assignment was to get the neural network to work with a higher number of input signals. We got our machine working easily with three buttons, see Fig. 1. Any number above three input signals seemed to only create faulty predictions no matter how many numbers of hidden layers, nodes or epochs we choose, see Fig. 2. We spent hours trying to understand why and tried one last thing, and it worked! 
To solve our issue, we had to change the activation function from ReLU to Tanh. We hardly knew other activation methods existed, so coming by this solution was quite fun. After this the rest was smooth sailing, and we could quite easily implement all other features we wanted.

![alt text](https://github.com/peter-strom/ML-p2-Neural_net_embedded/blob/4df7a1c26fd78acbf8bc1d4e7d95d58fd228faa2/img/fig1.png)

Fig.1 - Three input signals - Worked great when our machine running ReLU activation with different settings. 

![alt text](https://github.com/peter-strom/ML-p2-Neural_net_embedded/blob/3613ae104815c9729222e099af963688991a007f/img/fig2.png)

Fig.2 - Four input signals - Our best predictions using ReLU. 

## Artificial Neural Network
A neural netowrk is a collection of nodes/neurons connected to eachother in layers. Minimum is three layers, one input, one hiddern layer and one output layer. These all have a bias value(m) and the connections between them have a weight(k) value. To train a neural network you also need training data, input(x) and output(y). with these you have the formula (y=kx+m) which gives the output for each node in feedforward.

Feedforward. (input -> output)
When training a neural network there are three stages, feedforward, backproagation and optimization. Feedforward calculates the new output values for each node by taking the bias(m) value and adding the input and weight for each connected node(previus layer only). 
    y=m+(k1*x1)*(k2*x2)...

Backpropagation. (output -> input )
After feedforward for all layers are done you get an y-prediction from the output node. With this you calculate the deviation/error for each node. The output layer you compare the y-prediction to the ouput(y) from the training data. 
    error = ouput(y)- y prediction
For the hidden nodes you take the error value and the weight from the node after the selected one. For example, the to calculate the last hidden layer you take the weight and error from the output nodes.
    error = error(prev.layer) * weight(k(prev.layer))

Optimization. (output -> input)
The last step is to calculate new weight and bias values for the next iteration. For each layer you first calculate the new bias(m) value for each node by adding the old bias value with the error and the learning rate you want. 
    m(new)=m(old)+error*learnrate
And for each connection to same node you calculate a new weight by adding the old weight with the error, learnrate and the output from the next layer (going from output to input). 
For example, to optimize the output you take the old weight(k) + the error value for the same output node * learn rate and the output(y) of the connected hidden node to get the weight(k) of the connecting edge. 
    k(new)= k(old) + error * learnrate * output(y).

And repeat!


![alt text](https://github.com/peter-strom/ML-p2-Neural_net_embedded/blob/3613ae104815c9729222e099af963688991a007f/img/fig3.png)

Fig.3 - Feed forward.

![alt text](https://github.com/peter-strom/ML-p2-Neural_net_embedded/blob/3613ae104815c9729222e099af963688991a007f/img/fig4.png)

Fig.4 - Backpropagation (output layer).

![alt text](https://github.com/peter-strom/ML-p2-Neural_net_embedded/blob/3613ae104815c9729222e099af963688991a007f/img/fig5.png)

Fig.5 - Backpropagation (hidden layer).

![alt text](https://github.com/peter-strom/ML-p2-Neural_net_embedded/blob/3613ae104815c9729222e099af963688991a007f/img/fig6.png)

Fig.6 - Optimizeation (gradient descent).



[![Watch the video](https://github.com/peter-strom/ML-p2-Neural_net_embedded/blob/4df7a1c26fd78acbf8bc1d4e7d95d58fd228faa2/img/youtube.png)](https://youtu.be/20bjsbjJasY)

Movie.1 - Video of the neural net in action.
