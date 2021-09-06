#ifndef ADICIONARCONTATO_H
#define ADICIONARCONTATO_H

#include <QDialog>
#include <QMessageBox>
#include <QtSql>

namespace Ui {
class AdicionarContato;
}

class AdicionarContato : public QDialog
{
    Q_OBJECT

public:
    explicit AdicionarContato(QWidget *parent = nullptr);
    ~AdicionarContato();

private slots:
    void on_pushButton_adicionar_clicked();

    void on_pushButton_volta_tela_inicial_clicked();

private:
    Ui::AdicionarContato *ui;
};

#endif // ADICIONARCONTATO_H
