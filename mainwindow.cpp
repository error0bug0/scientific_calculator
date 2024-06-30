#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"QButtonGroup"
#include<QProcess>
#include<QWebEngineView>
#include<QTimer>
#include<QTableWidget>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ConnectBtn();
    InitGroup();
    //InitCalculus();
    ui->lineEdit_value->hide();
    QTimer* timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()),this, SLOT(TimeOut()));
    timer->start(500);
    connect(ui->storage_var,SIGNAL(itemChanged(QTableWidgetItem*)),this,SLOT(ChangeStorage()));
    connect(ui->storage_matrix,SIGNAL(itemChanged(QTableWidgetItem*)),this,SLOT(ChangeStorage()));
    QUrl exePath = QUrl(QCoreApplication::applicationFilePath());
    QUrl relativeUrl;
    relativeUrl=QUrl("../../../html/help.html");
    ui->HelpWeb->load(exePath.resolved(relativeUrl));

}


MainWindow::~MainWindow()
{
    process->kill();
    process->close();
    delete process;
    delete group;
    delete ui;
}

void MainWindow::ConnectBtn()
{
    //page_change_button
    connect(ui->BtnMainPage,SIGNAL(clicked()),this,SLOT(on_BtnMainPage_clicked()));
    connect(ui->BtnNormCalc,SIGNAL(clicked()),this,SLOT(on_BtnNormCalc_clicked()));
    connect(ui->BtnComplexCalc,SIGNAL(clicked()),this,SLOT(on_BtnComplexCalc_clicked()));
    connect(ui->BtnVectorCalc,SIGNAL(clicked()),this,SLOT(on_BtnVectorCalc_clicked()));
    connect(ui->BtnMatrixCalc,SIGNAL(clicked()),this,SLOT(on_BtnMatrixCalc_clicked()));
    connect(ui->BtnStatCalc,SIGNAL(clicked()),this,SLOT(on_BtnStatCalc_clicked()));
    connect(ui->BtnCalculusCalc,SIGNAL(clicked()),this,SLOT(on_BtnCalculusCalc_clicked()));
    connect(ui->BtnFuncCalc,SIGNAL(clicked()),this,SLOT(on_BtnFuncCalc_clicked()));
    connect(ui->BtnStorage,SIGNAL(clicked()),this,SLOT(on_BtnStorage_clicked()));
    //calc_button
    connect(ui->calc_1,SIGNAL(clicked()),this,SLOT(CalcAns()));
    connect(ui->calc_2,SIGNAL(clicked()),this,SLOT(CalcAns()));
    connect(ui->calc_3,SIGNAL(clicked()),this,SLOT(CalcAns()));
    connect(ui->calc_4,SIGNAL(clicked()),this,SLOT(CalcAns()));
    connect(ui->calc_6,SIGNAL(clicked()),this,SLOT(CalcAns()));
    connect(ui->calc_7,SIGNAL(clicked()),this,SLOT(CalcAns()));
    //cin_button
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(on_pushButton_clicked()),Qt::UniqueConnection);
    connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(on_pushButton_2_clicked()),Qt::UniqueConnection);
    connect(ui->pushButton_3,SIGNAL(clicked()),this,SLOT(on_pushButton_3_clicked()),Qt::UniqueConnection);
    connect(ui->pushButton_9,SIGNAL(clicked()),this,SLOT(on_pushButton_9_clicked()),Qt::UniqueConnection);
    connect(ui->pushButton_5,SIGNAL(clicked()),this,SLOT(on_pushButton_5_clicked()),Qt::UniqueConnection);
    connect(ui->pushButton_8,SIGNAL(clicked()),this,SLOT(on_pushButton_8_clicked()),Qt::UniqueConnection);
    connect(ui->pushButton_4,SIGNAL(clicked()),this,SLOT(on_pushButton_4_clicked()),Qt::UniqueConnection);
    connect(ui->pushButton_6,SIGNAL(clicked()),this,SLOT(on_pushButton_6_clicked()),Qt::UniqueConnection);
    connect(ui->pushButton_7,SIGNAL(clicked()),this,SLOT(on_pushButton_7_clicked()),Qt::UniqueConnection);
    connect(ui->pushButton_10,SIGNAL(clicked()),this,SLOT(on_pushButton_10_clicked()),Qt::UniqueConnection);
    connect(ui->pushButton_11,SIGNAL(clicked()),this,SLOT(on_pushButton_11_clicked()),Qt::UniqueConnection);
    connect(ui->pushButton_13,SIGNAL(clicked()),this,SLOT(on_pushButton_13_clicked()),Qt::UniqueConnection);
    connect(ui->pushButton_14,SIGNAL(clicked()),this,SLOT(on_pushButton_14_clicked()),Qt::UniqueConnection);
    connect(ui->pushButton_15,SIGNAL(clicked()),this,SLOT(on_pushButton_15_clicked()),Qt::UniqueConnection);
    connect(ui->pushButton_16,SIGNAL(clicked()),this,SLOT(on_pushButton_16_clicked()),Qt::UniqueConnection);
    connect(ui->pushButton_17,SIGNAL(clicked()),this,SLOT(on_pushButton_17_clicked()),Qt::UniqueConnection);
    connect(ui->pushButton_18,SIGNAL(clicked()),this,SLOT(on_pushButton_18_clicked()),Qt::UniqueConnection);
    connect(ui->pushButton_19,SIGNAL(clicked()),this,SLOT(on_pushButton_19_clicked()),Qt::UniqueConnection);
    connect(ui->pushButton_20,SIGNAL(clicked()),this,SLOT(on_pushButton_20_clicked()),Qt::UniqueConnection);
    connect(ui->pushButton_21,SIGNAL(clicked()),this,SLOT(on_pushButton_21_clicked()),Qt::UniqueConnection);
    connect(ui->pushButton_24,SIGNAL(clicked()),this,SLOT(on_pushButton_24_clicked()),Qt::UniqueConnection);
    connect(ui->pushButton_25,SIGNAL(clicked()),this,SLOT(on_pushButton_25_clicked()),Qt::UniqueConnection);
    connect(ui->pushButton_26,SIGNAL(clicked()),this,SLOT(on_pushButton_26_clicked()),Qt::UniqueConnection);
    connect(ui->pushButton_27,SIGNAL(clicked()),this,SLOT(on_pushButton_27_clicked()),Qt::UniqueConnection);
    connect(ui->pushButton_28,SIGNAL(clicked()),this,SLOT(on_pushButton_28_clicked()),Qt::UniqueConnection);
    connect(ui->pushButton_29,SIGNAL(clicked()),this,SLOT(on_pushButton_29_clicked()),Qt::UniqueConnection);
    connect(ui->pushButton_30,SIGNAL(clicked()),this,SLOT(on_pushButton_30_clicked()),Qt::UniqueConnection);
    connect(ui->pushButton_31,SIGNAL(clicked()),this,SLOT(on_pushButton_31_clicked()),Qt::UniqueConnection);
    connect(ui->pushButton_32,SIGNAL(clicked()),this,SLOT(on_pushButton_32_clicked()),Qt::UniqueConnection);
    connect(ui->pushButton_33,SIGNAL(clicked()),this,SLOT(on_pushButton_33_clicked()),Qt::UniqueConnection);
    connect(ui->pushButton_34,SIGNAL(clicked()),this,SLOT(on_pushButton_34_clicked()),Qt::UniqueConnection);
    connect(ui->pushButton_35,SIGNAL(clicked()),this,SLOT(on_pushButton_35_clicked()),Qt::UniqueConnection);
    connect(ui->pushButton_36,SIGNAL(clicked()),this,SLOT(on_pushButton_36_clicked()),Qt::UniqueConnection);
    connect(ui->pushButton_37,SIGNAL(clicked()),this,SLOT(on_pushButton_37_clicked()),Qt::UniqueConnection);
}

void MainWindow::InitGroup()
{
    group = new QButtonGroup(this);
    group->setExclusive(true);
    group->addButton(ui->BtnMainPage,0);
    group->addButton(ui->BtnNormCalc,1);
    group->addButton(ui->BtnComplexCalc,2);
    group->addButton(ui->BtnVectorCalc,3);
    group->addButton(ui->BtnMatrixCalc,4);
    group->addButton(ui->BtnStatCalc,5);
    group->addButton(ui->BtnCalculusCalc,6);
    group->addButton(ui->BtnFuncCalc,7);
    group->addButton(ui->BtnStorage,8);
    ui->BtnMainPage->click();
}




void MainWindow::ChangeStorage()
{
    QString pythonPath="../../Python312/python.exe";
    QString scriptPath="../../python/change_storage.py";
    QProcess process;
    connect(&process, &QProcess::readyReadStandardOutput, [&]() {
        QByteArray output = process.readAllStandardOutput();
        QString outputText = QString::fromLocal8Bit(output);
        //qDebug() << "Standard output:" << outputText;
    });

    // 实时读取标准错误输出
    connect(&process, &QProcess::readyReadStandardError, [&]() {
        QByteArray errorOutput = process.readAllStandardError();
        QString errorOutputText = QString::fromLocal8Bit(errorOutput);
        //qDebug() << "Standard error:" << errorOutputText;
    });
    process.start(pythonPath,QStringList()<<scriptPath);
    if (!process.waitForStarted()) {
        //qDebug() << "Process failed to start.";
        return;
    }
    //qDebug()<<std::to_string(ui->tabWidget_sto->currentIndex()).c_str();
    process.write(std::to_string(ui->tabWidget_sto->currentIndex()).c_str());
    process.write("\n");
    if(ui->tabWidget_sto->currentIndex()==0)
    {
        int row=ui->storage_var->rowCount();

        process.write(std::to_string(row).c_str());
        process.write("\n");
        for(int i=1;i<=row;i++)
        {
            if(ui->storage_var->item(i-1,0)!=nullptr&&ui->storage_var->item(i-1,1)!=nullptr)
            {
                process.write(ui->storage_var->item(i-1,0)->text().toStdString().c_str());
                process.write("\n");
                process.write(ui->storage_var->item(i-1,1)->text().toStdString().c_str());
                process.write("\n");
            }
            else
                process.write("\n\n");
        }
    }
    else if(ui->tabWidget_sto->currentIndex()==1)
    {
        int row=ui->storage_matrix->rowCount();

        process.write(std::to_string(row).c_str());
        process.write("\n");
        for(int i=1;i<=row;i++)
        {
            if(ui->storage_matrix->item(i-1,0)!=nullptr&&ui->storage_matrix->item(i-1,1)!=nullptr)
            {
                process.write(ui->storage_matrix->item(i-1,0)->text().toStdString().c_str());
                process.write("\n");
                process.write(ui->storage_matrix->item(i-1,1)->text().toStdString().c_str());
                process.write("\n");
            }
            else
                process.write("\n\n");
        }
    }
    process.waitForBytesWritten(10000);
    if (!process.waitForFinished()) {
        //qDebug() << "Process failed to finish.";
        return;
    }
}


void MainWindow::TimeOut()
{
    UpdateFormulaEditor();
}

void MainWindow::on_BtnMainPage_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}
void MainWindow::on_BtnNormCalc_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}
void MainWindow::on_BtnComplexCalc_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}
void MainWindow::on_BtnVectorCalc_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}
void MainWindow::on_BtnMatrixCalc_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}
void MainWindow::on_BtnStatCalc_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}
void MainWindow::on_BtnCalculusCalc_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}
void MainWindow::on_BtnFuncCalc_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);
}


void MainWindow::on_BtnStorage_clicked()
{
    ui->stackedWidget->setCurrentIndex(8);
}


void MainWindow::on_BtnAdd1_clicked()
{
    int row_count=ui->P5data1->rowCount();
    ui->P5data1->setRowCount(row_count+1);
}


void MainWindow::on_BtnDelete1_clicked()
{
    int row_count=ui->P5data1->rowCount();
    if(row_count>=2)
    ui->P5data1->setRowCount(row_count-1);
}


void MainWindow::on_calc_5_1_clicked()
{
    int row_count=ui->P5data1->rowCount();
    QList<double> data;
    int n=0;
    for(int i=0;i<row_count;i++)
    {
        if(ui->P5data1->item(i,0)!=nullptr)
        {
            n++;
            data.push_back(ui->P5data1->item(i,0)->text().toDouble());
        }
        else
            data.push_back(0);
    }
    double sum_x=0,sum_x_2=0;
    for(int i=0;i<row_count;i++)
    {
        sum_x+=data[i];
        sum_x_2+=data[i]*data[i];
    }
    double E_x=sum_x/n;
    ui->E_x->setText(std::to_string(E_x).c_str());
    double D_x=sum_x_2/n-E_x*E_x;
    ui->D_x->setText(std::to_string(D_x).c_str());
    ui->Sum_x->setText(std::to_string(sum_x).c_str());
    ui->Sum_x_2->setText(std::to_string(sum_x_2).c_str());
    double min_num=1E99;
    double max_num=-1E99;
    for(int i=0;i<row_count;i++)
    {
        if(ui->P5data1->item(i,0)!=nullptr)
        {
            if(min_num>data[i])
                min_num=data[i];
            if(max_num<data[i])
                max_num=data[i];
        }
    }
    ui->Min_x->setText(std::to_string(min_num).c_str());
    ui->Max_x->setText(std::to_string(max_num).c_str());
}


void MainWindow::on_BtnAdd2_clicked()
{
    int row_count=ui->P5data2->rowCount();
    ui->P5data2->setRowCount(row_count+1);
}


void MainWindow::on_BtnDelete2_clicked()
{
    int row_count=ui->P5data2->rowCount();
    if(row_count>=2)
        ui->P5data2->setRowCount(row_count-1);
}



void MainWindow::on_regression_clicked()
{
    int row_count=ui->P5data2->rowCount();
    QList<double> data2x;
    QList<double> data2y;
    int n_x=0,n_y=0,n=0;
    for(int i=0;i<row_count;i++)
    {
        if(ui->P5data2->item(i,0)!=nullptr)
        {
            n_x++;
            data2x.push_back(ui->P5data2->item(i,0)->text().toDouble());
        }
        else
            data2x.push_back(0);
        if(ui->P5data2->item(i,1)!=nullptr)
        {
            n_y++;
            data2y.push_back(ui->P5data2->item(i,1)->text().toDouble());
        }
        else
            data2y.push_back(0);
    }
    if(n_x==n_y)
        n=n_x;
    else
    {
        ui->Stat_k->setText("error");
        ui->Stat_b->setText("error");
        return;
    }
    double sum_x=0,sum_x_2=0;
    double sum_y=0,sum_xy=0;
    for(int i=0;i<row_count;i++)
    {
        sum_x+=data2x[i];
        sum_x_2+=data2x[i]*data2x[i];
        sum_y+=data2y[i];
        sum_xy+=data2x[i]*data2y[i];
    }
    double E_x=sum_x/n;
    double E_y=sum_y/n;
    double E_x_2=sum_x_2/n;
    double E_xy=sum_xy/n;
    double k=(E_xy-E_x*E_y)/(E_x_2-E_x*E_x);
    double b=E_y-k*E_x;
    ui->Stat_k->setText(std::to_string(k).c_str());
    ui->Stat_b->setText(std::to_string(b).c_str());
}


void MainWindow::on_pushButton_clicked()
{
    ui-> InputLineEdit1->insert("7");
}


void MainWindow::on_pushButton_2_clicked()
{
    ui-> InputLineEdit1->insert("8");
}


void MainWindow::on_pushButton_3_clicked()
{
    ui-> InputLineEdit1->insert("9");
}


void MainWindow::on_pushButton_9_clicked()
{
    ui-> InputLineEdit1->insert("4");
}


void MainWindow::on_pushButton_5_clicked()
{
    ui-> InputLineEdit1->insert("5");
}


void MainWindow::on_pushButton_8_clicked()
{
    ui-> InputLineEdit1->insert("6");
}


void MainWindow::on_pushButton_4_clicked()
{
    ui-> InputLineEdit1->insert("1");
}


void MainWindow::on_pushButton_6_clicked()
{
    ui-> InputLineEdit1->insert("2");
}


void MainWindow::on_pushButton_7_clicked()
{
    ui-> InputLineEdit1->insert("3");
}


void MainWindow::on_pushButton_10_clicked()
{
    ui-> InputLineEdit1->insert("0");
}


void MainWindow::on_pushButton_11_clicked()
{
    ui-> InputLineEdit1->insert(".");
}


void MainWindow::on_pushButton_13_clicked()
{
    ui-> InputLineEdit1->insert("+");
}


void MainWindow::on_pushButton_16_clicked()
{
    ui-> InputLineEdit1->insert("-");
}


void MainWindow::on_pushButton_15_clicked()
{
    ui-> InputLineEdit1->insert("*");
}


void MainWindow::on_pushButton_14_clicked()
{
    ui-> InputLineEdit1->insert("/");
}


void MainWindow::on_pushButton_24_clicked()
{
    ui-> InputLineEdit1->insert("pi");
}


void MainWindow::on_pushButton_25_clicked()
{
    ui-> InputLineEdit1->insert("ln");
}


void MainWindow::on_pushButton_18_clicked()
{
    ui-> InputLineEdit1->insert("sin");
}


void MainWindow::on_pushButton_19_clicked()
{
    ui-> InputLineEdit1->insert("cos");
}


void MainWindow::on_pushButton_26_clicked()
{
    ui-> InputLineEdit1->insert("asin");
}


void MainWindow::on_pushButton_17_clicked()
{
    ui-> InputLineEdit1->insert("**");
}


void MainWindow::on_pushButton_20_clicked()
{
    ui-> InputLineEdit1->insert("(");
}


void MainWindow::on_pushButton_21_clicked()
{
    ui-> InputLineEdit1->insert(")");
}


void MainWindow::on_pushButton_27_clicked()
{
    ui-> InputLineEdit1->insert("acos");
}


void MainWindow::on_pushButton_28_clicked()
{
    ui-> InputLineEdit1->insert("tan");
}


void MainWindow::on_pushButton_29_clicked()
{
    ui-> InputLineEdit1->insert("atan");
}


void MainWindow::on_pushButton_30_clicked()
{
    ui-> InputLineEdit1->insert("sinh");
}


void MainWindow::on_pushButton_31_clicked()
{
    ui-> InputLineEdit1->insert("cosh");
}


void MainWindow::on_pushButton_32_clicked()
{
    ui-> InputLineEdit1->insert("tanh");
}


void MainWindow::on_pushButton_33_clicked()
{
    ui-> InputLineEdit1->insert("asinh");
}


void MainWindow::on_pushButton_34_clicked()
{
    ui-> InputLineEdit1->insert("acosh");
}


void MainWindow::on_pushButton_35_clicked()
{
    ui-> InputLineEdit1->insert("atanh");
}


void MainWindow::on_pushButton_36_clicked()
{
    ui->InputLineEdit1->cursorBackward(false);
    ui->InputLineEdit1->del();
}


void MainWindow::on_pushButton_37_clicked()
{
    ui->InputLineEdit1->setText("");
    ui->OutputWebWidget1->setHtml("");
}

/*void MainWindow::on_pushButton_pressed()
{
    //ui-> InputLineEdit1->insert("7");
}*/
void MainWindow::on_pushButton_49_clicked()
{
    ui->InputLineEdit2->insert("7");
}



void MainWindow::on_pushButton_56_clicked()
{
    ui->InputLineEdit2->insert("8");
}



void MainWindow::on_pushButton_38_clicked()
{
    ui->InputLineEdit2->insert("9");
}




void MainWindow::on_pushButton_47_clicked()
{
    ui->InputLineEdit2->insert("4");
}


void MainWindow::on_pushButton_52_clicked()
{
    ui->InputLineEdit2->insert("5");
}


void MainWindow::on_pushButton_44_clicked()
{
    ui->InputLineEdit2->insert("6");
}


void MainWindow::on_pushButton_58_clicked()
{
    ui->InputLineEdit2->insert("1");
}


void MainWindow::on_pushButton_41_clicked()
{
    ui->InputLineEdit2->insert("2");
}


void MainWindow::on_pushButton_46_clicked()
{
    ui->InputLineEdit2->insert("3");
}


void MainWindow::on_pushButton_53_clicked()
{
    ui->InputLineEdit2->insert("0");
}


void MainWindow::on_pushButton_48_clicked()
{
    ui->InputLineEdit2->insert(".");
}


void MainWindow::on_pushButton_54_clicked()
{
    ui->InputLineEdit2->insert("**");
}


void MainWindow::on_pushButton_40_clicked()
{
    ui->InputLineEdit2->insert("+");
}


void MainWindow::on_pushButton_55_clicked()
{
    ui->InputLineEdit2->insert("-");
}


void MainWindow::on_pushButton_50_clicked()
{
    ui->InputLineEdit2->insert("pi");
}


void MainWindow::on_pushButton_45_clicked()
{
    ui->InputLineEdit2->insert("*");
}


void MainWindow::on_pushButton_57_clicked()
{
    ui->InputLineEdit2->insert("/");
}


void MainWindow::on_pushButton_59_clicked()
{
    ui->InputLineEdit2->insert("ln");
}


void MainWindow::on_pushButton_39_clicked()
{
    ui->InputLineEdit2->insert("sin");
}


void MainWindow::on_pushButton_43_clicked()
{
    ui->InputLineEdit2->insert("cos");
}


void MainWindow::on_pushButton_60_clicked()
{
    ui->InputLineEdit2->insert("asin");
}


void MainWindow::on_pushButton_42_clicked()
{
    ui->InputLineEdit2->insert("(");
}


void MainWindow::on_pushButton_51_clicked()
{
    ui->InputLineEdit2->insert(")");
}


void MainWindow::on_pushButton_61_clicked()
{
    ui->InputLineEdit2->insert("acos");
}


void MainWindow::on_pushButton_62_clicked()
{
    ui->InputLineEdit2->insert("tan");
}


void MainWindow::on_pushButton_63_clicked()
{
    ui->InputLineEdit2->insert("atan");
}


void MainWindow::on_pushButton_64_clicked()
{
    ui->InputLineEdit2->insert("sinh");
}


void MainWindow::on_pushButton_65_clicked()
{
    ui->InputLineEdit2->insert("cosh");
}


void MainWindow::on_pushButton_66_clicked()
{
    ui->InputLineEdit2->insert("tanh");
}


void MainWindow::on_pushButton_67_clicked()
{
    ui->InputLineEdit2->insert("asinh");
}


void MainWindow::on_pushButton_68_clicked()
{
    ui->InputLineEdit2->insert("acosh");
}


void MainWindow::on_pushButton_69_clicked()
{
    ui->InputLineEdit2->insert("atanh");
}


void MainWindow::on_pushButton_70_clicked()
{
    ui->InputLineEdit2->setText("");
    ui->InputWebWidget2->setHtml("");
    ui->OutputWebWidget2->setHtml("");
}


void MainWindow::on_pushButton_71_clicked()
{
    ui->InputLineEdit2->cursorBackward(false);
    ui->InputLineEdit2->del();
}


void MainWindow::on_pushButton_72_clicked()
{
    ui->InputLineEdit2->insert("I");
}

