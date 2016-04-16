#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>

class Playlist_Container;
class Song_Container;

extern Song_Container* sng_c;
extern Playlist_Container* pl_c;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_textEdit_textChanged();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::MainWindow *ui;
    QString songName;
    QString fileName;
    QString playlistName;
    QString playlistPopularity;
    QString suggestName;
};

#endif // MAINWINDOW_H
