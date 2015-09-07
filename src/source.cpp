#include "source.hpp"
#include "song_reference.hpp"

#include <cassert>

namespace Cantionale
{
    Source::Source(): QObject()
    {
        song_model = new SongSourceModel(this);
        layout_model = new LayoutSourceModel(this);
    }
    
    Source::~Source()
    {
        delete song_model;
        delete layout_model;
    }
    

    
    QAbstractItemModel * Source::getSongSourceModel() const
    {
        return song_model;
    }

    QAbstractItemModel * Source::getLayoutSourceModel() const
    {
        return layout_model;
    }
    
    Source::SongSourceModel::SongSourceModel(Source* source): QAbstractTableModel(source), src(source)
    {
    }

    Source::LayoutSourceModel::LayoutSourceModel(Source* source): QAbstractTableModel(source), src(source)
    {
    }

    int Source::LayoutSourceModel::columnCount(const QModelIndex& parent) const
    {
        return 1;
    }

    QVariant Source::LayoutSourceModel::data(const QModelIndex& index, int role) const
    {
        if(role == Qt::DisplayRole)
            return QVariant();
        return QVariant();
    }

    int Source::LayoutSourceModel::rowCount(const QModelIndex& parent) const
    {
        return 0;
    }

    int Source::SongSourceModel::columnCount(const QModelIndex& parent) const
    {
        return 1;
    }

    QVariant Source::SongSourceModel::data(const QModelIndex& index, int role) const
    {
        if(role == Qt::DisplayRole)
        {
            SongReference ref = src->getSong(index.row());
            return ref.getName();
        }
        return QVariant();
    }

    int Source::SongSourceModel::rowCount(const QModelIndex& parent) const
    {
        return src->songCount();
    }

}