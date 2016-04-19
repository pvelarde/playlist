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
#include "Song.h"
#include "Playlist.h"
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

std::string convTitleStream2StrNumStream(std::string inn_stream){
    string song_id_stream = ""; //test single playlist input: Friend Of God, Your Great Name, Collide, September 63
    std::string input = inn_stream;
    std::istringstream lineStream(input);
    std::string song_title;

    int counter = 0;
    while(std::getline(lineStream, song_title, ',')) {
        if(counter != 0)
            song_title = song_title.substr(1,song_title.size()-1);
        counter++;
        //std::cout << song_title << std::endl;
        song_id_stream += (((song_id_stream == "")?(""):(" ")) + sng_c->query_by_name(song_title)->get_song_id());
    }
    //std::cout << "before: " << inn_stream << '\n' << "after: " << song_id_stream << std::endl;
    return song_id_stream;
}

QAbstractItemModel *buildModel(){
    QStringList stringList;
    for(int ii = 1023, jj = 1; ii > 1015; ii--, jj++){
       string pl_id = pl_c->my_sorted_ids.at(ii);
       QString temp = QString::number(jj) + ": " + QString::fromStdString(convStrNumStream2TitleStream(pl_c->query(pl_id)->my_song_stream));
       //QString temp = "Playlist " + QString::number(ii); //QString::number(pl_c->pl_backend.size());
       stringList << temp;
    }


    QStringListModel *model = new QStringListModel(stringList);
    return model;
}

void updateGUI(){

}

void setInitialState(){
    QString fileName = QDir::homePath() + "/Desktop/playlist/Playlist/";
    //cout << fileName.toLatin1().data() << endl;
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
    QString fileName = ui->textEdit_2->toPlainText();
    string sFileName = fileName.toLatin1().data();
    std::cout << "Attempting to Upload: " + sFileName << std::endl;
    // test url: /Users/nick102795/Desktop/playlist/uploads/day01.txt

    QFile inputFile(fileName);
    if (inputFile.open(QIODevice::ReadOnly)){
       QTextStream in(&inputFile);
       srand(time(NULL));
       while (!in.atEnd()){
          QString line_temp = in.readLine();
          string line = line_temp.toUtf8().constData();
          string deliminator = "	";

          string str_of_song_ids = "";
          for(int ii = 0; ii < line.find(deliminator); ii++){
              str_of_song_ids += line[ii];
          }// + 2 since the deliminator is 2 characters long
          line = line.substr(line.find(deliminator)+1,line.length()-line.find(deliminator)+1);
          string pl_pop = line;
          int pl_popularity = atoi(pl_pop.c_str()); // was stoi but this version of C++ is bad
         //  std::cout << pl_pop << std::endl;

          // pl_popularity, str_of_song_ids are set at this point
          Playlist* new_pl = new Playlist(str_of_song_ids, pl_popularity);
          //std::cout << "ID: " << temp_str << " title: " << str_of_song_ids << " popularity: "<< pl_popularity << std::endl;
          pl_c->add(new_pl);
          pl_c->refine();
        }
           inputFile.close();
    }

    QListView *listView = ui->mostPopularPlaylistListView;
    QAbstractItemModel *model = buildModel();   // make the buildModel() func to intake the new most-popular PL strings
    listView->setModel(model);
    listView->show();

}

// single playlist adding
void MainWindow::on_pushButton_3_clicked(){
    ui->textEdit_3->setStyleSheet("color:black; background-color:white");
    playlistName = ui->textEdit_3->toPlainText();
    playlistPopularity = ui->textEdit_4->toPlainText();
    string sPlaylistName = playlistName.toLatin1().data();
    string sPlaylistPopularity = playlistPopularity.toLatin1().data();
    string song_id_stream = convTitleStream2StrNumStream(sPlaylistName);

    std::cout << "Single Playlist Submitted: " << (sPlaylistName + " " + sPlaylistPopularity) << std::endl;
    //test single playlist input: Friend Of God, Your Great Name, Collide, September 63

    // Convert users input stream of song names to IDs
    //string song_id_stream = convTitleStream2StrNumStream(sPlaylistName);
    // std::cout << "songs ids: " << song_id_stream << " pop: " << playlistPopularity.toInt() << std::endl;

    Playlist* new_pl = new Playlist(song_id_stream,playlistPopularity.toInt());
    // add a new playlist
    pl_c->add(new_pl);
    // refine is required to maintain the backend storage and so-on
    pl_c->refine();

    QListView *listView = ui->mostPopularPlaylistListView;
    QAbstractItemModel *model = buildModel();   // make the buildModel() func to intake the new most-popular PL strings
    listView->setModel(model);
    listView->show();
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
        songSuggestions << ((QString::fromStdString(suggested_vector->at(ii))) + " - " + QString::number(sng_c->query_by_name(suggested_vector->at(ii))->getPopularity()) + "🔥");
    }

    QStringListModel *model = new QStringListModel(songSuggestions);
    ui->listView->setModel(model);
}
