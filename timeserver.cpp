#include "timeserver.h"
#include "ui_timeserver.h"

TimeServer::TimeServer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TimeServer)
{
    ui->setupUi(this);
}

TimeServer::~TimeServer()
{
    delete ui;
}
