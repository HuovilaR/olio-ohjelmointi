#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->N1, &QPushButton::clicked,
            this, &MainWindow::numberClickedHandler);
    connect(ui->N2, &QPushButton::clicked,
            this, &MainWindow::numberClickedHandler);
    connect(ui->N3, &QPushButton::clicked,
            this, &MainWindow::numberClickedHandler);
    connect(ui->N4, &QPushButton::clicked,
            this, &MainWindow::numberClickedHandler);
    connect(ui->N5, &QPushButton::clicked,
            this, &MainWindow::numberClickedHandler);
    connect(ui->N6, &QPushButton::clicked,
            this, &MainWindow::numberClickedHandler);
    connect(ui->N7, &QPushButton::clicked,
            this, &MainWindow::numberClickedHandler);
    connect(ui->N8, &QPushButton::clicked,
            this, &MainWindow::numberClickedHandler);
    connect(ui->N9, &QPushButton::clicked,
            this, &MainWindow::numberClickedHandler);
    connect(ui->N0, &QPushButton::clicked,
            this, &MainWindow::numberClickedHandler);

    connect(ui->add, &QPushButton::clicked,
            this, &MainWindow::addSubMulDivClickHandler);
    connect(ui->sub, &QPushButton::clicked,
            this, &MainWindow::addSubMulDivClickHandler);
    connect(ui->mul, &QPushButton::clicked,
            this, &MainWindow::addSubMulDivClickHandler);
    connect(ui->div, &QPushButton::clicked,
            this, &MainWindow::addSubMulDivClickHandler);


    connect(ui->clear, &QPushButton::clicked,
            this, &MainWindow::clearAndEnterClickHandler);
    connect(ui->enter, &QPushButton::clicked,
            this, &MainWindow::clearAndEnterClickHandler);

    state = 1;
    operand = -1;

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::numberClickedHandler()
{
    QPushButton *btn = qobject_cast<QPushButton*>(sender());
    QString digit = btn->text();

    if (state == 1) {
        number1 += digit;
        ui->num1->setText(number1);
    } else {
        number2 += digit;
        ui->num2->setText(number2);
    }
}

void MainWindow::addSubMulDivClickHandler()
{
    QPushButton *btn = qobject_cast<QPushButton*>(sender());
    QString op = btn->text();

    if (op == "+") operand = 0;
    else if (op == "-") operand = 1;
    else if (op == "*") operand = 2;
    else if (op == "/") operand = 3;

    state = 2;
}
void MainWindow::clearAndEnterClickHandler()
{
    QPushButton *btn = qobject_cast<QPushButton*>(sender());

    if (btn == ui->clear) {
        state = 1;
        number1 = "";
        number2 = "";
        ui->num1->clear();
        ui->num2->clear();
        ui->result->clear();
        return;
    }

    if (btn == ui->enter) {
        float n1 = number1.toFloat();
        float n2 = number2.toFloat();

        switch (operand) {
        case 0: result = n1 + n2;
            break;
        case 1: result = n1 - n2;
            break;
        case 2: result = n1 * n2;
            break;
        case 3: result = n1 / n2;
            break;
        }

        ui->result->setText(QString::number(result));
    }
}
