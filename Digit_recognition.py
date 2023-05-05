import cv2
import numpy as np
from tensorflow.keras.models import load_model

cap = cv2.VideoCapture(0 + cv2.CAP_DSHOW)
WIDTH = cap.get(cv2.CAP_PROP_FRAME_WIDTH)
HEIGHT = cap.get(cv2.CAP_PROP_FRAME_HEIGHT)

model = load_model('model/digits.h5')


def prediction(image, model):
    img = cv2.resize(image, (28, 28))
    img = img / 255
    img = img.reshape(1, 28, 28, 1)
    #predict = model.predict(img)
    predict = np.argmax(model.predict(img), axis=-1)
    prob = np.amax(predict)
    class_index = model.predict(img)
    result = class_index[0]
    if prob < 0.75:
        result = 0
        prob = 0
    return result, prob


while True:

    _, frame = cap.read()
    frame = cv2.rotate(frame, cv2.ROTATE_180)
    frame_copy = frame.copy()

    bbox_size = (60, 60)
    bbox = [(int(WIDTH // 2 - bbox_size[0] // 2), int(HEIGHT // 2 - bbox_size[1] // 2)),
            (int(WIDTH // 2 + bbox_size[0] // 2), int(HEIGHT // 2 + bbox_size[1] // 2))]

    img_cropped = frame[bbox[0][1]:bbox[1][1], bbox[0][0]:bbox[1][0]]
    img_gray = cv2.cvtColor(img_cropped, cv2.COLOR_BGR2GRAY)
    img_gray = cv2.resize(img_gray, (200, 200))
    cv2.imshow("cropped", img_gray)

    result, probability = prediction(img_gray,model)
    cv2.putText(frame_copy,f"Prediction: {result}", (40,50), cv2.FONT_HERSHEY_SIMPLEX,0.8,
                (255,0,255),2,cv2.LINE_AA)

    cv2.putText(frame_copy,"Probability: "+"{:.2f}".format(probability), (40,80), cv2.FONT_HERSHEY_SIMPLEX,0.8,
                (255,0,255),2,cv2.LINE_AA)

    cv2.rectangle(frame_copy, bbox[0], bbox[1],(0,255,0),3)

    print(f'result = {result}')
    

    cv2.imshow("input", frame_copy)

    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

cv2.destroyAllWindows()
