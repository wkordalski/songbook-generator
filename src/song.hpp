#pragma once

#include <vector>

#include <QString>

namespace Cantionale
{
    /**
     * An editable object representing a song living on local RAM memory.
     */
    class Song
    {
    public:
        Song() {}
        
        bool isValid() { return title != ""; }
        
        QString title = "", author = "", notes = "", sounds = "", lyrics = "", script = "", url = "";
        std::vector<QString> tags;
    };
}
