from PyQt5.QtWidgets import *
from PyQt5.QtCore import *
from PyQt5.QtGui import *

class Main(QStackedWidget):
    def __init__(self):
        super().__init__()
        self.resize(1920, 1080)
        self.setAttribute(Qt.WA_StyledBackground, True)
        self.setStyleSheet('Main { background-color: white; }')
    
    def paintEvent(self, e):
        pass

    def keyPressEvent(self, e):
        if e.key() == Qt.Key_C:
            self.deleteLater()

if __name__ == '__main__':
    import sys
    app = QApplication(sys.argv)
    ui = Main()
    ui.showFullScreen()
    sys.exit(app.exec_())
    