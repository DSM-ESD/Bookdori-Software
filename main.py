from PyQt5.QtWidgets import *
from PyQt5.QtCore import *
from PyQt5.QtGui import *
from threading import Thread
from time import sleep
from random import randrange
from module.FaceRecognize import *

class Main(QStackedWidget):
    def __init__(self):
        super().__init__()
        self.resize(1920, 1080)
        self.setAttribute(Qt.WA_StyledBackground, True)
        self.setStyleSheet('Main { background-color: white; }')
        self.faceThread = Thread(target=self.expressionThread, args=())
        self.faceThread.daemon = True
        self.faceThread.start()
        self.isBlink = False
        '''self.face = ()'''
    
    def paintEvent(self, e):
        qp = QPainter(self)
        qp.setRenderHint(QPainter.Antialiasing)
        eyes = [QRect(380,400,200,200), QRect(1340,400,200,200)]
        '''
        for eye in eyes:
            if self.face:
                eye.translate(QPoint(self.face[0], self.face[1]))
        '''
        pen = QPen(Qt.black)
        pen.setWidth(10)
        qp.setPen(pen)

        qp.drawEllipse(QPoint(480,500), 250, 250)
        qp.drawEllipse(QPoint(1440,500), 250, 250)

        if not self.isBlink:
            qp.setBrush(Qt.black)
            qp.drawEllipse(eyes[0])
            qp.drawEllipse(eyes[1])
        else:
            qp.drawArc(480-100,500-100,200,200,-30*16,-120*16)
            qp.drawArc(1440-100,500-100,200,200,-30*16,-120*16)

        qp.drawArc(960-100,550,200,200,-30*16,-120*16)
        qp.end()

    def keyPressEvent(self, e):
        if e.key() == Qt.Key_C:
            self.deleteLater()
    
    def expressionThread(self):
        '''obj = FaceRecognize()'''
        while True:
            self.isBlink = True
            self.update()
            sleep(0.1)
            '''
            pos = obj.getFacePos()
            if pos:
                self.face = pos[0]
                print(self.face)
                self.update()
            '''
            self.isBlink = False
            self.update()
            sleep(randrange(4,7))

if __name__ == '__main__':
    import sys
    app = QApplication(sys.argv)
    ui = Main()
    ui.showFullScreen()
    #ui.show()
    sys.exit(app.exec_())
    