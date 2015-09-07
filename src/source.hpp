#pragma once


#include <QAbstractItemModel>

namespace Cantionale
{
    class Song;
    class SongReference;
    class Source : public QObject
    {
        Q_OBJECT
    public:
        Source();
        virtual ~Source();
        
        virtual QString getName() = 0;
        
        virtual SongReference insertSong(Song) = 0;
        virtual SongReference updateSong(SongReference, Song) = 0;
        virtual void removeSong(SongReference) = 0;
        virtual int songCount() const = 0;
        virtual SongReference getSong(int index) = 0;
        virtual QString getSongTitle(int id) = 0;
        virtual void refresh() = 0;
        
    protected:
        virtual Song getSongById(int id) = 0;
        friend class SongReference;
        
    public:
        QAbstractItemModel * getSongSourceModel() const;
        QAbstractItemModel * getLayoutSourceModel() const;
        
    private:
        class SongSourceModel : public QAbstractTableModel
        {
            Source *src;
        public:
            SongSourceModel(Source *source);
            int rowCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE ;
            int columnCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;
            QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;
        };
        
        class LayoutSourceModel : public QAbstractTableModel
        {
            Source *src;
        public:
            LayoutSourceModel(Source *source);
            int rowCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE ;
            int columnCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;
            QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;
        };
        
        QAbstractItemModel *song_model;
        QAbstractItemModel *layout_model;
    };
}