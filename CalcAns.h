#ifndef CALCANS_H
#define CALCANS_H

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"QButtonGroup"
#include<QProcess>
#include<QWebEngineView>
#include<QTimer>
#include<QTableWidget>


class AnsEditorBase :public MainWindow{
public:
    QLineEdit *inputLineEdit;
    QWebEngineView *outputWebWidget;
    QUrl relativeUrl;
    int pageIndex;
    Ui::MainWindow *ui;

public:
    AnsEditorBase(QLineEdit *inputLineEdit, QWebEngineView *outputWebWidget, int pageIndex,Ui::MainWindow *ui)
        : inputLineEdit(inputLineEdit), outputWebWidget(outputWebWidget), pageIndex(pageIndex),ui(ui) {}

    void updateAnsEditor();

protected:
    void executePythonScript(const QString& formula);
    void loadHtmlContent();

};



#endif // CALCANS_H
