import cv2

cam = cv2.VideoCapture(0)
#cap.set(cv2.CAP_PROP_BUFFERSIZE, 1)

img_counter = 1

while True:
    ret, frame = cam.read()
    
    if not ret:
        print("failed to grab frame")
        break
    
    cv2.imshow("TESTING", frame)
    
    k = cv2.waitKey(1)
    
    if k%256 == 27:
        print("Escape hit, CLOSING")
        break

    elif k%256 == 32:
        im_name = "/home/gene/Desktop/BACKUP RASPI/Raspberry/Tabla_{}.jpg".format(img_counter)
        cv2.imwrite(im_name, frame)
        print("Screenshot Taken")
        img_counter+=1
        
cam.release()
cv2.destroyAllWindows()