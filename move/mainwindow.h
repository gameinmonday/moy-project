#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "movelabel.h"
#include "findform.h"
#include "movecard.h"
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
    void processMoveMarix();
private:
    Ui::MainWindow *ui;
    QStringList imgPathList{};
    QVector<QString> topicVector{};


    QStringList split(QString str);
    void readCsv(QString fileAddress);

    QMap<int, QVector<QString>> filmTable{};
    QStringList fileList{};

    FindForm *ff{};

protected:
    void resizeEvent(QResizeEvent *) override;
public slots:



private slots:

    void on_toolButton_clicked();

    void on_ac_find_triggered();

signals:
    void testSignal();
};
#endif // MAINWINDOW_H
