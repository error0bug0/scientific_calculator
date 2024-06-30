#ifndef UPDATEFORMULAEDITOR_H
#define UPDATEFORMULAEDITOR_H


#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"QButtonGroup"
#include<QProcess>
#include<QWebEngineView>
#include<QTimer>
#include<QTableWidget>


class FormulaEditorBase :public MainWindow{
public:
    QLineEdit *inputLineEdit;
    QWebEngineView *inputWebWidget;
    QUrl relativeUrl;
    int pageIndex;
    Ui::MainWindow *ui;

public:
    FormulaEditorBase(QLineEdit *inputLineEdit, QWebEngineView *inputWebWidget, int pageIndex,Ui::MainWindow *ui)
        : inputLineEdit(inputLineEdit), inputWebWidget(inputWebWidget), pageIndex(pageIndex),ui(ui) {}

    void updateFormulaEditor();

protected:
    void executePythonScript(const QString& formula);
    void loadHtmlContent();

};



#endif // UPDATEFORMULAEDITOR_H
