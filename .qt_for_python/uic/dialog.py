# Form implementation generated from reading ui file 'f:\QQPCmgr\Desktop\Zhihu\小陈玩具屋\英文文献翻译格式整理器\src_code\05 Qt Designer Python\dialog.ui'
#
# Created by: PyQt6 UI code generator 6.3.0
#
# WARNING: Any manual changes made to this file will be lost when pyuic6 is
# run again.  Do not edit this file unless you know what you are doing.


from PyQt6 import QtCore, QtGui, QtWidgets


class Ui_Dialog(object):
    def setupUi(self, Dialog):
        Dialog.setObjectName("Dialog")
        Dialog.resize(1324, 612)
        self.oriText = QtWidgets.QTextEdit(Dialog)
        self.oriText.setGeometry(QtCore.QRect(10, 10, 661, 481))
        font = QtGui.QFont()
        font.setPointSize(13)
        self.oriText.setFont(font)
        self.oriText.setObjectName("oriText")
        self.translatedText = QtWidgets.QTextEdit(Dialog)
        self.translatedText.setGeometry(QtCore.QRect(690, 10, 581, 241))
        font = QtGui.QFont()
        font.setPointSize(13)
        self.translatedText.setFont(font)
        self.translatedText.setObjectName("translatedText")
        self.deletedOri = QtWidgets.QTextEdit(Dialog)
        self.deletedOri.setGeometry(QtCore.QRect(690, 300, 581, 191))
        font = QtGui.QFont()
        font.setPointSize(13)
        self.deletedOri.setFont(font)
        self.deletedOri.setObjectName("deletedOri")
        self.label = QtWidgets.QLabel(Dialog)
        self.label.setGeometry(QtCore.QRect(280, 520, 52, 26))
        font = QtGui.QFont()
        font.setPointSize(13)
        self.label.setFont(font)
        self.label.setObjectName("label")
        self.label_2 = QtWidgets.QLabel(Dialog)
        self.label_2.setGeometry(QtCore.QRect(900, 510, 182, 26))
        font = QtGui.QFont()
        font.setPointSize(13)
        self.label_2.setFont(font)
        self.label_2.setObjectName("label_2")
        self.label_3 = QtWidgets.QLabel(Dialog)
        self.label_3.setGeometry(QtCore.QRect(930, 260, 104, 26))
        font = QtGui.QFont()
        font.setPointSize(13)
        self.label_3.setFont(font)
        self.label_3.setObjectName("label_3")
        self.splitter = QtWidgets.QSplitter(Dialog)
        self.splitter.setGeometry(QtCore.QRect(750, 550, 457, 37))
        font = QtGui.QFont()
        font.setPointSize(13)
        self.splitter.setFont(font)
        self.splitter.setOrientation(QtCore.Qt.Orientation.Horizontal)
        self.splitter.setObjectName("splitter")
        self.translateButton = QtWidgets.QPushButton(self.splitter)
        font = QtGui.QFont()
        font.setPointSize(13)
        self.translateButton.setFont(font)
        self.translateButton.setObjectName("translateButton")
        self.copyOri = QtWidgets.QPushButton(self.splitter)
        font = QtGui.QFont()
        font.setPointSize(13)
        self.copyOri.setFont(font)
        self.copyOri.setObjectName("copyOri")
        self.copyTranslated = QtWidgets.QPushButton(self.splitter)
        font = QtGui.QFont()
        font.setPointSize(13)
        self.copyTranslated.setFont(font)
        self.copyTranslated.setObjectName("copyTranslated")
        self.deleteButton = QtWidgets.QPushButton(self.splitter)
        font = QtGui.QFont()
        font.setPointSize(13)
        self.deleteButton.setFont(font)
        self.deleteButton.setObjectName("deleteButton")

        self.retranslateUi(Dialog)
        QtCore.QMetaObject.connectSlotsByName(Dialog)

    def retranslateUi(self, Dialog):
        _translate = QtCore.QCoreApplication.translate
        Dialog.setWindowTitle(_translate("Dialog", "Dialog"))
        self.label.setText(_translate("Dialog", "原文"))
        self.label_2.setText(_translate("Dialog", "智能删除后原文"))
        self.label_3.setText(_translate("Dialog", "翻译内容"))
        self.translateButton.setText(_translate("Dialog", "翻译"))
        self.copyOri.setText(_translate("Dialog", "复制原文"))
        self.copyTranslated.setText(_translate("Dialog", "复制翻译"))
        self.deleteButton.setText(_translate("Dialog", "智能删除"))
