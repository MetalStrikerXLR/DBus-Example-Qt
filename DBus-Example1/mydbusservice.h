#ifndef MYDBUSSERVICE_H
#define MYDBUSSERVICE_H
#include <QDBusConnection>
#include <QDBusError>


class MyDBusService: public QObject
{
    Q_OBJECT
    Q_CLASSINFO("D-Bus Interface", "com.example.MyDBusService")

public:
    MyDBusService(QObject *parent = nullptr) : QObject(parent) {}

public slots:
    QString hello() { return "Hello from MyDBusService"; }

};

#endif // MYDBUSSERVICE_H
