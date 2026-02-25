#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QDebug>
#include <QTimer>
#include <iostream>

using namespace std;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    pQTimer = new QTimer(this);
    connect(pQTimer, &QTimer::timeout,
            this, &MainWindow::timeout);

    connect(ui->start, &QPushButton::clicked,
            this, &MainWindow::clickHandler);
    connect(ui->stop, &QPushButton::clicked,
            this, &MainWindow::clickHandler);
    connect(ui->player1, &QPushButton::clicked,
            this, &MainWindow::clickHandler);
    connect(ui->player2, &QPushButton::clicked,
            this, &MainWindow::clickHandler);
    connect(ui->time1, &QPushButton::clicked,
            this, &MainWindow::clickHandler);
    connect(ui->time2, &QPushButton::clicked,
            this, &MainWindow::clickHandler);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::clickHandler()
{
    QPushButton *btn = qobject_cast<QPushButton*>(sender());

    if (btn == ui->start){
        startGame();
}
    else if(btn == ui->stop){
        endGame();
        setGameInfoText("New game via start button", 11);

}
    else if(btn == ui->player1){
        currentPlayer = 1;
        setGameInfoText("Game ongoing", 11);
}
    else if(btn == ui->player2){
        currentPlayer = 2;
        setGameInfoText("Game ongoing", 11);
}
    else if(btn == ui->time1){
        gameTime = 120;
        setGameInfoText("ready to play", 11);
}
    else if(btn == ui->time2){
        gameTime = 300;
        setGameInfoText("ready to play", 11);
 }
}
void MainWindow::startGame()
{
    ui->progressBar->setMinimum(0);
    ui->progressBar->setMaximum(gameTime);

    ui->progressBar_2->setMinimum(0);
    ui->progressBar_2->setMaximum(gameTime);

    player1Time = gameTime;
    player2Time = gameTime;
    cout<< "pelaajan 1 aika "<< player1Time << " " << endl;
    cout<< "pelaajan 2 aika "<< player2Time << " " << endl;
    cout << "Peli aika " << gameTime << " " << endl;

    currentPlayer = 1;

    updateProgressBar();
    pQTimer->start(1000);

}

void MainWindow::endGame()
{
    pQTimer->stop();
    updateProgressBar();
}

void MainWindow::timeout()
{
    if (currentPlayer == 1)
        player1Time --;
    else
        player2Time --;

    updateProgressBar();

    if (player1Time <= 0){
         setGameInfoText("Player 2 won", 11);
        endGame();
    }

    else if (player2Time <= 0) {
        setGameInfoText("Player 1 won", 11);
        endGame();

    }
}

void MainWindow::updateProgressBar()
{
    ui->progressBar->setValue(player1Time);
    ui->progressBar_2->setValue(player2Time);
}

void MainWindow::setGameInfoText(QString text, short fontSize)
{
    QFont font = ui->label->font();

    font.setPointSize(fontSize);
    ui->label->setFont(font);
    ui->label->setText(text);
}




