import numpy as np
import matplotlib.pyplot as plt
import matplotlib.image as mpimg
import random

def rgb2gray(rgb):
    return np.dot(rgb[...,:3],[1,1,1])
    # return np.dot(rgb[...,:3],[0.3,0.59,0.11])  
img_rgb = mpimg.imread('C:\\Users\\gupta\\Downloads\\book.jpeg')


img_grayo = rgb2gray(img_rgb)

for i in range(img_grayo.shape[0]):
     for k in range(img_grayo.shape[1]):
        if (i==200 and k>=300 and k<=500) or (k==400 and i>=200 and i<=400)  :
             img_grayo[i,k]=1
        else:
             img_grayo[i,k]=0
plt.imshow(img_grayo, cmap=plt.get_cmap('binary_r'))  
plt.show()