#include "HtmlEditor.h"

HtmlEditor::HtmlEditor(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    QObject::connect(ui.codeEdit, &QPlainTextEdit::textChanged, [edit = ui.codeEdit, view = ui.codeView]() {
        view->setHtml(edit->toPlainText());
        });
}
