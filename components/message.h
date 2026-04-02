#pragma once

#include "private/utils.h"
#include "color.h"

#include <QString>
#include <QLabel>
#include <QHash>
#include <QPoint>
#include <QPropertyAnimation>
#include <QGraphicsOpacityEffect>
#include <QParallelAnimationGroup>

namespace Element
{
    class MessageManager;

    class Message : public QWidget
    {
        Q_OBJECT

        friend class MessageManager;


    public:
        enum class Type
        {
            Primary,
            Success,
            Warning,
            Info,
            Error
        };

        enum class Place
        {
            Top,
            TopLeft,
            TopRight,
            Bottom,
            BottomLeft,
            BottomRight
        };

    public:
        Message& setMessage(const QString& message);
        Message& setParamater(const QString& paramater);
        Message& setType(Type type);
        Message& setPlain(bool plain);
        Message& setShowClose(bool showClose, bool autoClose = true);
        Message& setPlacement(Place place);
        Message& setDuration(int msec);
        Message& setOnClose(bool onClose);

    public:
        Message(const QString& message, MessageManager* manager = nullptr, QWidget* parent = nullptr);
        Message(const QString& message, const QString& paramater, MessageManager* manager = nullptr, QWidget* parent = nullptr);
        Message(const QString& message, Type type = Type::Info, MessageManager* manager = nullptr, QWidget* parent = nullptr);
        Message(const QString& message, const QString& paramater, Type type = Type::Info, MessageManager* manager = nullptr, QWidget* parent = nullptr);

        void show();

    signals:
        void closed();

    private:
        void updateTextAndIcon();
        void updatePosition();

        QString getColor();
        QString getBorderColor();
        QString getBackgroundColor();
        QPixmap getIcon();
        Place getPlacement();

        void stopFadeIn();
        void onTimeout();

    protected:
        void paintEvent(QPaintEvent *event) override;

    private:
        QString _message;
        QString _paramater;

    private:
        Type _type = Type::Info;
        Place _placement = Place::Top;
        bool _plain = false;
        bool _showClose = false;
        bool _onClose = false;
        int _duration = 3000;

    private:
        QSSHelper _qsshelper;
        QLabel* _icon;
        QLabel* _text;
        QTimer* _timer;
        QPropertyAnimation* _opaAni;
        QPropertyAnimation* _moveAni;
        QGraphicsOpacityEffect* _opaEff;
        QParallelAnimationGroup* _fadeIn;
        QParallelAnimationGroup* _fadeOut;

        MessageManager* _manager;
    };

    inline uint qHash(Message::Place key, uint seed = 0) noexcept {
        return static_cast<uint>(std::hash<int>{}(static_cast<int>(key))) ^ seed;
    }
}
