#include "UpdateFormulaEditor.h"
extern FormulaEditorBase *editor;

void FormulaEditorBase::executePythonScript(const QString& formula) {
    QString pythonPath = "../../Python312/python.exe";
    QString scriptPath = "../../python/mathml_to_html.py";
    QProcess process;

    connect(&process, &QProcess::readyReadStandardOutput, [&]() {
        QByteArray output = process.readAllStandardOutput();
        QString outputText = QString::fromLocal8Bit(output);
        //qDebug() << "Standard output:" << outputText;
    });

    connect(&process, &QProcess::readyReadStandardError, [&]() {
        QByteArray errorOutput = process.readAllStandardError();
        QString errorOutputText = QString::fromLocal8Bit(errorOutput);
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
    process.write("show\n");
    process.waitForBytesWritten(10000);
    if (!process.waitForFinished()) {
        //qDebug() << "Process failed to finish.";
        return;
    }
}

void FormulaEditorBase::loadHtmlContent() {
    QUrl exePath = QUrl(QCoreApplication::applicationFilePath());

    switch (pageIndex) {
    case 1:
        relativeUrl = QUrl("../../../html/input_formula1.html");
        break;
    case 2:
        relativeUrl = QUrl("../../../html/input_formula2.html");
        break;
    case 6:
        relativeUrl = QUrl("../../../html/input_formula6.html");
        break;
    case 7:
        relativeUrl = QUrl("../../../html/input_formula7.html");
        break;
    }
    inputWebWidget->load(exePath.resolved(relativeUrl));
}
void FormulaEditorBase::updateFormulaEditor()
{
    QString formula = inputLineEdit->text();
    //qDebug() << formula;
    executePythonScript(formula);
    loadHtmlContent();
}




// 在 MainWindow 类中使用 FormulaEditorBase 类的实例
void MainWindow::UpdateFormulaEditor() {
    int page_index = ui->stackedWidget->currentIndex();
    if (page_index != 1 && page_index != 2 && page_index != 6 && page_index != 7) return;

    // 创建对应页面的编辑器实例

    switch (page_index) {
    case 1:
        editor->inputLineEdit=ui->InputLineEdit1;
        editor->inputWebWidget= ui->InputWebWidget1;
        editor->pageIndex=1;
        break;
    case 2:
        editor->inputLineEdit=ui->InputLineEdit2;
        editor->inputWebWidget= ui->InputWebWidget2;
        editor->pageIndex=2;
        break;
    case 6:
        editor->inputLineEdit=ui->InputLineEdit6;
        editor->inputWebWidget= ui->InputWebWidget6;
        editor->pageIndex=6;
        break;
    case 7:
        editor->inputLineEdit=ui->InputLineEdit7;
        editor->inputWebWidget= ui->InputWebWidget7;
        editor->pageIndex=7;
        break;
    }

    if (editor) {
        editor->updateFormulaEditor();// 注意释放内存

    }
}
