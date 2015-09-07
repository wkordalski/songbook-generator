#include "model.hpp"

#include <cassert>

#include "database_source.hpp"
#include <QSqlDatabase>
#include <QSqlError>
#include <QMessageBox>

namespace Cantionale
{
    Model::Model(QObject* parent): QAbstractTableModel(parent)
    {
        QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL", "db_conn");
        db.setHostName("localhost");
        db.setPort(3306);
        db.setDatabaseName("songbook");
        db.setUserName("zifre");
        db.setPassword("mysqlpassword");
        if(!db.open())
        {
            QMessageBox *mbox = new QMessageBox("Connection error", db.lastError().text(), QMessageBox::Critical, QMessageBox::Ok, QMessageBox::NoButton, QMessageBox::NoButton);
            mbox->show();
        }
        DatabaseSource *dbs = new DatabaseSource("Local database", "db_conn");
        sources.push_back(dbs);
    }
    
    Model::~Model()
    {
        delete sources[0];
    }

    
    int Model::rowCount(const QModelIndex& parent) const
    {
        if(parent.isValid())
        {
            return 0;
        }
        else
        {
            return sources.size();
        }
    }
    
    int Model::columnCount(const QModelIndex& parent) const
    {
        return 1;
    }

    QVariant Model::data(const QModelIndex& index, int role) const
    {
        if(role == Qt::DisplayRole) return QVariant(sources[index.row()]->getName());
        return QVariant();
    }



    std::vector< Source* > Model::getSources() const
    {
        return sources;
    }
    
    Source* Model::getSource(int index) const
    {
        return sources[index];
    }


}