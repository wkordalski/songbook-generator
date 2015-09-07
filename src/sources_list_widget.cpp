#include "sources_list_widget.hpp"

#include "window.hpp"
#include "song_reference.hpp"
#include "song_widget.hpp"

#include <iostream>

#include <QToolBar>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QAction>
#include <QMenu>


namespace Cantionale {
    SourcesListWidget::SourcesListWidget(Model& model, Window *wnd)
        : QWidget(), model(model), wnd(wnd), src(nullptr)
    {
        QVBoxLayout *layout = new QVBoxLayout();
        this->setLayout(layout);
        
        QToolBar *toolbar = new QToolBar();
        layout->addWidget(toolbar);
        
        sources_list = new QListView();
        
        source_selector = new QComboBox();
        source_selector->setModel(&model);
        source_selector->setCurrentIndex(-1);
        toolbar->addWidget(source_selector);
        source_selector->setView(sources_list);
        
        QAction *taddactions = toolbar->addAction("Add");        
        
        QLineEdit *search = new QLineEdit();
        search->setPlaceholderText("Search");
        layout->addWidget(search);
        
        splitter = new QSplitter();
        splitter->setOrientation(Qt::Vertical);
        layout->addWidget(splitter);
        
        song_list = new QListView(this);
        splitter->addWidget(song_list);
        
        layout_list = new QListView(this);
        splitter->addWidget(layout_list);
        
        
        QItemSelectionModel *selection_model = sources_list->selectionModel();
        connect(source_selector, SIGNAL(currentIndexChanged(int)),
                this, SLOT(activeSourceChanged(int)));
        
        connect(song_list, SIGNAL(doubleClicked(const QModelIndex&)),
                this, SLOT(openSong(const QModelIndex&)));
        
    }
    
    void SourcesListWidget::activeSourceChanged(int /*row*/)
    {
        const QModelIndex index = sources_list->selectionModel()->currentIndex();
        if(model.rowCount() <= 0)
        {
            song_list->setModel(nullptr);
            layout_list->setModel(nullptr);
            src = nullptr;
        }
        else
        {
            src = model.getSource(index.row());
            song_list->setModel(src->getSongSourceModel());
            layout_list->setModel(src->getLayoutSourceModel());
        }
    }

    void SourcesListWidget::openSong(const QModelIndex& index)
    {
        Song s = src->getSong(index.row()).getSong();
        QWidget *wdg = new SongWidget(s);
        wnd->documents->addTab(wdg, s.title);
    }

}