#ifndef MOVELABEL_H
#define MOVELABEL_H

#include <QLabel>

class MoveLabel : public QLabel
{
    Q_OBJECT
public:
    MoveLabel(QString fileName, QWidget *parent = nullptr);

private:
    QString filename{};

protected:
    void	mousePressEvent(QMouseEvent *ev) override;

signals:
    void click();
};

#endif // MOVELABEL_H
