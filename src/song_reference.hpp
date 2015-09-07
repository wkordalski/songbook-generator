#pragma once

#include "source.hpp"
#include "song.hpp"

namespace Cantionale
{
    
    /**
     * A reference to song living on some song source provider.
     */
    class SongReference
    {
        Source *source;
        int song_id;
    public:
        SongReference() : source(nullptr), song_id(0) {}
        SongReference(Source *src, int id) : source(src), song_id(id) {}
        virtual Song getSong() { return source->getSongById(song_id); }
        Source * getSongSource() { return source; }
        virtual QString getName() { return source?source->getSongTitle(song_id):"<invalid resource>"; }
        
        bool isValid() { return source != nullptr; }
    };
}