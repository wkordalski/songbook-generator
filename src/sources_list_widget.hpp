#pragma once

#include "source.hpp"
#include "model.hpp"

#include <map>

#include <QWidget>
#include <QListView>
#include <QComboBox>
#include <QSplitter>

namespace Cantionale
{
    class Window;
    class SourcesListWidget : public QWidget
    {
        Q_OBJECT
    public:
        SourcesListWidget(Model &model, Window *wnd);
    private slots:
        void activeSourceChanged(int /*row*/);
        void openSong(const QModelIndex &);
    private:
        Model &model;
        Source *src;
        Window *wnd;
        QComboBox *source_selector;
        QListView *sources_list;
        QListView *song_list;
        QListView *layout_list;
        QSplitter *splitter;
    };
}