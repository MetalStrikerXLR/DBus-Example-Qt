#include <QCoreApplication>
#include "mydbusservice.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    MyDBusService myDBusService;

    if (!QDBusConnection::sessionBus().registerService("com.example.MyDBusService")) {
        qCritical("Failed to register service to D-Bus: %s", qPrintable(QDBusConnection::sessionBus().lastError().message()));
        return 1;
    }
    if (!QDBusConnection::sessionBus().registerObject("/com/example/MyDBusService", &myDBusService, QDBusConnection::ExportAllSlots)) {
        qCritical("Failed to register object to D-Bus: %s", qPrintable(QDBusConnection::sessionBus().lastError().message()));
        return 1;
    }

    return a.exec();
}
