#include "Contato.h"

namespace jaos {
    Contato::Contato()
    {
       nome= "";
       telefone = "";
       email = "";
    }

    void Contato::set_nome(QString nome)
    {
        this->nome = nome;
    }

    void Contato::set_telefone(QString telefone)
    {
        this->telefone = telefone;
    }

    void Contato::set_email(QString email)
    {
        this->email = email;
    }

    QString Contato::get_nome() const
    {
        return nome;
    }

    QString Contato::get_telefone() const
    {
        return telefone;
    }

    QString Contato::get_email() const
    {
        return email;
    }

    void Contato::addContato(QString nome, QString telefone, QString email)
    {
        this->nome = nome;
        this->telefone = telefone;
        this->email = email;
    }

    void Contato::addContato1(QString nome, QString telefone)
    {
        this->nome = nome;
        this->telefone = telefone;
    }

    void Contato::addContato2(QString nome, QString email)
    {
        this->nome = nome;
        this->email = email;
    }

    bool Contato::removeContato(QString nome)
    {

        return false;
    }

    int Contato::buscaContato(QString nome)
    {

        return 0;
    }
}

