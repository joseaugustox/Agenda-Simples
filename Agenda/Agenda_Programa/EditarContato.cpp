#include "EditarContato.h"
#include "ui_EditarContato.h"

static int id;

EditarContato::EditarContato(QWidget *parent, int id_contato) :
    QDialog(parent),
    ui(new Ui::EditarContato)
{
    ui->setupUi(this);
    id=id_contato;
    QSqlQuery query;
    query.prepare("select * from tb_contato where id_contato="+QString::number(id_contato));//busca o contato de acordo com o id
    query.exec();
    query.first();
    ui->lineEdit_nome->setText(query.value(1).toString());//preencher com os dados do selecionado
    ui->lineEdit_telefone->setText(query.value(2).toString());//tbm
    ui->lineEdit_email->setText(query.value(3).toString());//tbm
}

EditarContato::~EditarContato()
{
    delete ui;
}

void EditarContato::on_pushButton_gravar_informacoes_clicked()
{
    QString nome = ui->lineEdit_nome->text();
    QString telefone = ui->lineEdit_telefone->text();
    QString email = ui->lineEdit_email->text();

       QSqlQuery query;
       query.prepare("Update tb_contato set nome_contato='"+nome+"', telefone_contato='"+telefone+"', email_contato='"+email+"' where id_contato="+QString::number(id));
       if(query.exec())
       {
           QMessageBox::information(this,"","Dados gravados com sucesso");
       }
       else
       {
           QMessageBox::warning(this,"ERRO","Erro ao atualizar dados");
       }
}

void EditarContato::on_pushButton_voltar_clicked()
{
    this->close();
}
