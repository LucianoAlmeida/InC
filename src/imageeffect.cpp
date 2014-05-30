#include "imageeffect.h"

ImageEffect::ImageEffect() : ImageSprite()
{

}

ImageEffect::~ImageEffect()
{

}

void
ImageEffect::fadein()
{
    Uint32 now = SDL_GetTicks();
    Uint32 last = 0;
    m_alpha = SDL_ALPHA_TRANSPARENT;
    while(m_alpha<SDL_ALPHA_OPAQUE)
    {
        now = SDL_GetTicks();
        if(now > last + 10)
        {
            SDL_SetTextureBlendMode( m_texture, SDL_BLENDMODE_BLEND );
            SDL_SetTextureAlphaMod(m_texture, m_alpha);
            m_alpha += 5;
            if(m_alpha>=SDL_ALPHA_OPAQUE)
                m_alpha = SDL_ALPHA_OPAQUE;
            draw();
            render();
            last = now;
        }
    }
}

void
ImageEffect::fadeout()
{
    Uint32 now = SDL_GetTicks();
    Uint32 last = 0;
    m_alpha = SDL_ALPHA_OPAQUE;
    while(m_alpha>SDL_ALPHA_TRANSPARENT)
    {
        now = SDL_GetTicks();
        if(now > last + 10)
        {
            SDL_SetTextureBlendMode( m_texture, SDL_BLENDMODE_BLEND );
            SDL_SetTextureAlphaMod(m_texture, m_alpha);
            m_alpha -= 5;
            if(m_alpha<=SDL_ALPHA_TRANSPARENT)
                m_alpha = SDL_ALPHA_TRANSPARENT;
            draw();
            render();
            last = now;
        }
    }
}