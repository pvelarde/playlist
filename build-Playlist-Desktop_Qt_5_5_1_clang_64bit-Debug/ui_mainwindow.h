/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QListView *mostPopularPlaylistListView;
    QLabel *label;
    QFrame *searchFrame;
    QTextEdit *textEdit;
    QPushButton *pushButton;
    QLabel *label_2;
    QListView *listView;
    QFrame *uploadFrame;
    QFrame *frame;
    QPushButton *pushButton_2;
    QTextEdit *textEdit_2;
    QFrame *frame_2;
    QTextEdit *textEdit_3;
    QTextEdit *textEdit_4;
    QPushButton *pushButton_3;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_3;
    QLabel *label_4;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QMenuBar *menuBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(835, 526);
        MainWindow->setStyleSheet(QLatin1String("QWidget{\n"
"background-color:rgb(191, 191, 191);\n"
"border-radius:2px;\n"
"}\n"
"\n"
"QLabel{\n"
"background-color: rgb(38, 180, 17);\n"
"}\n"
"QListView{\n"
"}\n"
"QPushButton {\n"
"margin-left:2px;\n"
"margin-top:-5px;\n"
"padding-top:-2px;\n"
"background:qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgb(38, 180, 17), stop:1 rgb(26, 122, 12));\n"
"}\n"
"\n"
"QFrame {\n"
"/*background:orange;*/\n"
"border: black;\n"
"}\n"
"\n"
"QTextEdit{\n"
"background:white;\n"
"}\n"
"\n"
"\n"
"\n"
"QToolBar {\n"
"/*background:purple;*/\n"
"}\n"
"\n"
"QStatusBar{\n"
"}\n"
"\n"
"QMenuBar{ /*bar at top*/\n"
"\n"
"}\n"
"\n"
"QListView{\n"
"background:rgb(232, 232, 232);\n"
"\n"
"}"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        mostPopularPlaylistListView = new QListView(centralWidget);
        mostPopularPlaylistListView->setObjectName(QStringLiteral("mostPopularPlaylistListView"));
        mostPopularPlaylistListView->setGeometry(QRect(30, 40, 761, 141));
        mostPopularPlaylistListView->setStyleSheet(QStringLiteral(""));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(320, 10, 141, 16));
        searchFrame = new QFrame(centralWidget);
        searchFrame->setObjectName(QStringLiteral("searchFrame"));
        searchFrame->setGeometry(QRect(30, 230, 351, 231));
        searchFrame->setStyleSheet(QStringLiteral("background:black;"));
        searchFrame->setFrameShape(QFrame::StyledPanel);
        searchFrame->setFrameShadow(QFrame::Raised);
        textEdit = new QTextEdit(searchFrame);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(10, 20, 251, 31));
        pushButton = new QPushButton(searchFrame);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(260, 20, 91, 31));
        label_2 = new QLabel(searchFrame);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(70, 70, 201, 31));
        listView = new QListView(searchFrame);
        listView->setObjectName(QStringLiteral("listView"));
        listView->setGeometry(QRect(10, 110, 331, 111));
        listView->setStyleSheet(QStringLiteral(""));
        pushButton->raise();
        textEdit->raise();
        label_2->raise();
        listView->raise();
        uploadFrame = new QFrame(centralWidget);
        uploadFrame->setObjectName(QStringLiteral("uploadFrame"));
        uploadFrame->setGeometry(QRect(400, 230, 391, 231));
        uploadFrame->setFrameShape(QFrame::StyledPanel);
        uploadFrame->setFrameShadow(QFrame::Raised);
        frame = new QFrame(uploadFrame);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(10, 30, 371, 81));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        pushButton_2 = new QPushButton(frame);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(260, 10, 91, 31));
        textEdit_2 = new QTextEdit(frame);
        textEdit_2->setObjectName(QStringLiteral("textEdit_2"));
        textEdit_2->setGeometry(QRect(10, 10, 251, 31));
        textEdit_2->setStyleSheet(QStringLiteral(""));
        frame_2 = new QFrame(uploadFrame);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setGeometry(QRect(10, 140, 371, 81));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        textEdit_3 = new QTextEdit(frame_2);
        textEdit_3->setObjectName(QStringLiteral("textEdit_3"));
        textEdit_3->setGeometry(QRect(10, 10, 261, 31));
        textEdit_3->setStyleSheet(QStringLiteral(""));
        textEdit_4 = new QTextEdit(frame_2);
        textEdit_4->setObjectName(QStringLiteral("textEdit_4"));
        textEdit_4->setGeometry(QRect(10, 40, 261, 31));
        textEdit_4->setStyleSheet(QLatin1String("margin-top:2px;\n"
""));
        pushButton_3 = new QPushButton(frame_2);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(270, 10, 101, 61));
        label_5 = new QLabel(uploadFrame);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(20, 10, 59, 16));
        label_6 = new QLabel(uploadFrame);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(20, 120, 101, 16));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(150, 200, 101, 16));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(540, 200, 111, 16));
        MainWindow->setCentralWidget(centralWidget);
        searchFrame->raise();
        mostPopularPlaylistListView->raise();
        label->raise();
        uploadFrame->raise();
        label_3->raise();
        label_4->raise();
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 835, 22));
        MainWindow->setMenuBar(menuBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        label->setText(QApplication::translate("MainWindow", "Most Popular Playlists", 0));
        pushButton->setText(QApplication::translate("MainWindow", "Go", 0));
        label_2->setText(QApplication::translate("MainWindow", "*Stub for most popular playlist*", 0));
        pushButton_2->setText(QApplication::translate("MainWindow", "Go", 0));
        pushButton_3->setText(QApplication::translate("MainWindow", "Go", 0));
        label_5->setText(QApplication::translate("MainWindow", "from file:", 0));
        label_6->setText(QApplication::translate("MainWindow", "a single playlist:", 0));
        label_3->setText(QApplication::translate("MainWindow", "Search a song!", 0));
        label_4->setText(QApplication::translate("MainWindow", "Upload a playlist!", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
