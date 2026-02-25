#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void timeout();
private:
    Ui::MainWindow *ui;
    QTimer *pQTimer;
    short gameTime;
    short currentPlayer;
    short player1Time;
    short player2Time;
    void updateProgressBar();
    void setGameInfoText(QString, short);
    void clickHandler();
    void startGame();
    void endGame();

};
#endif // MAINWINDOW_H
