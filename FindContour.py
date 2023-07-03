import cv2
import numpy as np
import matplotlib.pyplot as plt
import pytesseract

class ImageProcessing:
    def __init__(self,Path):
        if type(Path) == str:
            self.OriginalImage = cv2.imread(Path)
        else:
            self.OriginalImage = np.copy(Path)

    def CopyImage(self):
        return np.copy(self.OriginalImage)
    
    def To_Grayscale(self):
        self.GrayscaleImage = cv2.cvtColor(self.OriginalImage, cv2.COLOR_BGR2GRAY)
    
    def BinaryThreshold(self,Thresh):
        self.BinaryImage = cv2.threshold(self.OriginalImage, Thresh, 255, cv2.THRESH_BINARY)[1]
    
    def CannyEdge(self,LowerThresh,UpperThresh):
        self.CannyEdgeImage = cv2.Canny(self.GrayscaleImage, LowerThresh, UpperThresh)

    def FindContours(self,Lower,Upper,width,height):
        # CONTORNOS
        CONT, JERAR = cv2.findContours(self.CannyEdgeImage, cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)
        self.AlignedImage = np.copy(self.OriginalImage)  # Create a copy of the original image
        self.ContourImage = np.copy(self.OriginalImage)  # Create a copy of the original image

        for i in range(len(CONT)):
            CNT = CONT[i]
            area = cv2.contourArea(CNT)

            if (area > Lower and area < Upper):
                cv2.drawContours(self.ContourImage, CONT, i, (0,255,0), 2)
                print(f"Index: {i} ; Area: {area}")

                # Obtain the four corner points of the contour's bounding rectangle
                rect = cv2.minAreaRect(CNT)
                box = cv2.boxPoints(rect)
                src_points = np.float32(box)

                # Calculate the destination points for the perspective transformation
                dst_points = np.float32([[0, 0], [width, 0], [width, height], [0, height]])
                
                # Perform the perspective transformation
                Image_Cut = cv2.getPerspectiveTransform(src_points, dst_points)
                warped_image = cv2.warpPerspective(self.AlignedImage, Image_Cut, (width, height))
                self.WarpedImage = cv2.rotate(warped_image, cv2.ROTATE_90_COUNTERCLOCKWISE)

    def DetectLines(self, rho, theta, threshold, minLineLength, maxLineGap):
        self.LinesImage = np.copy(self.OriginalImage)  # Create a copy of the original image
        lines = cv2.HoughLinesP(self.CannyEdgeImage, rho, theta, threshold, minLineLength, maxLineGap)
        
        if lines is not None:
            for line in lines:
                x1, y1, x2, y2 = line[0]
                cv2.line(self.LinesImage, (x1, y1), (x2, y2), (0, 0, 255), 2)
        else:
            print("No lines detected.")

#https://stackoverflow.com/questions/7263621/how-to-find-corners-on-a-image-using-opencv

pytesseract.pytesseract.tesseract_cmd = 'C:\\Users\\maxel\\anaconda3\\envs\\Robotica_Angelica\\Scripts\\pytesseract.exe'
im_name = "Table_Pics Rev02\Foto #2.jpg"
Image = ImageProcessing(im_name)
Image.To_Grayscale()
Image.CannyEdge(30,200)
Image.FindContours(48563,50000,800,600)

Image2 = ImageProcessing(Image.WarpedImage)
Image2.To_Grayscale()
Image2.CannyEdge(100,200)
Image2.FindContours(0,50000,800,600)
Image2.DetectLines(5,np.pi/180,50,350,50)

cv2.imshow("Original Image",Image.OriginalImage)
#cv2.imshow("Grayscale Image",Image.GrayscaleImage)
cv2.imshow("Canny Image",Image.CannyEdgeImage)
cv2.imshow("Contour Image",Image.ContourImage)
cv2.imshow("Warped Image",Image.WarpedImage)

cv2.imshow("Image2",Image2.OriginalImage)
cv2.imshow("Imagecanny 2",Image2.CannyEdgeImage)
cv2.imshow("Contour Image2",Image2.ContourImage)
cv2.imshow("Lines Image2",Image2.LinesImage)


#print(pytesseract.image_to_string(Image2.OriginalImage))

# waits for user to press any key
cv2.waitKey(0)
  
# closing all open windows
cv2.destroyAllWindows()