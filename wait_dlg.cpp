#include "wait_dlg.h"

Wait_Dlg::Wait_Dlg(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	setWindowTitle(tr("Busy Wait"));
	movie = new QMovie("./icon/wait.gif");
	ui.label->setMovie(movie);
}

Wait_Dlg::~Wait_Dlg()
{

}
void Wait_Dlg::Display()
{
    movie->start();

}

void Wait_Dlg::Set(QString str)
{
	ui.label_2->setText(str);
}
void Wait_Dlg:: m_Close()
{
	close();
}
