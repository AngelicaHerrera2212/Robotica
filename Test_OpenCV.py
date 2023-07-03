import cv2
import numpy as np
import matplotlib.pyplot as plt
#import pytesseract

#https://stackoverflow.com/questions/7263621/how-to-find-corners-on-a-image-using-opencv

im_name = "Table_Pics Rev02\Foto #2.jpg"
Image = cv2.imread(im_name)
cv2.imshow("Original",Image)

image_grayscale = cv2.cvtColor(Image, cv2.COLOR_BGR2GRAY)
cv2.imshow('IN GREY',image_grayscale)

#canny
edged = cv2.Canny(image_grayscale, 30, 200)
cv2.imshow("canny",edged)

# BINARIZACION NORMAL - ES MEJOR PARA LOSCONTORNOS
thresh = 80
image_binary = cv2.threshold(image_grayscale, thresh, 255, cv2.THRESH_BINARY)[1]
cv2.imshow('BINARY',image_binary)

aligned_image = np.copy(Image)  # Create a copy of the original image

# CONTORNOS
ContourList, JERAR = cv2.findContours(image_binary, cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)
i = 0

for Contour in ContourList:
    Area = cv2.contourArea(Contour)
    i += 1

    if (Area > 40000 and Area < 70000):
        cv2.drawContours(Image, ContourList, i, (255,0,0), 2)
        cv2.imshow('IMAGEN CONTORNOS', Image)
        ID = Contour
        
        # Obtain the four corner points of the contour's bounding rectangle
        rect = cv2.minAreaRect(Contour)
        box = cv2.boxPoints(rect)
        #box = np.int0(box)
        src_points = np.float32(box)

        # Calculate the destination points for the perspective transformation
        dst_points = np.float32([[0, 0], [800, 0], [800, 600], [0, 600]])

        # Perform the perspective transformation
        M = cv2.getPerspectiveTransform(src_points, dst_points)
        warped_image = cv2.warpPerspective(aligned_image, M, (800, 600))

        # Display the warped image
        cv2.imshow('Warped Image', warped_image)

cv2.imshow('Aligned Image', aligned_image)

# waits for user to press any key
cv2.waitKey(0)
  
# closing all open windows
cv2.destroyAllWindows()