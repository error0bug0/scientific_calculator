#include "mainwindow.h"
#include <QWebEngineView>
#include<QWebEngineSettings>
#include<QProcess>
#include<QDebug>
#include<QFile>
#include"UpdateFormulaEditor.h"
#include"CalcAns.h"
#include<QtWebEngineWidgets>
#include <QApplication>
#include <QLocale>
#include <QTranslator>
#undef slots

#define slots Q_SLOTS
using namespace std;

FormulaEditorBase *editor;
AnsEditorBase *editor_ans;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    /*qDebug()<<"Standard Output:"<<QString::fromLocal8Bit(process.readAllStandardOutput());
    qDebug()<<"Standard error:"<<process.readAllStandardError();*/



    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "scientific_calculator_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }
    MainWindow w;
    editor = new FormulaEditorBase(nullptr,nullptr,0,w.ui);
    editor_ans = new AnsEditorBase(nullptr,nullptr,0,w.ui);
    w.show();//c:/Users/Administrator/Desktop/math.html
    return a.exec();
}
