#include<doc.h>

class Composition: Glyph {
};

class Compositor: Composition {
    void SetComposition(Composition* );
    virtual void Compose();
};