#include "clickablelabel.h"

ClickableLabel::ClickableLabel(QWidget* parent, Qt::WindowFlags f)
    : QLabel(parent) {

}

ClickableLabel::ClickableLabel(const QString &text, QWidget *parent, Qt::WindowFlags f)
    :QLabel (parent) {
    this->setText(text);
}

ClickableLabel::~ClickableLabel() {}

void ClickableLabel::mousePressEvent(QMouseEvent* event) {
    QString nombre = this->text();
    emit clicked(nombre);
}
