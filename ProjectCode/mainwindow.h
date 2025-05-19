#pragma once

#include <QMainWindow>

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

private slots:

    void on_BTN1_clicked();

    void on_BTN0_clicked();

    void on_BTN2_clicked();

    void on_BTN3_clicked();

    void on_BTN4_clicked();

    void on_BTN5_clicked();

    void on_BTN6_clicked();

    void on_BTN7_clicked();

    void on_BTN8_clicked();

    void on_BTN9_clicked();

    void on_BTNAdd_clicked();

    void on_BTNEqual_clicked();

    void on_BTNSub_clicked();

    void on_BTNMultiply_clicked();

    void on_BTNDivide_clicked();

    void on_BTNbackspace_clicked();

    void on_BTNDecimal_clicked();



    void on_BTNClear_clicked();

    void on_BTNEntryClear_clicked();

    void on_BTNRoot_clicked();

    void on_BTNSquared_clicked();

    void on_BTNInverse_clicked();

    void on_BTNPercent_clicked();

    void on_BTNSign_clicked();

    void ChangeHistory(QString history2);

    void on_MemoryClear_clicked();

    void on_MemoryAdd_clicked();

    void on_MemorySub_clicked();



    void on_MemoryRecall_clicked();

    void on_MemoryStore_clicked();

    void on_HistoryClear_clicked();



    void on_BTNEntryClear_2_clicked();

    void on_BTNEntryClear_3_clicked();

    void on_BTNEntryClear_4_clicked();

    void on_BTNEntryClear_5_clicked();

    void on_BTNEntryClear_6_clicked();

    void on_BTNEntryClear_7_clicked();

    void on_BTNEntryClear_8_clicked();

    void on_BTNEntryClear_9_clicked();

    void on_BTNEntryClear_10_clicked();

    void on_BTNEntryClear_11_clicked();

    void on_BTNEntryClear_12_clicked();

    void on_BTNEntryClear_13_clicked();

    void on_BTNEntryClear_14_clicked();

    void on_BTNEntryClear_15_clicked();

    void on_BTNEntryClear_16_clicked();

    void on_BTNEntryClear_17_clicked();

private:
    Ui::MainWindow* ui;
};


int Split(std::string input);

