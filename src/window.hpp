#pragma once

#include "model.hpp"

#include <QMainWindow>
#include <QDockWidget>
#include <QTabWidget>

namespace Cantionale
{
    class Window : public QMainWindow
    {
        Q_OBJECT
        
    public:
        Window(Model &model);
        
    public:
        Model &model;
        QDockWidget *sources;
        QTabWidget *documents;
        
    private slots:
        void onDocCloseRequest(int index);
    };
}