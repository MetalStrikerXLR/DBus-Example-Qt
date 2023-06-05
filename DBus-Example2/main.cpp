#include <QCoreApplication>
#include "MyDBusServiceAdaptor.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QObject myDBusService;
    MyDBusServiceAdaptor adaptor(&myDBusService);

    if (!QDBusConnection::sessionBus().registerService("com.example.MyDBusAdapterService")) {
        qCritical("Failed to register service to D-Bus: %s",
                  qPrintable(QDBusConnection::sessionBus().lastError().message()));
        return 1;
    }
    if (!QDBusConnection::sessionBus().registerObject("/com/example/MyDBusAdapterService", &adaptor,
                                                      QDBusConnection::ExportAllSlots)) {
        qCritical("Failed to register object to D-Bus: %s",
                  qPrintable(QDBusConnection::sessionBus().lastError().message()));
        return 1;
    }

    return a.exec();
}
