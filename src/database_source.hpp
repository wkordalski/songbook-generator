#pragma once

#include "source.hpp"

#include <string>

#include <QSqlDatabase>

namespace Cantionale
{
    class DatabaseSource : public Source
    {
        QString name;
        QString connection;
        QSqlDatabase db;
    public:
        DatabaseSource(QString name, QString connection);
        
        virtual ~DatabaseSource();
        
        virtual QString getName() {return name;}
        
        virtual SongReference insertSong(Song);
        virtual SongReference updateSong(SongReference, Song);
        virtual void removeSong(SongReference);
        virtual int songCount() const;
        virtual SongReference getSong(int index);
        virtual QString getSongTitle(int id);
        virtual void refresh();
        
    protected:
        virtual Song getSongById(int id);
        
        friend class SongReference;
        
        std::vector<SongReference> refs;
    };
}