#ifndef MYDBUSSERVICEADAPTOR_H
#define MYDBUSSERVICEADAPTOR_H

#include <QDBusConnection>
#include <QDBusError>
#include <QDBusAbstractAdaptor>

class MyDBusServiceAdaptor : public QDBusAbstractAdaptor
{
    Q_OBJECT
    Q_CLASSINFO("D-Bus Interface", "com.example.MyDBusAdapterService")
    Q_PROPERTY(QString greeting READ greeting WRITE setGreeting NOTIFY greetingChanged)

public:
    MyDBusServiceAdaptor(QObject *parent) : QDBusAbstractAdaptor(parent), m_greeting("Hello") {}

    QString greeting() const { return m_greeting; }
    void setGreeting(const QString &greeting) { m_greeting = greeting; }

signals:
    void greetingChanged();

public slots:
    QString hello() { return m_greeting + " from MyDBusAdapterService"; }

private:
    QString m_greeting;
};

#endif // MYDBUSSERVICEADAPTOR_H
