#include "CalcAns.h"
extern AnsEditorBase *editor_ans;
bool error=0;
void AnsEditorBase::executePythonScript(const QString& formula) {
    QString pythonPath = "../../Python312/python.exe";
    QString scriptPath = "../../python/mathml_to_html.py";
    QProcess process;
    QString errorOutputText="";
    connect(&process, &QProcess::readyReadStandardOutput, [&]() {
        QByteArray output = process.readAllStandardOutput();
        QString outputText = QString::fromLocal8Bit(output);
        //qDebug() << "Standard output:" << outputText;
    });

    connect(&process, &QProcess::readyReadStandardError, [&]() {
        QByteArray errorOutput = process.readAllStandardError();
        errorOutputText = QString::fromLocal8Bit(errorOutput);
        //qDebug() << "Standard error:" << errorOutputText;
    });

    process.start(pythonPath, QStringList() << scriptPath);
    if (!process.waitForStarted()) {
        //qDebug() << "Process failed to start.";
        return;
    }

    process.write(std::to_string(pageIndex).c_str());
    process.write("\n");
    process.write(formula.toStdString().c_str());
    process.write("\n");
    process.write("eval\n");
    if(pageIndex==6)
    {
        if(ui->radioButton6_mode1->isChecked())
        {
            process.write("integral_1\n");
            QString low=ui->lineEdit_low->text();
            QString high=ui->lineEdit_high->text();
            process.write(low.toStdString().c_str());
            process.write("\n");
            process.write(high.toStdString().c_str());
            process.write("\n");
        }
        if(ui->radioButton6_mode2->isChecked())
            process.write("integral_2\n");
        if(ui->radioButton6_mode3->isChecked())
        {
            process.write("diff_1\n");
            QString value=ui->lineEdit_value->text();
            process.write(value.toStdString().c_str());
            process.write("\n");
        }

        if(ui->radioButton6_mode4->isChecked())
            process.write("diff_2\n");
    }
    if (pageIndex==7){
        if(ui->radioButton7_mode2->isChecked())
        {
            process.write("function\n");
            QString value=ui->lineEdit_value_2->text();
            process.write(value.toStdString().c_str());
            process.write("\n");
        }
        if(ui->radioButton7_mode1->isChecked())
        {
            process.write("equation\n");
        }
    }
    process.waitForBytesWritten(10000);
    if (!process.waitForFinished()) {
        //qDebug() << "Process failed to finish.";
        return;
    }
    if(errorOutputText.isEmpty())
        error=0;
    else
        error=1;
}

void AnsEditorBase::loadHtmlContent() {
    QUrl exePath = QUrl(QCoreApplication::applicationFilePath());
    if(error==0)
    {
        switch (pageIndex) {
        case 1:
            relativeUrl = QUrl("../../../html/output_formula1.html");
            break;
        case 2:
            relativeUrl = QUrl("../../../html/output_formula2.html");
            break;
        case 3:
            relativeUrl = QUrl("../../../html/output_formula3.html");
            break;
        case 4:
            relativeUrl = QUrl("../../../html/output_formula4.html");
            break;
        case 6:
            relativeUrl = QUrl("../../../html/output_formula6.html");
            break;
        case 7:
            relativeUrl = QUrl("../../../html/output_formula7.html");
            break;
        }
    }
    else
        relativeUrl = QUrl("../../../html/error.html");
    outputWebWidget->load(exePath.resolved(relativeUrl));

}
void AnsEditorBase::updateAnsEditor()
{
    QString formula = inputLineEdit->text();
    //qDebug() << formula;
    executePythonScript(formula);
    loadHtmlContent();
}




void MainWindow::CalcAns() {
    int page_index = ui->stackedWidget->currentIndex();

    switch (page_index) {
    case 1:
        editor_ans->inputLineEdit=ui->InputLineEdit1;
        editor_ans->outputWebWidget= ui->OutputWebWidget1;
        editor_ans->pageIndex=1;
        break;
    case 2:
        editor_ans->inputLineEdit=ui->InputLineEdit2;
        editor_ans->outputWebWidget= ui->OutputWebWidget2;
        editor_ans->pageIndex=2;
        break;
    case 3:
        editor_ans->inputLineEdit=ui->InputLineEdit3;
        editor_ans->outputWebWidget= ui->OutputWebWidget3;
        editor_ans->pageIndex=3;
        break;
    case 4:
        editor_ans->inputLineEdit=ui->InputLineEdit4;
        editor_ans->outputWebWidget= ui->OutputWebWidget4;
        editor_ans->pageIndex=4;
        break;

    case 6:
        editor_ans->inputLineEdit=ui->InputLineEdit6;
        editor_ans->outputWebWidget= ui->OutputWebWidget6;
        editor_ans->pageIndex=6;
        break;
    case 7:
        editor_ans->inputLineEdit=ui->InputLineEdit7;
        editor_ans->outputWebWidget= ui->OutputWebWidget7;
        editor_ans->pageIndex=7;
        break;
    }

    if (editor_ans) {
        editor_ans->updateAnsEditor();

    }
}
