import tensorflow as tf 
import cv2
import numpy as np

(X_train, Y_train), (X_test, Y_test) = tf.keras.datasets.mnist.load_data()

X_val, Y_val = X_train[50000:60000, :], Y_train[50000:60000]
X_train, Y_train = X_train[:50000, :], Y_train[:50000]

#reshape

X_train = X_train.reshape(X_train.shape[0], 28, 28, 1)
X_val = X_val.reshape(X_val.shape[0], 28, 28, 1)
X_test = X_test.reshape(X_test.shape[0], 28, 28, 1)

#one hot coding

Y_train = tf.keras.utils.to_categorical(Y_train, 10)
Y_test = tf.keras.utils.to_categorical(Y_test, 10)
Y_val = tf.keras.utils.to_categorical(Y_val, 10)

