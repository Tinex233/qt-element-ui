#ifndef MESSAGEMANAGER_H
#define MESSAGEMANAGER_H

#include "message.h"

#include <QObject>
#include <QHash>
#include <QList>
#include <QPropertyAnimation>
#include <QApplication>
#include <QScreen>

namespace Element
{
    class MessageManager : public QObject
    {
    Q_OBJECT

    public:
        MessageManager& setOffset(int offset);
        void addMessage(Element::Message* msg);
        void removeMessage(Element::Message* msg);

    public:
        MessageManager(QWidget* parentWidget);
        virtual ~MessageManager();

    private:
        int _offset = 20;

    private:
        QHash<Element::Message::Place, QList<Element::Message*>> _messagesList;

    protected:
        Message::Place getMsgPlacement(Message* msg);
        void stopMsgFadeIn(Message* msg);

    protected:
        virtual void adjust(Element::Message::Place placement);
        virtual QRect calNewMsgGeometry(Message* msg) const;
    };
}

#endif // MESSAGEMANAGER_H
