#include "database_source.hpp"

#include "song_reference.hpp"
#include "song.hpp"

#include <cassert>

#include <QSqlQuery>

namespace Cantionale 
{
    DatabaseSource::DatabaseSource(QString name, QString connection) : name(name), connection(connection), db(QSqlDatabase::database(connection))
    {
        refresh();
    }
    
    void DatabaseSource::refresh()
    {
        refs.clear();
        QSqlQuery query(db);
        query.exec("SELECT id FROM songs ORDER BY title ASC, id ASC");
        while(query.next())
        {
            refs.push_back(SongReference(this, query.value(0).toInt()));
        }
    }


    DatabaseSource::~DatabaseSource()
    {
    }
    
    int DatabaseSource::songCount() const
    {
        return refs.size();
    }
    
    SongReference DatabaseSource::getSong(int index)
    {
        return refs[index];
    }

        
    QString DatabaseSource::getSongTitle(int id)
    {
        QSqlQuery query(db);
        query.prepare("SELECT title FROM songs WHERE id=:id");
        query.bindValue(":id", id);
        query.exec();
        assert(query.next());
        return query.value(0).toString();
    }

    Song DatabaseSource::getSongById(int id)
    {
        Song song;
        {
            QSqlQuery query(db);
            query.prepare("SELECT title, author, sounds, note, lyrics, script, url "
                        "FROM songs WHERE id=:id");
            query.bindValue(":id", id);
            query.exec();
            if(!query.next()) return Song();
            song.title = query.value(0).toString();
            song.author = query.value(1).isNull()?"":query.value(1).toString();
            song.sounds = query.value(2).isNull()?"":query.value(2).toString();
            song.notes = query.value(3).isNull()?"":query.value(3).toString();
            song.lyrics = query.value(4).isNull()?"":query.value(4).toString();
            song.script = query.value(5).isNull()?"":query.value(5).toString();
            song.url = query.value(6).isNull()?"":query.value(6).toString();
        }
        {
            QSqlQuery query(db);
            query.prepare("SELECT name FROM tags "
                          "JOIN tags_to_songs ON tags_to_songs.tag_id=tags.id "
                          "WHERE tags_to_songs.song_id=:id");
            query.bindValue(":id", id);
            query.exec();
            while(query.next())
            {
                song.tags.push_back(query.value(0).toString());
            }
        }
        return song;
    }
        
    SongReference DatabaseSource::insertSong(Song)
    {
        return SongReference(nullptr, 0);
    }

    SongReference DatabaseSource::updateSong(SongReference, Song)
    {
        return SongReference(nullptr, 0);
    }

    void DatabaseSource::removeSong(SongReference)
    {

    }

}