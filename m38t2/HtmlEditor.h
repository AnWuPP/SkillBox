#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_HtmlEditor.h"
#include <QPlainTextEdit>

class HtmlEditor : public QMainWindow
{
    Q_OBJECT

public:
    HtmlEditor(QWidget *parent = Q_NULLPTR);

private:
    Ui::HtmlEditorClass ui;
};
