#ifndef CONNEXTION_H
#define CONNEXTION_H
#include <QSqldatabase>
#include <QString>

class connextion
{
public:
    QString id, password;
    connextion();
    QString get_id();
    QString get_password();
    bool ouvrir_connextion();
};

#endif // CONNEXTION_H
