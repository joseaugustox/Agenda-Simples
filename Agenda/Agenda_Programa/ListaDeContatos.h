#ifndef LISTADECONTATOS_H
#define LISTADECONTATOS_H

#include <QDialog>
#include <QtSql>
#include <QMessageBox>
#include"EditarContato.h"

namespace Ui {
class ListaDeContatos;
}

class ListaDeContatos : public QDialog
{
    Q_OBJECT

public:
    explicit ListaDeContatos(QWidget *parent = nullptr);
    ~ListaDeContatos();

private slots:
    void on_pushButton_excluir_clicked();

    void on_pushButton_voltar_clicked();

    void on_pushButton_editar_clicked();

private:
    Ui::ListaDeContatos *ui;
};

#endif // LISTADECONTATOS_H
