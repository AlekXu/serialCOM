#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    resize(830,580);
    flag = 0;
    sendCnt = 0;

    setupUi ();
    setWindowTitle (tr("串口调试助手&XU"));
    connect (openCom,SIGNAL(clicked(bool)),this,SLOT(openCom_Button_Clicked()));
    connect (sendButton,SIGNAL(clicked(bool)),this,SLOT(sendButton_Clicked()));
    //comboBox1->setEnabled (false);
    //serialPort.setPortName ("COM1");
    //serialPort.setBaudRate (9600);
    //serialPort.setDataBits (QSerialPort::Data8);
    //serialPort.setParity (QSerialPort::NoParity);
    //serialPort.setStopBits (QSerialPort::OneStop);
    //serialPort.setFlowControl (QSerialPort::NoFlowControl);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setupUi ()
{
    tabWidget = new QTabWidget(this);

    tabWidget->setTabShape (QTabWidget::Triangular);//设置形状
    tabWidget->resize (830,580);

    //新建一个页面
    QWidget *widget = new QWidget(tabWidget);
    QGroupBox *groupBox1 = new QGroupBox(tr("串口配置"));
    QGroupBox *groupBox2 = new QGroupBox(tr("串口辅助"));
    groupBox3 = new QGroupBox(tr("接收区:已接收0字节,速度0字节/秒"));
    groupBox4 = new QGroupBox(tr("发送区:已发送0字节"));
    QGridLayout *gridLayout = new QGridLayout();
    gridLayout->addWidget (groupBox1,0,0,2,1);
    gridLayout->addWidget (groupBox2,2,0,3,1);
    gridLayout->addWidget (groupBox3,0,1,3,4);
    gridLayout->addWidget (groupBox4,3,1,2,4);
    //gridLayout->setContentsMargins(20,20,20,20);//设置布局内部四边的空隙
    QLabel *label1 = new QLabel(tr(" 端 口:"));
    QLabel *label2 = new QLabel(tr("波特率:"));
    QLabel *label3 = new QLabel(tr("数据位:"));
    QLabel *label4 = new QLabel(tr("停止位:"));
    QLabel *label5 = new QLabel(tr(" 校 验:"));
    label8 = new QLabel();
    label8->setPixmap (QPixmap("F:\\Git\\QT\\test\\serialCOM\\off.png"));
    comboBox1 = new QComboBox();
    /*foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
    {
        serialPort.setPort(info);
        if (serialPort.open(QIODevice::ReadWrite))
        {
            comboBox1->addItem (info.portName ());
            serialPort.close();
        }
    }*/
    comboBox1->insertItem (0,"COM1");
    comboBox1->insertItem (1,"COM2");
    comboBox1->insertItem (2,"COM3");
    comboBox1->insertItem (3,"COM4");
    comboBox1->insertItem (4,"COM5");
    comboBox1->insertItem (5,"COM6");
    comboBox1->insertItem (6,"COM7");
    comboBox1->insertItem (7,"COM8");
    comboBox1->insertItem (8,"COM9");
    comboBox1->insertItem (9,"COM10");
    comboBox1->insertItem (10,"COM11");
    comboBox1->setEditable (false);
    comboBox2 = new QComboBox();
    comboBox2->insertItem (0,"1200");
    comboBox2->insertItem (1,"2400");
    comboBox2->insertItem (2,"4800");
    comboBox2->insertItem (3,"9600");
    comboBox2->insertItem (4,"14400");
    comboBox2->insertItem (5,"19200");
    comboBox2->insertItem (6,"38400");
    comboBox2->insertItem (7,"56000");
    comboBox2->insertItem (8,"57600");
    comboBox2->insertItem (9,"115200");
    comboBox2->setMaxVisibleItems (6);
    comboBox2->setCurrentIndex (3);
    comboBox3 = new QComboBox();
    comboBox3->insertItem (0,"5");
    comboBox3->insertItem (1,"6");
    comboBox3->insertItem (2,"7");
    comboBox3->insertItem (3,"8");
    comboBox3->setCurrentIndex (3);
    comboBox4 = new QComboBox();
    comboBox4->insertItem (0,"1");
    comboBox4->insertItem (1,"2");
    comboBox4->setCurrentIndex (0);
    comboBox5 = new QComboBox();
    comboBox5->insertItem (0,"NONE");
    comboBox5->insertItem (1,"ODD");
    comboBox5->insertItem (2,"EVEN");
    openCom = new QPushButton("打开串口");
    QHBoxLayout *hLayout1 = new QHBoxLayout();
    QHBoxLayout *hLayout2 = new QHBoxLayout();
    QHBoxLayout *hLayout3 = new QHBoxLayout();
    QHBoxLayout *hLayout4 = new QHBoxLayout();
    QHBoxLayout *hLayout5 = new QHBoxLayout();
    //最后添加，为了给按键添加图片
    QHBoxLayout *hLayout13 = new QHBoxLayout();
    QVBoxLayout *vLayout = new QVBoxLayout();
    //串口辅助设计
    //在界面上插入图片
    QLabel *label7 = new QLabel();
    label7->setPixmap (QPixmap("F:\\Git\\QT\\test\\serialCOM\\changan.ico"));
    //label7->setPixmap (QIcon("changan.ico"));
    checkBox1 = new QCheckBox("Hex发送");
    checkBox2 = new QCheckBox("Hex显示");
    checkBox3 = new QCheckBox("连续发送");
    QLineEdit *lineEdit1 = new QLineEdit();
    lineEdit1->setText ("1000");
    QPushButton *button1 = new QPushButton("清发送区");
    QPushButton *button2 = new QPushButton("清接受区");
    QPushButton *button3 = new QPushButton("重新计数");
    QHBoxLayout *hLayout6 = new QHBoxLayout();
    QHBoxLayout *hLayout7 = new QHBoxLayout();
    QHBoxLayout *hLayout8 = new QHBoxLayout();
    QHBoxLayout *hLayout9 = new QHBoxLayout();
    hLayout6->addWidget (checkBox1);
    hLayout6->addWidget (checkBox2);
    hLayout7->addWidget (checkBox3);
    hLayout7->addWidget (lineEdit1);
    hLayout8->addWidget (button1);
    hLayout8->addWidget (button2);
    hLayout9->addWidget (button3);
    QVBoxLayout *vLayout1 = new QVBoxLayout();
    vLayout1->addLayout (hLayout6);
    vLayout1->addLayout (hLayout7);
    vLayout1->addLayout (hLayout8);
    vLayout1->addLayout (hLayout9);
    vLayout1->addWidget (label7);
    //vLayout1->addStretch (50);

    //groupBox2->setLayout (vLayout1);
    //布局
    hLayout1->addWidget (label1);
    hLayout1->addWidget (comboBox1);
    hLayout1->addSpacing (10);

    hLayout2->addWidget (label2);
    hLayout2->addWidget (comboBox2);
    hLayout2->addSpacing (10);

    hLayout3->addWidget (label3);
    hLayout3->addWidget (comboBox3);
    hLayout3->addSpacing (10);

    hLayout4->addWidget (label4);
    hLayout4->addWidget (comboBox4);
    hLayout4->addSpacing (10);

    hLayout5->addWidget (label5);
    hLayout5->addWidget (comboBox5);
    hLayout5->addSpacing (10);

    hLayout13->addWidget (label8);
    hLayout13->addSpacing (10);
    hLayout13->addWidget (openCom);
    hLayout13->addSpacing (10);

    vLayout->addLayout (hLayout1);
    vLayout->addLayout (hLayout2);
    vLayout->addLayout (hLayout3);
    vLayout->addLayout (hLayout4);
    vLayout->addLayout (hLayout5);
    vLayout->addLayout (hLayout13);
    //vLayout->addWidget (openCom);

    textEdit1 = new QTextEdit();
    //背景设置为黑 文字设置为白 设置失败
    //textEdit1->setStyleSheet ("background-color:black");
    //QPalette palette;
    //palette.setColor (QPalette::Active,QPalette::Base,Qt::white);
    //palette.setColor (QPalette::Inactive,QPalette::Base,Qt::white);
    //textEdit1->setPalette (palette);
    QHBoxLayout *hLayout10 = new QHBoxLayout();
    hLayout10->addWidget (textEdit1);

    textEdit2 = new QTextEdit();
    sendButton = new QPushButton(" 发送 ");
    QPushButton *sendMoreButton = new QPushButton("多项发送");
    QHBoxLayout *hLayout11 = new QHBoxLayout();
    QHBoxLayout *hLayout12 = new QHBoxLayout();
    QVBoxLayout *vLayout2 = new QVBoxLayout();

    hLayout11->addWidget (sendButton);
    hLayout11->addSpacing (1000);
    hLayout11->addWidget (sendMoreButton);
    hLayout12->addWidget (textEdit2);
    vLayout2->addLayout (hLayout12);
    vLayout2->addLayout (hLayout11);

    groupBox4->setLayout (vLayout2);

    groupBox3->setLayout (hLayout10);
    groupBox1->setLayout (vLayout);
    groupBox2->setLayout (vLayout1);
    widget->setLayout(gridLayout);

    QwtPlot *plot = new QwtPlot();
    //QLabel *label = new QLabel("Hello Qt");
    QLabel *label6 = new QLabel("Hello Qt");
    //添加页面
    tabWidget->addTab(widget,tr("串口调试助手"));
    tabWidget->addTab(plot,tr("虚拟示波器"));
    tabWidget->addTab(label6,tr("PID参数整定助手"));
    tabWidget->show ();

    //QHBoxLayout *layout = new QHBoxLayout(this);
    //layout->addWidget (tabWidget);
}

void MainWindow::openCom_Button_Clicked ()
{
    if(flag == 0)
    {
        //打开界面设置
        comboBox1->setEnabled (false);
        comboBox2->setEnabled (false);
        comboBox3->setEnabled (false);
        comboBox4->setEnabled (false);
        comboBox5->setEnabled (false);
        openCom->setText ("关闭串口");
        label8->setPixmap (QPixmap("F:\\Git\\QT\\test\\serialCOM\\on.png"));
        //串口设置
        serialPort.setPortName (comboBox1->currentText ());
        serialPort.setBaudRate (comboBox2->currentText ().toInt ());
        switch(comboBox5->currentIndex())
        {
            case 0: serialPort.setParity(QSerialPort::NoParity);break;
            case 1: serialPort.setParity(QSerialPort::OddParity);break;
            case 2: serialPort.setParity(QSerialPort::EvenParity);break;
            default: break;
        }
        switch(comboBox3->currentIndex())
        {
            case 0: serialPort.setDataBits(QSerialPort::Data5);break;
            case 1: serialPort.setDataBits(QSerialPort::Data6);break;
            case 2: serialPort.setDataBits(QSerialPort::Data7);break;
            case 3: serialPort.setDataBits(QSerialPort::Data8);break;
            default: break;
        }
        switch(comboBox4->currentIndex())
        {
            case 0: serialPort.setStopBits(QSerialPort::OneStop);break;
            case 1: serialPort.setStopBits(QSerialPort::TwoStop);break;
            default: break;
        }
        //serialPort.setDataBits (QSerialPort::Data8);
        //serialPort.setParity (QSerialPort::NoParity);
        //serialPort.setStopBits (QSerialPort::OneStop);
        serialPort.setFlowControl (QSerialPort::NoFlowControl);
        serialPort.open (QIODevice::ReadWrite);
        /*if(serialPort.open (QIODevice::ReadWrite))
        {
            serialPort.write ("hehe");
            //connect(&serialPort,SIGNAL(readyRead()),this,SLOT(readCOM));
        }*/
        timer = new QTimer();
        connect(timer,SIGNAL(timeout()),this,SLOT(readCOM()));
        timer->start (500);//msec

        flag = 1;
    }
    else
    {
        timer->stop();//定时器停止，防止程序崩溃
        comboBox1->setEnabled (true);
        comboBox2->setEnabled (true);
        comboBox3->setEnabled (true);
        comboBox4->setEnabled (true);
        comboBox5->setEnabled (true);
        openCom->setText ("打开串口");
        label8->setPixmap (QPixmap("F:\\Git\\QT\\test\\serialCOM\\off.png"));

        serialPort.close ();
        flag = 0;
    }

}

void MainWindow::sendButton_Clicked ()
{
    serialPort.write(textEdit2->toPlainText ().toLatin1 ());
}

void MainWindow::readCOM ()
{
    QByteArray requestData;
    requestData = serialPort.readAll ();
    if(requestData != NULL)
    {
        //textEdit1->setText (tr(requestData));
        //textEdit1->append(tr(requestData));
        if(checkBox2->isChecked ())//选中了
        {
            textEdit1->insertPlainText (requestData.toHex ());
        }
        else//没选中
        {
            textEdit1->insertPlainText (tr(requestData));
            textEdit1->moveCursor (QTextCursor::End);
        }
        receiveCnt += requestData.size ();
        //groupBox3
        groupBox3->setTitle ("接收区:已接收receiveCnt字节,速度0字节/秒");
    }
    requestData.clear();
}

