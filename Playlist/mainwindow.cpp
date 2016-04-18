#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QListView>
#include <QStringList>
#include <QAbstractItemModel>
#include <QStringListModel>
#include <iostream>
#include <fstream>
#include "Playlist_Container.h"
#include "Song_Container.h"
#include "Text_Parser.h"
#include "Try.h"
#include <QString>
#include <QFile>
#include <QDir>
#include <QDebug>

/* // QString -> string
 cout << QDir::homePath().toLatin1().data() << endl; // convert Qstring to c_string
*/

/* // FILE I/O
     QFile inputFile(fileName);
    if (inputFile.open(QIODevice::ReadOnly))
    {
       QTextStream in(&inputFile);
       while (!in.atEnd())
       {
          QString line = in.readLine();
          qDebug() << line;
       }
       inputFile.close();
    }
*/


Song_Container* sng_c = NULL;// new Song_Container();
Playlist_Container* pl_c = NULL; // new Playlist_Container();
Try* song_tree = NULL; // new Trie();

QAbstractItemModel *buildModel(){
    QStringList stringList;

    /*for(int ii = 0; ii < 9; ii++){
        QString temp = "Playlist " + QString::number(ii); //QString::number(pl_c->pl_backend.size());
        stringList << temp;
    }*/

    for(int ii = 1023, jj = 1; ii > 1015; ii--, jj++){
       string pl_id = pl_c->my_sorted_ids.at(ii);
       /*std::cout << "id: " << pl_id << "my songs: " <<
       pl_c->query(pl_id)->my_song_stream << " popularity: " <<
       pl_c->query(pl_id)->getPopularity() << std::endl;*/
       QString temp = QString::number(jj) + ": " + QString::fromStdString(pl_c->query(pl_id)->my_song_stream);
       //QString temp = "Playlist " + QString::number(ii); //QString::number(pl_c->pl_backend.size());
       stringList << temp;
    }


    QStringListModel *model = new QStringListModel(stringList);
    return model;
}

void setInitialState(){
    QString fileName = QDir::homePath() + "/Desktop/playlist/Playlist/";
    //cout << QDir::homePath().toLatin1().data() << endl;
    // load up songs from file
    Text_Parser* song_loader = new Text_Parser(fileName + "song_list.txt");
    Text_Parser* playlist_loader = new Text_Parser(fileName + "day00.txt");

    // load up the backend datastructures here
    // create song objects
    sng_c = song_loader->parse_song_text();
    // fill the playlist container
    pl_c = playlist_loader->parse_playlist_text();
    // sort all IDs in order of that playlist's popularity
    pl_c->sort_me();
    // load up all the song popularities, now that the playlists have been instanciated
    pl_c->update_song_popularities();
    // load all songs into the Trie
    song_tree = sng_c->load_trie_w_songs();
}

MainWindow::MainWindow(QWidget *parent) :QMainWindow(parent),ui(new Ui::MainWindow){
    ui->setupUi(this);
    // build all initial backend structures & load the appropriate data from files
    setInitialState();

    /*for(int ii = 1023; ii > 1015; ii--){
        string pl_id = pl_c->my_sorted_ids.at(ii);
        std::cout << "id: " << pl_id << "my songs: " << pl_c->query(pl_id)->my_song_stream << " popularity: " << pl_c->query(pl_id)->getPopularity() << std::endl;
    }*/

    // Set Up the top 8 Most Popular Playlists
    QListView *listView = ui->mostPopularPlaylistListView;
    QAbstractItemModel *model = buildModel();   // make the buildModel() func to intake the new most-popular PL strings
    listView->setModel(model);
    listView->show();
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::on_pushButton_clicked(){
    songName = ui->textEdit->toPlainText();
    //std::cout << "button clicked" << std::endl;
}

void MainWindow::on_pushButton_2_clicked(){
    fileName = ui->textEdit_2->toPlainText();
    //std::cout << "button2 clicked" << std::endl;
}

void MainWindow::on_pushButton_3_clicked(){
    playlistName = ui->textEdit_3->toPlainText();
    playlistPopularity = ui->textEdit_4->toPlainText();
    QString testString = playlistName + " " + playlistPopularity;
    //std::cout << "button3 clicked" << std::endl;
}

void MainWindow::on_textEdit_textChanged(){
    suggestName = ui->textEdit->toPlainText();
    string input = suggestName.toLatin1().data();
    QStringList songSuggestions;
    /*for (int i=0; i<4; i++)
    {
        QString songName;
        if (i <= suggestName.length()) songName = suggestName[i];
        else songName = "";
        songSuggestions << songName;
    }*/


    //song_tree->hasPrefix();
    vector<string>* suggested_vector = song_tree->hasPrefixAsVector(input);

    //std::cout << "inside vector: " << std::endl;
    for(int ii = 0; ii < suggested_vector->size(); ii++){
        //std::cout << suggested_vector->at(ii) << std::endl;
        songSuggestions << QString::fromStdString(suggested_vector->at(ii));
    }
    //std::cout << "leaving vector" << std::endl;
    //std::cout << "vector size: " << suggested_vector.size() << std::endl;

    // HERE HERE - At this point you need to refine the displayed list to the top 4 most popular songs


    QStringListModel *model = new QStringListModel(songSuggestions);
    ui->listView->setModel(model);
}
