#ifndef TICKET_H
#define TICKET_H
#include <QObject>
#include <QGraphicsScene>
#include <QPainter>
#include <QGraphicsTextItem>

class Ticket : public QObject
{
    Q_OBJECT
public:
    explicit Ticket(QObject *parent = 0);
    QGraphicsScene * render();
//    void setTicket(QString name, int price);
private:
    QGraphicsScene * ticketImage;

signals:

public slots:
};

#endif // TICKET_H
