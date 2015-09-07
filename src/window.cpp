#include "window.hpp"

#include "sources_list_widget.hpp"
#include "song_widget.hpp"

#include <QPushButton>
#include <QTabWidget>
#include <QLineEdit>
#include <QMenuBar>
#include <QCompleter>
#include <QStatusBar>

namespace Cantionale
{
    Window::Window(Model& model) : model(model)
    {
        this->setWindowTitle("Cantionale");
        
        QMenuBar *menubar = new QMenuBar(this);
        menubar->addMenu(tr("File"));
        menubar->addMenu(tr("Edit"));
        QMenu *view_menu = menubar->addMenu(tr("View"));
        menubar->addMenu(tr("Help"));
        this->setMenuBar(menubar);
        
        documents = new QTabWidget(this);
        documents->setDocumentMode(true);
        documents->setMovable(true);
        documents->setTabsClosable(true);
        this->setCentralWidget(documents);
        
        QStatusBar *status = new QStatusBar(this);
        this->setStatusBar(status);
        
        sources = new QDockWidget(tr("Sources"), this);
        sources->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
        sources->setWidget(new SourcesListWidget(model, this));
        view_menu->addAction(sources->toggleViewAction());
        
        this->addDockWidget(Qt::LeftDockWidgetArea, sources);
        
        connect(documents, SIGNAL(tabCloseRequested(int)),
                this, SLOT(onDocCloseRequest(int)));
    }
    
    void Window::onDocCloseRequest(int index)
    {
        QWidget *wdg = this->documents->widget(index);
        if(SongWidget *sw = dynamic_cast<SongWidget *>(wdg))
        {
            if(sw->requestClose())
            {
                this->documents->removeTab(index);
                delete sw;
            }
            return;
        }
    }

}