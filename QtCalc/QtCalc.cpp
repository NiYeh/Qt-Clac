#include "QtCalc.h"
#include <QButtonGroup>
#include <math.h>

QtCalc::QtCalc(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::QtCalcClass())
{
    ui->setupUi(this);
    initUi();
}

QtCalc::~QtCalc()
{
    delete ui;
}

void QtCalc::initUi()
{
    // TODO 找到所有的按鈕 並放到數組裡面
    auto buttonGroup = new QButtonGroup(this);
    auto btnlist = findChildren<QPushButton*>();

    for (auto btn : btnlist) 
    {
        buttonGroup->addButton(btn);
    }
    
    // TODO 關聯按鈕組點擊信號
    connect(buttonGroup, &QButtonGroup::buttonClicked, this, &QtCalc::OnButtonGroupClick);
    vec.resize(5);
}

void QtCalc::OnButtonGroupClick(QAbstractButton* btn)
{
    float val = ui->lineEdit->text().toFloat();

    // qInfo() << btn->text();
    QString temp = btn->text();
    
    // TODO 如果是數字直接顯示
    if (temp >= "0" && temp <= "9" || temp == ".")
    {
        // TODO 前面有0要先刪掉
        if (ui->lineEdit->text() == "0" && temp != ".")
            ui->lineEdit->clear();

        // TODO 如果有運算符則重置輸入數字
        if (prevBtn == "+")
            ui->lineEdit->clear();
        else if (prevBtn == "-")
            ui->lineEdit->clear();
        else if (prevBtn == "x")
            ui->lineEdit->clear();
        else if (prevBtn == "÷")
            ui->lineEdit->clear();
        else if (prevBtn == "%")
            ui->lineEdit->clear();
        else if (prevBtn == "x²")
            ui->lineEdit->clear();

        ui->lineEdit->insert(temp);
    }

    else if (temp == "+")
    {
        if (vec[2].isNull())
        {
            // TODO 把左邊數值儲存起來
            vec[0] = val;
            vec[1] = "+";
        }
    }
    else if (temp == "-")
    {
        if (vec[2].isNull())
        {
            // TODO 把左邊數值儲存起來
            vec[0] = val;
            vec[1] = "-";
        }
    }
    else if (temp == "x")
    {
        if (vec[2].isNull())
        {
            // TODO 把左邊數值儲存起來
            vec[0] = val;
            vec[1] = "x";
        }
    }
    else if (temp == "÷")
    {
        if (vec[2].isNull())
        {
            // TODO 把左邊數值儲存起來
            vec[0] = val;
            vec[1] = "÷";
        }
    }
    else if (temp == "%")
    {
        if (vec[2].isNull())
        {
            // TODO 把左邊數值儲存起來
            vec[0] = val;
            vec[1] = "%";
        }
    }
    else if (temp == "x²")
    {
        if (vec[2].isNull())
        {
            // TODO 把左邊數值儲存起來
            vec[0] = val;
            vec[1] = "²";
        }
    }

    // TODO 當按下 = 符號時做出運算
    else if (temp == "=")
    {
        vec[2] = val;
        vec[3] = "=";

        if (vec[1] == "+")
        {
            vec[4] = vec[0].toFloat() + vec[2].toFloat();
        }
        else if (vec[1] == "-")
        {
            vec[4] = vec[0].toFloat() - vec[2].toFloat();
        }
        else if (vec[1] == "x")
        {
            vec[4] = vec[0].toFloat() * vec[2].toFloat();
        }
        else if (vec[1] == "÷")
        {
            vec[4] = vec[0].toFloat() / vec[2].toFloat();
        }
        else if (vec[1] == "%")
        {
            vec[4] = vec[0].toInt() % vec[2].toInt();
        }
        else if (vec[1] == "²")
        {
            vec[4] = vec[0].toInt() * vec[0].toInt();
        }
        ui->lineEdit->setText(vec[4].toString());
    }

    else if (temp == "C")
    {
        ui->lineEdit->clear();
        ui->lineEdit_2->clear();
        vec[0].clear();
        vec[1].clear();
        vec[2].clear();
        vec[3].clear();
        vec[4].clear();
    }
    else if (temp == "CE")
    {
        ui->lineEdit->clear();
    }
    else if (temp == "DEL")
    {
        ui->lineEdit->setCursorPosition(ui->lineEdit->cursorPosition() - 1);
        ui->lineEdit->del();
    }

    // TODO 顯示表達式
    ui->lineEdit_2->clear();
    for (auto var : vec)
    {
        ui->lineEdit_2->insert(var.toString());
    }
    prevBtn = temp;
}