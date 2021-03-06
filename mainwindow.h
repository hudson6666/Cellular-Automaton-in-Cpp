#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "settings.h"
#include "cellcar.h"
#include "gamecontroller.h"
#include "arenawidget.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public slots:
    void redraw();
    void addCell(int x, int y, bool add);
    void increaseCC();

private slots:
    void on_LBrushRadioButton_clicked();
    void on_RBrushRadioButton_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

    void on_CarFactoryRadioButton_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_CarCollectorRadioButton_clicked();

    void on__1BrushRadioButton_clicked();

    void on_lBrushRadioButton_clicked();

    void on_rBrushRadioButton_clicked();

private:
    Ui::MainWindow *ui;
    GameController *gc;
    Settings settings;
};

#endif // MAINWINDOW_H
