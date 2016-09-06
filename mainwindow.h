#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QObject>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QSerialPort>
#include <QDebug>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QPushButton>
#include <QLabel>
#include <QTextEdit>
#include <QGroupBox>
#include <QLineEdit>
#include <QComboBox>
#include <QCheckBox>
#include <QColor>
#include <QPalette>
#include <qwt_plot.h>
#include <QTimer>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QSerialPort serialPort;
    QTabWidget *tabWidget;
    QPushButton *openCom;
    QComboBox *comboBox1;//串口
    QComboBox *comboBox2;//波特率
    QComboBox *comboBox3;//数据位
    QComboBox *comboBox4;//停止位
    QComboBox *comboBox5;//奇偶校验
    QTextEdit *textEdit1;
    QTextEdit *textEdit2;
    QLabel *label8;
    QPushButton *sendButton;
    QTimer *timer;
    QCheckBox *checkBox2;
    QCheckBox *checkBox1;
    QCheckBox *checkBox3;
    QGroupBox *groupBox3;
    QGroupBox *groupBox4;
    char flag;
    uint32_t receiveCnt;
    uint32_t sendCnt;
    void setupUi();
private slots:
    void openCom_Button_Clicked();
    void sendButton_Clicked();
    void readCOM();
};

#endif // MAINWINDOW_H
