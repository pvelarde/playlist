//
//  Text_Parser.cpp
//  prac_PlayList
//
//  Created by Nick Maresco on 4/5/16.
//  Copyright © 2016 ___Marss___. All rights reserved.
//

#include "Text_Parser.h"

Text_Parser::Text_Parser(QString file_name){
    this->my_file = file_name;
}

Text_Parser::~Text_Parser(){

}

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

Song_Container* Text_Parser::parse_song_text(){
    Song_Container * sng_c = new Song_Container();

  /*  std::string line;
    std::ifstream myfile (this->my_file.c_str());
    if (myfile.is_open())
    {
        sng_c = new Song_Container();
        while ( getline (myfile,line) )
        {
            string deliminator = "	";

            // find id
            string id = "";
            for(int ii = 0; ii < line.find(deliminator); ii++){
                id += line[ii];
            }
            line = line.substr(line.find(deliminator)+1,line.length()-line.find(deliminator)+1);

            string song_name = "";
            for(int ii = 0; ii < line.find(deliminator); ii++){
                song_name += line[ii];
            }
            line = line.substr(line.find(deliminator)+1,line.length()-line.find(deliminator)+1);

            // find song artist
            string artist_name = line;


            // id, song_name, and artist_name are set at this point
            Song* new_song = new Song(id,song_name,artist_name);
            sng_c->add(new_song);

        }
        myfile.close();
    }

    else cout << "Unable to open file ";*/

    QFile inputFile(this->my_file);
    if (inputFile.open(QIODevice::ReadOnly))
    {
       QTextStream in(&inputFile);
       while (!in.atEnd())
       {
          QString line_temp = in.readLine();
          string line = line_temp.toUtf8().constData();
          string deliminator = "	";

          // find id
          string id = "";
          for(int ii = 0; ii < line.find(deliminator); ii++){
              id += line[ii];
          }
          line = line.substr(line.find(deliminator)+1,line.length()-line.find(deliminator)+1);

          string song_name = "";
          for(int ii = 0; ii < line.find(deliminator); ii++){
              song_name += line[ii];
          }
          line = line.substr(line.find(deliminator)+1,line.length()-line.find(deliminator)+1);

          // find song artist
          string artist_name = line;

          // id, song_name, and artist_name are set at this point
          Song* new_song = new Song(id,song_name,artist_name);
          sng_c->add(new_song);

          //qDebug() << line_temp;
       }
       inputFile.close();
    }
    return sng_c;
}

char createRandom(){
    const char alphanum[] =
    "0123456789"
    "!@#$%^&*"
    "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    "abcdefghijklmnopqrstuvwxyz";
    int stringLength = sizeof(alphanum) - 1;
    return alphanum[rand() % stringLength];
}

Playlist_Container* Text_Parser::parse_playlist_text(){
    Playlist_Container* pl_c =  new Playlist_Container();
/*
    string line;
    ifstream myfile (this->my_file.c_str());
    if (myfile.is_open())
    {
        pl_c = new Playlist_Container();
        while ( getline (myfile,line))
        {
            string deliminator = " 	";
            string str_of_song_ids = "";
            for(int ii = 0; ii < line.find(deliminator); ii++){
                str_of_song_ids += line[ii];
            }// + 2 since the deliminator is 2 characters long
            line = line.substr(line.find(deliminator)+2,line.length()-line.find(deliminator)+1);
            string pl_pop = line;
            int pl_popularity = atoi(pl_pop.c_str()); // was stoi but this version of C++ is bad

            srand(time(0));
            string temp_str = "";
            for(unsigned int i = 0; i < 31; ++i){
                temp_str += createRandom();
            }
            cout << temp_str << endl;

            // pl_popularity, str_of_song_ids are set at this point
            Playlist* new_pl = new Playlist(temp_str, str_of_song_ids, pl_popularity);
            pl_c->add(new_pl);

        }
        myfile.close();
    }

    else cout << "Unable to open file";


*/

    /*int line_count = 0;
    QFile inputFile(this->my_file);
    if (inputFile.open(QIODevice::ReadOnly))
    {
       QTextStream in(&inputFile);
       srand(time(NULL));
       while (!in.atEnd()){
           line_count++;
       }
    inputFile.close();
    }*/

   // if(line_count <= 1024){
        int line_counter = 1;
        QFile inputFile(this->my_file);
        if (inputFile.open(QIODevice::ReadOnly)){
            QTextStream in(&inputFile);
            srand(time(NULL));
            while (!in.atEnd()){
                /*
                    This if statement is written from the perspective that
                    this is only being used for the initial load of 1024
                */
                if(line_counter > 1024){
                    //cout << "Hit max file upload size" << endl;
                    break;
                }

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
                string temp_str = "";
                for(unsigned int i = 0; i < 31; ++i){
                    temp_str += createRandom();
                }

                // pl_popularity, str_of_song_ids are set at this point
                Playlist* new_pl = new Playlist(temp_str, str_of_song_ids, pl_popularity);
                //std::cout << "ID: " << temp_str << " title: " << str_of_song_ids << " popularity: "<< pl_popularity << std::endl;
                pl_c->add(new_pl);
                line_counter++;
           }
           inputFile.close();
        }
  //  }
    return pl_c;
}
