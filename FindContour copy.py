import cv2
import numpy as np
import matplotlib.pyplot as plt
import csv
#import pytesseract

class ImageProcessing:
    def __init__(self,Path):
        self.OriginalImage = cv2.imread() 

#https://stackoverflow.com/questions/7263621/how-to-find-corners-on-a-image-using-opencv

kernel = np.ones((5,5),np.uint8)

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

# CONTORNOS
CONT, JERAR = cv2.findContours(edged, cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)
aligned_image = np.copy(Image)  # Create a copy of the original image
areas = []

for i in range(len(CONT)):
    CNT = CONT[i]
    area = cv2.contourArea(CNT)
    areas.append(area)

    if (area > 48563 and area < 50000):
        cv2.drawContours(Image, CONT, i, (0,255,0), 2)
        cv2.imshow('IMAGEN CONTORNOS', Image)
        print(f"Index: {i} ; Area: {area}")

        # Obtain the four corner points of the contour's bounding rectangle
        rect = cv2.minAreaRect(CNT)
        box = cv2.boxPoints(rect)
        #box = np.int0(box)
        src_points = np.float32(box)
        width, height = 800,600

        # Calculate the destination points for the perspective transformation
        dst_points = np.float32([[0, 0], [width, 0], [width, height], [0, height]])
        # Perform the perspective transformation
        Image_Cut = cv2.getPerspectiveTransform(src_points, dst_points)
        warped_image = cv2.warpPerspective(aligned_image, Image_Cut, (width, height))
        rotated_image = cv2.rotate(warped_image, cv2.ROTATE_90_COUNTERCLOCKWISE)

        # Display the warped image
        cv2.imshow('Warped Image', rotated_image)

#print(areas)

# waits for user to press any key
cv2.waitKey(0)
  
# closing all open windows
cv2.destroyAllWindows()