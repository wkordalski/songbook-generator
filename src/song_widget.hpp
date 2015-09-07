#pragma once

#include <song.hpp>

#include <QWidget>
#include <QPushButton>

namespace Cantionale
{
    class SongWidget : public QWidget
    {
        Q_OBJECT
    public:
        // Fills-in the form.
        SongWidget(Song song, QWidget* parent = 0);
        
        // Gets data from widgets.
        Song getSong();
        
        bool requestClose();
        
    protected:
        QPushButton *btn;
    };
}