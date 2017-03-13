#include "droptable.h"

DropTable::DropTable(QWidget *parent) :
QTableView(parent)
{
	setAcceptDrops(true);
}

void DropTable::dragEnterEvent(QDragEnterEvent *event)
{

	event->acceptProposedAction();

}

void DropTable::dragMoveEvent(QDragMoveEvent *event)
{

	event->acceptProposedAction();

}

void DropTable::dropEvent(QDropEvent *event)
{
	senddragMoveEvent(event);

}


