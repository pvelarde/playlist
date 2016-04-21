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
    QListView *listView;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_9;
    QFrame *uploadFrame;
    QFrame *frame;
    QPushButton *pushButton_2;
    QTextEdit *textEdit_2;
    QPushButton *pushButton_4;
    QFrame *frame_2;
    QTextEdit *textEdit_3;
    QTextEdit *textEdit_4;
    QPushButton *pushButton_3;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_4;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QMenuBar *menuBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1153, 647);
        MainWindow->setStyleSheet(QLatin1String("QWidget{\n"
"background-color:rgb(191, 191, 191);\n"
"border-radius:2px;\n"
"}\n"
"\n"
"[objectName=\"centralWidget\"]{\n"
"background-color:black;\n"
"}\n"
"\n"
"QPushButton[objectName=\"pushButton_4\"]{\n"
"margin-left:2px;\n"
"margin-top:0px;\n"
"background:qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgb(88, 226, 255), stop:1 rgb(70, 180, 238));\n"
"border-width:2px;\n"
"border-style: solid;\n"
"border-color: rgb(61, 159, 211);\n"
"border-radius: 6px;\n"
"}\n"
"\n"
"QLabel{\n"
"background-color: rgb(121, 208, 141);\n"
"}\n"
"QListView{\n"
"}\n"
"QPushButton {\n"
"margin-left:2px;\n"
"margin-top:0px;\n"
"background:qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgb(121, 208, 141), stop:1 rgb(41, 194, 18));\n"
"border-width: 2px;\n"
"border-style: solid;\n"
"border-color: rgb(34, 159, 15);\n"
"border-radius: 6px;\n"
"}\n"
"\n"
"QFrame {\n"
"border-width: 2px;\n"
"border-style: solid;\n"
"border-color: black;\n"
"border-radius: 6px;\n"
"}\n"
"\n"
"QTextEdit{\n"
"background:white;\n"
""
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
        mostPopularPlaylistListView->setGeometry(QRect(50, 50, 1051, 171));
        mostPopularPlaylistListView->setStyleSheet(QStringLiteral(""));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(440, 20, 150, 20));
        searchFrame = new QFrame(centralWidget);
        searchFrame->setObjectName(QStringLiteral("searchFrame"));
        searchFrame->setGeometry(QRect(50, 229, 521, 321));
        searchFrame->setStyleSheet(QStringLiteral(""));
        searchFrame->setFrameShape(QFrame::StyledPanel);
        searchFrame->setFrameShadow(QFrame::Raised);
        textEdit = new QTextEdit(searchFrame);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(10, 40, 401, 31));
        pushButton = new QPushButton(searchFrame);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(420, 40, 91, 31));
        listView = new QListView(searchFrame);
        listView->setObjectName(QStringLiteral("listView"));
        listView->setGeometry(QRect(10, 80, 501, 101));
        listView->setStyleSheet(QStringLiteral("margin-top:2px;"));
        label_2 = new QLabel(searchFrame);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 190, 141, 20));
        label_3 = new QLabel(searchFrame);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(200, 10, 121, 20));
        label_3->setAlignment(Qt::AlignCenter);
        label_9 = new QLabel(searchFrame);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(10, 220, 501, 91));
        label_9->setStyleSheet(QLatin1String("background-color:white;\n"
"color: grey;"));
        label_9->setScaledContents(false);
        label_9->setWordWrap(true);
        pushButton->raise();
        textEdit->raise();
        listView->raise();
        label_2->raise();
        label_3->raise();
        label_9->raise();
        uploadFrame = new QFrame(centralWidget);
        uploadFrame->setObjectName(QStringLiteral("uploadFrame"));
        uploadFrame->setGeometry(QRect(580, 230, 521, 321));
        uploadFrame->setFrameShape(QFrame::StyledPanel);
        uploadFrame->setFrameShadow(QFrame::Raised);
        frame = new QFrame(uploadFrame);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(10, 70, 501, 50));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        pushButton_2 = new QPushButton(frame);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(410, 10, 81, 30));
        textEdit_2 = new QTextEdit(frame);
        textEdit_2->setObjectName(QStringLiteral("textEdit_2"));
        textEdit_2->setGeometry(QRect(50, 10, 351, 30));
        textEdit_2->setStyleSheet(QStringLiteral(""));
        pushButton_4 = new QPushButton(frame);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(10, 10, 31, 30));
        pushButton_4->setStyleSheet(QStringLiteral(""));
        frame_2 = new QFrame(uploadFrame);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setGeometry(QRect(10, 169, 501, 141));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        textEdit_3 = new QTextEdit(frame_2);
        textEdit_3->setObjectName(QStringLiteral("textEdit_3"));
        textEdit_3->setGeometry(QRect(10, 40, 381, 30));
        textEdit_3->setStyleSheet(QStringLiteral(""));
        textEdit_4 = new QTextEdit(frame_2);
        textEdit_4->setObjectName(QStringLiteral("textEdit_4"));
        textEdit_4->setGeometry(QRect(10, 100, 381, 30));
        textEdit_4->setStyleSheet(QLatin1String("margin-top:2px;\n"
""));
        pushButton_3 = new QPushButton(frame_2);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(400, 40, 91, 91));
        label_7 = new QLabel(frame_2);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(10, 16, 91, 21));
        label_8 = new QLabel(frame_2);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(10, 80, 121, 20));
        label_5 = new QLabel(uploadFrame);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 46, 71, 20));
        label_6 = new QLabel(uploadFrame);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(10, 136, 101, 20));
        label_4 = new QLabel(uploadFrame);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(170, 10, 111, 20));
        label_4->setAlignment(Qt::AlignCenter);
        MainWindow->setCentralWidget(centralWidget);
        searchFrame->raise();
        mostPopularPlaylistListView->raise();
        label->raise();
        uploadFrame->raise();
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1153, 22));
        MainWindow->setMenuBar(menuBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        label->setText(QApplication::translate("MainWindow", "Most Popular Playlists", 0));
        textEdit->setPlaceholderText(QApplication::translate("MainWindow", "Search a song...", 0));
        pushButton->setText(QApplication::translate("MainWindow", "Go", 0));
        label_2->setText(QApplication::translate("MainWindow", "Most Popular Playlist", 0));
        label_3->setText(QApplication::translate("MainWindow", "Search for a Song", 0));
        label_9->setText(QApplication::translate("MainWindow", "The most popularly matched playlist...", 0));
        pushButton_2->setText(QApplication::translate("MainWindow", "Go", 0));
        textEdit_2->setPlaceholderText(QApplication::translate("MainWindow", "Enter absolute path to a .txt...", 0));
        pushButton_4->setText(QApplication::translate("MainWindow", "\360\237\224\274", 0));
        textEdit_3->setPlaceholderText(QApplication::translate("MainWindow", "Enter comma seperated songs...", 0));
        textEdit_4->setPlaceholderText(QApplication::translate("MainWindow", "Enter playlist's popularity...", 0));
        pushButton_3->setText(QApplication::translate("MainWindow", "Go", 0));
        label_7->setText(QApplication::translate("MainWindow", "Playlist Name", 0));
        label_8->setText(QApplication::translate("MainWindow", "Playlist Popularity", 0));
        label_5->setText(QApplication::translate("MainWindow", "From File:", 0));
        label_6->setText(QApplication::translate("MainWindow", "Single Playlist:", 0));
        label_4->setText(QApplication::translate("MainWindow", "Upload a Playlist", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
