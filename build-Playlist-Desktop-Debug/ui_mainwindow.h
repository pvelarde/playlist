/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
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
    QTextEdit *textEdit_5;
    QFrame *uploadFrame;
    QFrame *frame;
    QPushButton *pushButton_2;
    QTextEdit *textEdit_2;
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
        MainWindow->resize(900, 600);
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
        mostPopularPlaylistListView->setGeometry(QRect(50, 50, 800, 141));
        mostPopularPlaylistListView->setStyleSheet(QStringLiteral(""));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(375, 20, 150, 20));
        searchFrame = new QFrame(centralWidget);
        searchFrame->setObjectName(QStringLiteral("searchFrame"));
        searchFrame->setGeometry(QRect(50, 229, 380, 320));
        searchFrame->setStyleSheet(QStringLiteral(""));
        searchFrame->setFrameShape(QFrame::StyledPanel);
        searchFrame->setFrameShadow(QFrame::Raised);
        textEdit = new QTextEdit(searchFrame);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(10, 40, 251, 31));
        pushButton = new QPushButton(searchFrame);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(270, 40, 91, 31));
        listView = new QListView(searchFrame);
        listView->setObjectName(QStringLiteral("listView"));
        listView->setGeometry(QRect(10, 70, 251, 111));
        listView->setStyleSheet(QStringLiteral(""));
        label_2 = new QLabel(searchFrame);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 200, 150, 20));
        label_3 = new QLabel(searchFrame);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(115, 10, 150, 20));
        label_3->setAlignment(Qt::AlignCenter);
        textEdit_5 = new QTextEdit(searchFrame);
        textEdit_5->setObjectName(QStringLiteral("textEdit_5"));
        textEdit_5->setGeometry(QRect(10, 220, 251, 31));
        pushButton->raise();
        textEdit->raise();
        listView->raise();
        label_2->raise();
        label_3->raise();
        textEdit_5->raise();
        uploadFrame = new QFrame(centralWidget);
        uploadFrame->setObjectName(QStringLiteral("uploadFrame"));
        uploadFrame->setGeometry(QRect(440, 230, 391, 291));
        uploadFrame->setFrameShape(QFrame::StyledPanel);
        uploadFrame->setFrameShadow(QFrame::Raised);
        frame = new QFrame(uploadFrame);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(10, 70, 370, 50));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        pushButton_2 = new QPushButton(frame);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(270, 10, 90, 30));
        textEdit_2 = new QTextEdit(frame);
        textEdit_2->setObjectName(QStringLiteral("textEdit_2"));
        textEdit_2->setGeometry(QRect(10, 10, 250, 30));
        textEdit_2->setStyleSheet(QStringLiteral(""));
        frame_2 = new QFrame(uploadFrame);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setGeometry(QRect(10, 159, 370, 121));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        textEdit_3 = new QTextEdit(frame_2);
        textEdit_3->setObjectName(QStringLiteral("textEdit_3"));
        textEdit_3->setGeometry(QRect(10, 30, 250, 30));
        textEdit_3->setStyleSheet(QStringLiteral(""));
        textEdit_4 = new QTextEdit(frame_2);
        textEdit_4->setObjectName(QStringLiteral("textEdit_4"));
        textEdit_4->setGeometry(QRect(10, 90, 250, 30));
        textEdit_4->setStyleSheet(QLatin1String("margin-top:2px;\n"
""));
        pushButton_3 = new QPushButton(frame_2);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(270, 30, 91, 91));
        label_7 = new QLabel(frame_2);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(20, 10, 140, 17));
        label_8 = new QLabel(frame_2);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(20, 70, 140, 20));
        label_5 = new QLabel(uploadFrame);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 50, 100, 16));
        label_6 = new QLabel(uploadFrame);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(10, 140, 100, 16));
        label_4 = new QLabel(uploadFrame);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(115, 10, 150, 20));
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
        menuBar->setGeometry(QRect(0, 0, 900, 25));
        MainWindow->setMenuBar(menuBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        label->setText(QApplication::translate("MainWindow", "Most Popular Playlists", 0));
        pushButton->setText(QApplication::translate("MainWindow", "Go", 0));
        label_2->setText(QApplication::translate("MainWindow", "Most Popular Playlist", 0));
        label_3->setText(QApplication::translate("MainWindow", "Search for a Song", 0));
        pushButton_2->setText(QApplication::translate("MainWindow", "Go", 0));
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
