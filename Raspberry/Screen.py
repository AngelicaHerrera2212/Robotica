import cv2

def TAKE_PICK(img_counter):

    cam = cv2.VideoCapture(0)
    ret, frame = cam.read()
    
    if not ret:
        print("Screenshot Failed")      
        return("Screenshot Failed")
        
    
    else:
        im_name = "/home/gene/Desktop/BACKUP RASPI/Raspberry/Tabla_{}.jpg".format(img_counter)
        cv2.imwrite(im_name, frame)
        #cv2.imshow("PICK", frame)
        print("Screenshot Taken")
        return("Screenshot Taken")
    
    cam.release()
    cv2.destroyAllWindows()