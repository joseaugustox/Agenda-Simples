#include "TelaInicial.h"
#include "ui_TelaInicial.h"
#include "AdicionarContato.h"
#include "ListaDeContatos.h"

TelaInicial::TelaInicial(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TelaInicial)
{
    ui->setupUi(this);
    QSqlDatabase bancoDeDados = QSqlDatabase::addDatabase("QSQLITE");//criar o banco de dados
    bancoDeDados.setDatabaseName("C:/Users/josea/Desktop/Agenda/tb_agenda.db");//diretorio do meu computador pessoal
    bancoDeDados.open();
}

TelaInicial::~TelaInicial()
{
    delete ui;
}

void TelaInicial::on_pushButton_add_contato_clicked()//executa janela
{
    AdicionarContato janelaAddContato;
    janelaAddContato.exec();
}

void TelaInicial::on_pushButton_lista_contatos_clicked()//tbm
{
    ListaDeContatos janelaListaDeContatos;
    janelaListaDeContatos.exec();
}
