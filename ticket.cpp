#include "ticket.h"

Ticket::Ticket(QObject *parent) : QObject(parent)
{

    ticketImage = new QGraphicsScene(0,0,200,300);
    QGraphicsTextItem * name = new QGraphicsTextItem;
//    name = new QGraphicsTextItem("placeholder");
    name->setPos(0,0);
    name->setPlainText("placeholder");
    ticketImage->addItem(name);
}

QGraphicsScene * Ticket::render()
{
    return ticketImage;
}

//void Ticket::setTicket(QString name, int price)
//{

//}

