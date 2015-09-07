#include "song_widget.hpp"

namespace Cantionale
{
    SongWidget::SongWidget(Song song, QWidget* parent): QWidget(parent)
    {
        btn = new QPushButton(song.title, this);
    }

    Song SongWidget::getSong()
    {
        Song song;
        return song;
    }

    bool SongWidget::requestClose()
    {
        return true;
    }

}