import cv2
import time

cam = cv2.VideoCapture(0)

def TAKE_PICK(img_counter):

    ret, frame = cam.read()
    
    if not ret:
        print("failed to grab frame")      
        return("failed to grab frame")
        
    
    else:
        im_name = "Tabla_{}.jpg".format(img_counter)
        cv2.imwrite(im_name, frame)
        #cv2.imshow("PICK", frame)
        print("Screenshot Taken")
        return("Screenshot Taken")
    

TAKE_PICK(0)

cam.release()
cv2.destroyAllWindows()