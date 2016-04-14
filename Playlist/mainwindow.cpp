#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QListView>
#include <QStringList>
#include <QAbstractItemModel>
#include <QStringListModel>
#include "Playlist_Container.h"
#include "Song_Container.h"

Song_Container* sng_c = new Song_Container();
Playlist_Container* pl_c = new Playlist_Container();

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

    // load up the backend datastructures here

    // load up songs from file
    // create song objects


    // fill the playlist container



    // Set Up the top 8 Most Popular Playlists
    QListView *listView = ui->mostPopularPlaylistListView;
    QAbstractItemModel *model = buildModel();   // make the buildModel() func to intake the new most-popular PL strings
    listView->setModel(model);
    listView->show();


}

MainWindow::~MainWindow(){
    delete ui;
}
