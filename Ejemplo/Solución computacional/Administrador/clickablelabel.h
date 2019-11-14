#ifndef CLICKABLELABEL_H
#define CLICKABLELABEL_H

#include <QObject>
#include <QLabel>
#include <Qt>
#include <QDebug>
#include <iostream>

using namespace std;

class ClickableLabel : public QLabel
{
    Q_OBJECT
public:
    explicit ClickableLabel(QWidget* parent = Q_NULLPTR, Qt::WindowFlags f = Qt::WindowFlags());
    explicit ClickableLabel(const QString &text, QWidget *parent=nullptr, Qt::WindowFlags f=Qt::WindowFlags());
    ~ClickableLabel();
signals:
    void clicked(QString pNombre);
protected:
    void mousePressEvent(QMouseEvent* event);
};

#endif // CLICKABLELABEL_H
