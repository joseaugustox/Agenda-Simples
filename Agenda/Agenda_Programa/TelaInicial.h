#ifndef TELAINICIAL_H
#define TELAINICIAL_H

#include <QDialog>
#include<QtSql>
#include"EditarContato.h"
#include "ListaDeContatos.h"

namespace Ui {
class TelaInicial;
}

class TelaInicial : public QDialog
{
    Q_OBJECT

public:
    explicit TelaInicial(QWidget *parent = nullptr);
    ~TelaInicial();

private slots:
    void on_pushButton_add_contato_clicked();

    void on_pushButton_lista_contatos_clicked();

private:
    Ui::TelaInicial *ui;
};

#endif // TELAINICIAL_H
