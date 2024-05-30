#ifndef MOVELABEL_H
#define MOVELABEL_H

#include <QLabel>

class MoveLabel : public QLabel
{
    Q_OBJECT
public:
    MoveLabel(QString fileName, QWidget *parent = nullptr);
    void drawPixmap(QPixmap p_pix);
private:
    QString filename{};
    QPixmap pix{};
protected:
    void	mousePressEvent(QMouseEvent *ev) override;
    void resizeEvent(QResizeEvent *) override;
signals:
    void click();
};

#endif // MOVELABEL_H
