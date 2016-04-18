#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QListView>
#include <QStringList>
#include <QAbstractItemModel>
#include <QStringListModel>
#include <iostream>
#include <fstream>
#include <sstream>
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

std::string convStrNumStream2TitleStream(std::string inn_stream){
    stringstream lineStream(inn_stream);
    string song_title_stream = "";
    string song_id;
    while (lineStream >> song_id){
        song_title_stream += (((song_title_stream == "")?(""):(", ")) + sng_c->query(song_id)->get_song_name());
    }
    return song_title_stream;
}

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
       QString temp = QString::number(jj) + ": " + QString::fromStdString(convStrNumStream2TitleStream(pl_c->query(pl_id)->my_song_stream));
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

// bottom left functionality for the most popularly associated playlist
void MainWindow::on_pushButton_clicked(){

    QString Qinput = ui->textEdit->toPlainText();
    string input = ui->textEdit->toPlainText().toLatin1().data();

    std::cout << "button clicked" << std::endl;
    ui->label_9->setStyleSheet("color:black; background-color:white");

    // need to do error checking in the case that the program crashes
    QString the_most_pop_playlist = QString::fromStdString(convStrNumStream2TitleStream(pl_c->query(sng_c->query_by_name(input)->get_song_most_pop_playlist_id())->my_song_stream));
    ui->label_9->setText(the_most_pop_playlist);
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
    ui->label_9->setStyleSheet("color:grey; background-color:white");
    ui->label_9->setText("The most popularly matched playlist...");

    suggestName = ui->textEdit->toPlainText();
    string input = suggestName.toLatin1().data();
    QStringList songSuggestions;
    vector<string>* suggested_vector = song_tree->hasPrefixAsVector(input);

    // sort the suggested_vector by song popularity
    int nn = suggested_vector->size();
    for (int ii = 0 ; ii < ( nn - 1 ); ii++){
        for (int jj = 0 ; jj < nn - ii - 1; jj++){
          if ( sng_c->query_by_name(suggested_vector->at(jj))->getPopularity() < sng_c->query_by_name(suggested_vector->at(jj + 1))->getPopularity()){ /* For decreasing order use < */
              //std::cout << this->query(this->my_sorted_ids.at(jj))->getPopularity() << std::endl;
            string swap = suggested_vector->at(jj);
            suggested_vector->at(jj)   = suggested_vector->at(jj+1);
            suggested_vector->at(jj+1) = swap;
          }
        }
      }
    // At this point, the song names sorted in the array are in popularity order



    for(int ii = 0; ii < suggested_vector->size(); ii++){
        songSuggestions << (QString::fromStdString(suggested_vector->at(ii)) + " " + QString::number(sng_c->query_by_name(suggested_vector->at(ii))->getPopularity()));
    }

    // HERE HERE - At this point you need to refine the displayed list to the top 4 most popular songs
    //vector<string> top4MostPopSongMatches;






    QStringListModel *model = new QStringListModel(songSuggestions);
    ui->listView->setModel(model);
}
