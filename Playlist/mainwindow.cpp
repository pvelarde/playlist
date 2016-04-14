#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QListView>
#include <QStringList>
#include <QAbstractItemModel>
#include <QStringListModel>

QAbstractItemModel *buildModel(){
    QStringList stringList;

    for(int ii = 0; ii < 9; ii++){
        QString temp = "Playlist " + QString::number(ii);
        stringList << temp;
    }

    QStringListModel *model = new QStringListModel(stringList);
    return model;
}

MainWindow::MainWindow(QWidget *parent) :QMainWindow(parent),ui(new Ui::MainWindow){
    ui->setupUi(this);
    QListView *listView = ui->mostPopularPlaylistListView;
    QAbstractItemModel *model = buildModel();
    listView->setModel(model);
    listView->show();

}

MainWindow::~MainWindow(){
    delete ui;
}
