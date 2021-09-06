#include "ListaDeContatos.h"
#include "ui_ListaDeContatos.h"

ListaDeContatos::ListaDeContatos(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ListaDeContatos)
{
    ui->setupUi(this);
    QSqlQuery query;
    query.prepare("select * from tb_contato");//abre o banco de dados com todos os arquivos selecionados
    query.exec();
    int cont = 0;
    ui->tableWidget_contatos->setColumnCount(4);//qtd colunas
    while(query.next())//enquanto tiver
    {
        ui->tableWidget_contatos->insertRow(cont);//inserir linha
        ui->tableWidget_contatos->setItem(cont,0,new QTableWidgetItem(query.value(0).toString()));//inserir elemento na coluna ID
        ui->tableWidget_contatos->setItem(cont,1,new QTableWidgetItem(query.value(1).toString()));//nome
        ui->tableWidget_contatos->setItem(cont,2,new QTableWidgetItem(query.value(2).toString()));//telefone
        ui->tableWidget_contatos->setItem(cont,3,new QTableWidgetItem(query.value(3).toString()));//email
        ui->tableWidget_contatos->setRowHeight(cont,20);//altura da linha
        cont++;
    }
    ui->tableWidget_contatos->setColumnWidth(0,30);//formata tamanho de cada coluna
    ui->tableWidget_contatos->setColumnWidth(1,150);
    ui->tableWidget_contatos->setColumnWidth(2,130);
    ui->tableWidget_contatos->setColumnWidth(3,250);

    QStringList cabecalho = {"ID","Nome","Telefone","Email"};//array de QString
    ui->tableWidget_contatos->setHorizontalHeaderLabels(cabecalho);//alterar cabecalho
    ui->tableWidget_contatos->setEditTriggers(QAbstractItemView::NoEditTriggers);//nao ser editavel
    ui->tableWidget_contatos->setSelectionBehavior(QAbstractItemView::SelectRows);//selecionar toda linha
    ui->tableWidget_contatos->verticalHeader()->setVisible(false);//oculta numeros linhas
    ui->tableWidget_contatos->setStyleSheet("QTableView{selection-background-color::blue}");//cor de selecao

}

ListaDeContatos::~ListaDeContatos()
{
    delete ui;
}

void ListaDeContatos::on_pushButton_excluir_clicked()
{
    int linha= ui->tableWidget_contatos->currentRow();//linha atual selecionada
    QString id = ui->tableWidget_contatos->item(linha,0)->text();//pegar o id e guarda
    QSqlQuery query;
    query.prepare("delete from tb_contato where id_contato="+id);
    query.exec();
    ui->tableWidget_contatos->removeRow(linha);//remove na tabela o elemento
    QMessageBox::information(this,"","Contato excluido com sucesso");
}

void ListaDeContatos::on_pushButton_voltar_clicked()
{
    close();
}

void ListaDeContatos::on_pushButton_editar_clicked()
{
    int linha = ui->tableWidget_contatos->currentRow();//linha atual
    int id = ui->tableWidget_contatos->item(linha,0)->text().toInt();
    EditarContato janelaEditaContato(this,id);
    janelaEditaContato.exec();
    QSqlQuery query;
    query.prepare("select * from tb_contato where id_contato="+QString::number(id));
    if(query.exec())
    {
        query.first();
        ui->tableWidget_contatos->setItem(linha,1,new QTableWidgetItem(query.value(1).toString()));//atualizar os campos
        ui->tableWidget_contatos->setItem(linha,2,new QTableWidgetItem(query.value(2).toString()));
        ui->tableWidget_contatos->setItem(linha,3,new QTableWidgetItem(query.value(3).toString()));
    }
    else
    {
        QMessageBox::warning(this,"ERRO","Erro ao selecionar contato");
    }
}
