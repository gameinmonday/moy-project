#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "movelabel.h"
#include "findform.h"
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QStringList split(QString str);

    QMap<int, QVector<QString>> filmTable{};
public slots:


private slots:

    void on_toolButton_clicked();

signals:
    void testSignal();
};
#endif // MAINWINDOW_H
