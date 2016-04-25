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
#include <cmath>
#include <QFileDialog>

Song_Container* sng_c = NULL;// new Song_Container();
Playlist_Container* pl_c = NULL; // new Playlist_Container();
Try* song_tree = NULL; // new Trie();

bool isInteger(std::string & s)
{
   if(s.empty() || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+'))) return false ;

   char * p ;
   strtol(s.c_str(), &p, 10) ;

   return (*p == 0) ;
}

//check if the string is a legal playlist initiation format
bool is_legal_id_stream(std::string inn){
    bool result = true;
    // 234 2334 653 3455    23
    stringstream lineStream(inn);
    string song_id;
    while (lineStream >> song_id){
        if(!isInteger(song_id)){
            result = false;
            break;
        }
    }
    return result;
}

//checks if a string stream is legal
bool is_legal_input_str_stream(std::string in_ss){
    bool result = true;
    if(in_ss == ""){
        result = false;
        //std::cout << "illegal input: (Empty Input)" << std::endl;
    }
    else{
        stringstream lineStream(in_ss);
        string song_title;
        while(std::getline(lineStream, song_title, ',')) {
            // if the input string does not exist in the valid
            // song tree it is not a valid string stream
            if(song_title[0] == ' '){
                song_title = song_title.substr(1, song_title.length()-1);
            }

            if(song_tree->check(song_title) == 0){
                result = 0;
                //std::cout << "illegal input: " << song_title << std::endl;
                break;
            }
        }
    }
    if(result)
        //std::cout << "legal input" << std::endl;

    return result;
}

std::string redactParenthesis(std::string in_str){
    // This is a test function that is going to remove () from strings
    //std::string in_str = "Herl dsf , (This i vf ] 3sd(fg gfdg ][4";
    std::string result = "";
    for(int ii = 0; ii < in_str.length(); ii++){
        if(in_str[ii] == '('){
            int caught_index = ii;
            while(in_str[ii] != ')'){
              // if you never get a )
              if(ii == in_str.length() - 1){
                  for(int jj = caught_index; jj < in_str.length(); jj++){
                      result += in_str[jj];
                  }
              }
              ii++;
            }
            ii++;
        }
        if(ii <= in_str.length())
            result += in_str[ii];
    }
    return result;
}

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
       QString temp = QString::number(jj) + ": " + QString::fromStdString(redactParenthesis(convStrNumStream2TitleStream(pl_c->query(pl_id)->my_song_stream))) + " - 👍" + QString::number(pl_c->query(pl_id)->getPopularity());
       //QString temp = "Playlist " + QString::number(ii); //QString::number(pl_c->pl_backend.size());
       stringList << temp;
    }


    QStringListModel *model = new QStringListModel(stringList);
    return model;
}

void updateGUI(){

}

QString QProjectLocation = "";
void setInitialState(){
    QString proj_location = QDir::currentPath() + "";
    std::string project_root = proj_location.toLatin1().data();
    int where_playlist_dir_ii = project_root.find("playlist");
    std::string path_to_proj_dir = project_root.substr(0,where_playlist_dir_ii + 8);
    QString fileName = QString::fromStdString((path_to_proj_dir + "/Playlist/"));
    QProjectLocation = QString::fromStdString(path_to_proj_dir);

    // load up songs from file
    Text_Parser* song_loader = new Text_Parser(fileName + "song_list.txt");
    // This will however only load the first 2014 playlists due to the project contraints
    Text_Parser* playlist_loader = new Text_Parser(fileName + "all_playlists.txt");

    // load up the backend datastructures here
    // create song objects
    sng_c = song_loader->parse_song_text();
    // fill the playlist container
    pl_c = playlist_loader->parse_playlist_text();
    // sort all IDs in order of that playlist's popularity
    pl_c->sort_me_initially();
    // load up all the song popularities, now that the playlists have been instanciated
    pl_c->update_song_popularities();
    // load all songs into the Trie
    song_tree = sng_c->load_trie_w_songs();
}

MainWindow::MainWindow(QWidget *parent) :QMainWindow(parent),ui(new Ui::MainWindow){
    ui->setupUi(this);
    setWindowIcon(QIcon("/Users/nick102795/Desktop/favicon.ico"));
    // build all initial backend structures & load the appropriate data from files
    setInitialState();
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
    int check_val = song_tree->check(input);
    std::cout << check_val << std::endl;
    if(check_val > 0){
        ui->label_9->setStyleSheet("color:black; background-color:white");
        // need to do error checking in the case that the program crashes
        QString the_most_pop_playlist = QString::fromStdString(convStrNumStream2TitleStream(pl_c->query(sng_c->query_by_name(input)->get_song_most_pop_playlist_id())->my_song_stream));
        ui->label_9->setText(the_most_pop_playlist);
    }
}

// upload playlists from a file
void MainWindow::on_pushButton_2_clicked(){
    QString fileName = ui->textEdit_2->toPlainText();
    string sFileName = fileName.toLatin1().data();
    std::cout << "Attempting to Upload: " + sFileName << std::endl;
    // test url: /Users/nick102795/Desktop/main/School/College/year3/EC504/playlist/uploads/day01.txt

    int line_counter = 1;
    QFile inputFile(fileName);
    if (inputFile.open(QIODevice::ReadOnly)){
       QTextStream in(&inputFile);
       srand(time(NULL));
       while (!in.atEnd()){
           if(line_counter > 128){
               // one is only allowed to upload 128 lines
               break;
           }

          QString line_temp = in.readLine();
          string line = line_temp.toUtf8().constData();
          string deliminator = "	";

          //make sure there is at least one '\t' on that line


          int up_to = line.find(deliminator);
          if(up_to <= 0){
              // There is no tab deliminator to be found
              std::cout << "Tab Deliminator Error" << endl << "Exited due to error in the file." << endl <<"Successfully uploaded " << (line_counter - 1) << " playlists." << endl;
              break;
          }

          string str_of_song_ids = "";
          for(int ii = 0; ii < up_to; ii++){
              str_of_song_ids += line[ii];
          }
          line = line.substr(line.find(deliminator)+1,line.length()-line.find(deliminator)+1);
          string pl_pop = line;
          int pl_popularity = atoi(pl_pop.c_str()); // was stoi but this version of C++ is bad
          std::cout << "Playlists Uploaded: " << (line_counter - 1) << std::endl;
         //  std::cout << pl_pop << std::endl;

          if(!is_legal_id_stream(str_of_song_ids)){
              std::cout << "Exited due to error in the file." << endl <<"Successfully uploaded " << (line_counter - 1) << " playlists." << endl;
              break;
          }

          // pl_popularity, str_of_song_ids are set at this point
          Playlist* new_pl = new Playlist(str_of_song_ids, pl_popularity);
          //std::cout << "ID: " << temp_str << " title: " << str_of_song_ids << " popularity: "<< pl_popularity << std::endl;
          pl_c->add(new_pl);

          // add this playlists popularity to the song's pop
          for(int ii = 0; ii < new_pl->my_songs->size(); ii++){
              std::string member_song_id = new_pl->my_songs->at(ii);
              // sng_c->query(member_song_id)->set_song_popularity(sng_c->query(member_song_id)->getPopularity() + new_pl->getPopularity());
              sng_c->query((member_song_id))->song_add_playlist(new_pl->my_id);
          }
          line_counter++;
        }
           pl_c->refine();
           inputFile.close();
           QListView *listView = ui->mostPopularPlaylistListView;
           QAbstractItemModel* model = buildModel();   // make the buildModel() func to intake the new most-popular PL strings
           listView->setModel(model);
           listView->show();
    }
    else{
        std::cout << "Failed to open: " << sFileName << std::endl;
    }
    ui->textEdit_2->setText("");
}

// single playlist adding
void MainWindow::on_pushButton_3_clicked(){
    ui->textEdit_3->setStyleSheet("color:black; background-color:white");
    playlistName = ui->textEdit_3->toPlainText();
    playlistPopularity = ui->textEdit_4->toPlainText();
    string sPlaylistName = playlistName.toLatin1().data();
    string sPlaylistPopularity = playlistPopularity.toLatin1().data();
    //test single playlist input: Friend Of God, Your Great Name, Collide, September 63

    bool is_legal_pop = true;
    bool is_legal_ss = is_legal_input_str_stream(sPlaylistName);
    int dec = playlistPopularity.toInt(&is_legal_pop, 10);

    // some general console error logs
    if(!is_legal_ss && !is_legal_pop){
        std::cout << "illegal stream & illegal popularity inputs" << std::endl;
    }
    else if(!is_legal_ss){
        std::cout << "illegal stream input" << std::endl;
    }
    else if(!is_legal_pop){
        std::cout << "illegal popularity input" << std::endl;
    }

    if(is_legal_ss && is_legal_pop){
        string song_id_stream = convTitleStream2StrNumStream(sPlaylistName);
        std::cout << "Single Playlist Submitted: " << (sPlaylistName + " " + sPlaylistPopularity) << std::endl;

        Playlist* new_pl = new Playlist(song_id_stream,playlistPopularity.toInt());
        // add a new playlist
        pl_c->add(new_pl);

        // add this playlists popularity to the song's pop
        for(int ii = 0; ii < new_pl->my_songs->size(); ii++){
            std::string member_song_id = new_pl->my_songs->at(ii);
            // sng_c->query(member_song_id)->set_song_popularity(sng_c->query(member_song_id)->getPopularity() + new_pl->getPopularity());
            sng_c->query((member_song_id))->song_add_playlist(new_pl->my_id);
        }

        // refine is required to maintain the backend storage and so-on
        pl_c->refine();
        QListView *listView = ui->mostPopularPlaylistListView;
        QAbstractItemModel *model = buildModel();   // make the buildModel() func to intake the new most-popular PL strings
        listView->setModel(model);
        listView->show();
    }
}

void MainWindow::on_textEdit_textChanged(){
    ui->label_9->setStyleSheet("color:grey; background-color:white");
    ui->label_9->setText("The most popularly matched playlist...");
    suggestName = ui->textEdit->toPlainText();
    string input = suggestName.toLatin1().data();
    QStringList songSuggestions;
    vector<string>* suggested_vector = song_tree->hasPrefixAsVector(input);

    std::cout << suggested_vector->size() << std::endl;

    // check otherwise the vector could go out of range
    if(suggested_vector->size() > 0){
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
        double highest_found_pop = sng_c->query_by_name(suggested_vector->at(0))->getPopularity() * 1.0;
        int first_third=floor(highest_found_pop/3), second_third=(2*first_third);
        std::string fire = "🔥";
        for(int ii = 0; ii < suggested_vector->size(); ii++){
            std::string cur = suggested_vector->at(ii);
            int cur_pop = sng_c->query_by_name(cur)->getPopularity();

            std::string fire_rating;
            if(cur_pop == 0){
                fire_rating = "";
            }
            else if(cur_pop <= first_third){
                fire_rating = fire;
            }
            else if(cur_pop <= second_third){
                fire_rating = fire +fire;
            }
            else{
                fire_rating = fire + fire + fire;
            }
            songSuggestions << ((QString::fromStdString(cur)) + " - " + QString::number(cur_pop) + QString::fromStdString(fire_rating));
        }
        songSuggestions << "";
        QStringListModel *model = new QStringListModel(songSuggestions);
        ui->listView->setModel(model);
    }


}

void MainWindow::on_pushButton_4_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),QProjectLocation,tr("(*.txt)"));
    std::cout << fileName.toLatin1().data() << std::endl;
    if(fileName == ""){
        std::cout << "empty" << std::endl;
    }
    else{
        ui->textEdit_2->setText(fileName); //labe->setText(
    }

}
