#pragma once

#include <QtWidgets/QWidget>
#include "ui_QtCalc.h"
#include <QVector>

QT_BEGIN_NAMESPACE
namespace Ui { class QtCalcClass; };
QT_END_NAMESPACE

class QtCalc : public QWidget
{
    Q_OBJECT

public:
    QtCalc(QWidget *parent = nullptr);
    ~QtCalc();
    
    void initUi();

public slots:
    void OnButtonGroupClick(QAbstractButton*btn);

private:
    Ui::QtCalcClass *ui;
    QVector<QVariant> vec;
    QString prevBtn;
};
