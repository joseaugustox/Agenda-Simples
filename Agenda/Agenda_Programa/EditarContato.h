#ifndef EDITARCONTATO_H
#define EDITARCONTATO_H

#include <QDialog>
#include <QtSql>
#include <QMessageBox>

namespace Ui {
class EditarContato;
}

class EditarContato : public QDialog
{
    Q_OBJECT

public:
    explicit EditarContato(QWidget *parent = nullptr, int id_contato=0);
    ~EditarContato();

private slots:
    void on_pushButton_gravar_informacoes_clicked();

    void on_pushButton_voltar_clicked();

private:
    Ui::EditarContato *ui;
};

#endif // EDITARCONTATO_H
