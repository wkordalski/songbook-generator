#pragma once

#include "source.hpp"

#include <vector>

#include <QAbstractItemModel>

namespace Cantionale
{
    class Model : public QAbstractTableModel
    {
        Q_OBJECT
    public:
        Model(QObject *parent);
        ~Model();
        int rowCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE ;
        int columnCount(const QModelIndex& parent = QModelIndex()) const Q_DECL_OVERRIDE;
        QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;
        std::vector<Source*> getSources() const;
        Source * getSource(int index) const;
        
    private:
        std::vector<Source*> sources;
    };
}