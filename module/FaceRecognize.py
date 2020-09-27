import cv2

class FaceRecognize():
    def __init__(self):
        self.cap = cv2.VideoCapture(0)
        self.cap.set(3, 480)
        self.cap.set(4, 480)
        self.face_cascade = cv2.CascadeClassifier('resource/haarcascade_frontface.xml')

    def getFacePos(self):
        ret, frame = self.cap.read()
        gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
        faces = self.face_cascade.detectMultiScale(gray, 1.3, 5)
        pos = []
        for (x, y, w, h) in faces:
            x += 480 - (w / 2) - 240
            y += (h / 2) - 240
            pos.append((x, y))
        return pos

    def __del__(self):
        self.cap.release()