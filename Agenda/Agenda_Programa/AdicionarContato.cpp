#include "AdicionarContato.h"
#include "ui_AdicionarContato.h"


AdicionarContato::AdicionarContato(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdicionarContato)
{
    ui->setupUi(this);
}

AdicionarContato::~AdicionarContato()
{
    delete ui;
}

void AdicionarContato::on_pushButton_adicionar_clicked()
{
     QString nome = ui->lineEdit_escreve_nome->text();
     QString telefone = ui->lineEdit_2_escreve_telefone->text();
     QString email = ui->lineEdit_3_escreve_email->text();

     QSqlQuery query;
     query.prepare("insert into tb_contato(nome_contato,telefone_contato,email_contato) values"
                   "('"+nome+"','"+telefone+"','"+email+"')");//inserir contato
     if(nome =="" || (telefone == "" && email ==""))
     {
         QMessageBox::warning(this,"ERRO","Algum campo obrigatorio nao preenchido");
     }
     else
     {
         query.exec();
         QMessageBox::about(this,"Adicionar Contato","Contato adicionado com sucesso");
         ui->lineEdit_escreve_nome->clear();//limpa campo
         ui->lineEdit_2_escreve_telefone->clear();
         ui->lineEdit_3_escreve_email->clear();
         ui->lineEdit_escreve_nome->setFocus();
     }
}

void AdicionarContato::on_pushButton_volta_tela_inicial_clicked()
{
    close();
}
